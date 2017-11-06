typedef long double dfloat;

const dfloat cof_0 = 1.000000000190015L;

const int NUMBER_OF_C_FUNCTIONS = 6;

const int CHEBYSHEV_MAX_COEFFICIENTS = 101;

const int TRUNCATE = 20;

#include "c-coefficients-for-cheby.h"

#include "coff-all.h"

#include <complex>

#include <cmath>

#include <iostream>

#include <iomanip>

#include "mpi.h"

#include <fstream>

using
  std::cout;

using
  std::endl;

#include <cassert>

#include <cstdio>

#include <cstdlib>

#include <unistd.h>

using
  std::imag;

using
  std::real;

#ifdef NEED_PI
const dfloat
  M_PIl =
  3.14159265358979323846264338327950288419716939937510582097494459230781640628620896L;

#endif /*NEED_PI */

typedef
  std::complex <
  dfloat >
  dcomplex;

const dfloat
  log_sqrt_2_pi =
logl (sqrtl ((2 * M_PIl)));

dcomplex
log_gamma (dcomplex x)
{
  dcomplex
  tmp (x);
  assert ((0 < real (x)));
  tmp += 5.5;
  tmp -= (log (tmp) * (x + 0.5L));
  dcomplex
  ser (cof_0);
  dcomplex
    y =
    x;
  for (int j = 0; j < 6; ++j)
    {
      y += 1;
      ser += (cof[j] / y);
    }
  ser /= x;
  ser = log (ser);
  ser -= tmp;
  ser += log_sqrt_2_pi;
  return ser;
}

dfloat
chebev (const dfloat * c, int m, dfloat x)
{
  dfloat
    d =
    0;
  dfloat
    dd =
    0;
  dfloat
    sv;
  assert ((m < CHEBYSHEV_MAX_COEFFICIENTS));
  assert ((0 <= x));
  assert ((x <= 1));
  dfloat
    y2 = (2 * ((2 * x) - 1));
  for (int j = (m - 1); (1 <= j); --j)
    {
      sv = d;
      d = (((y2 * d) - dd) + c[j]);
      dd = sv;
    }
  dfloat
    y = (0.5 * y2);
  dfloat
    ret = (((y * d) - dd) + (0.5 * c[0]));
  return ret;
}

dfloat
Remainder (dfloat sqrt_t_over_2pi, dfloat p)
{
/*These \"ought\" to be added backwards...*/
  dfloat
    multiple =
    1;
  dfloat
    sum =
    0;
  for (int i = 0; i < NUMBER_OF_C_FUNCTIONS; ++i)
    {
      dfloat
	c =
	chebev (coeffs[i], TRUNCATE, p);
      c *= multiple;
      sum += c;
      multiple /= sqrt_t_over_2pi;
    }
  sum /= sqrtl (sqrt_t_over_2pi);
/*the sign is computed in neg-1-pow*/
  return sum;
}

/** (-1)^n */
inline int
neg_1_pow (int n)
{
  int
    b = ((2 * (!(n & 1))) - 1);
  return b;
}

const dfloat
  HALF_LOG_PI = (0.5 * logl (M_PIl));

dfloat
theta_approx (dfloat t)
{
  dfloat
    ret = (t * 0.5 * (logl ((t / (2 * M_PIl))) - 1));
  ret -= (M_PIl / 8);
  ret += (1 / (48 * t));
  ret += (7 / (5760 * t * t * t));
  return ret;
}

dfloat
theta (dfloat t)
{
  dcomplex
  arg (0.25, (t / 2));
  dcomplex
    r1 =
    log_gamma (arg);
  dfloat
    ret = (imag (r1) - (t * HALF_LOG_PI));
  return ret;
}

dfloat
  lookup_sqrtl[7000];

dfloat
  lookup_logl[7000];

void
init_tables ()
{
  for (int i = 1; (i < 7000); ++i)
    {
      lookup_logl[i] = logl (i);
      lookup_sqrtl[i] = sqrtl (i);
    }
}

dfloat
  z_max =
  0;

dfloat
Z_riemann (dfloat t)
{
  dfloat
    sqrt_t_over_2pi =
    sqrtl ((t / (2 * M_PIl)));
  int
    N =
    static_cast < int >(sqrt_t_over_2pi);
  dfloat
    p = (sqrt_t_over_2pi - N);
  dfloat
    sumZ =
    0;
  dfloat
    theta_t =
    theta (t);
  assert ((N < 7000));
  for (int n = 1; (n <= N); ++n)
    {
      sumZ += (cosl ((theta_t - (t * lookup_logl[n]))) / lookup_sqrtl[n]);
    }
  sumZ *= 2;
  sumZ += (neg_1_pow ((N - 1)) * Remainder (sqrt_t_over_2pi, p));
  return sumZ;
}

dcomplex
zeta (dfloat t)
{
  dcomplex
  theta_ti (0, theta (t));
  dcomplex
    ee =
    exp (theta_ti);
  dcomplex
    ret = (Z_riemann (t) / ee);
  return ret;
}

typedef long long
  Sample;

const Sample
  CHUNK_SIZE =
  1000000ll;

const Sample
start_sample = 1700*CHUNK_SIZE;//(70ll * 60ll * 44100ll);

/*the end-sample is approximate, depending on the CHUNK-SIZE*/
const Sample
//  end_sample = (start_sample + (1530ll * 1000000ll));
end_sample = 2354*CHUNK_SIZE;

int
  chunk_finished_tag =
  1001;

int
  stop_tag =
  1002;

int
  assignment_tag =
  1003;

int
chunk_number (Sample queue_point)
{
  queue_point -= start_sample;
  assert (((queue_point % CHUNK_SIZE) == 0));
  Sample
    quot = (queue_point / CHUNK_SIZE);
  return quot;
}

Sample
invert_chunk_number (int chunk)
{
  Sample
    s =
    chunk;
  s *= CHUNK_SIZE;
  s += start_sample;
  return s;
}

std::ofstream log_file;

void
send_assignment (Sample queue_point, int dest, int *active_computations)
{
  int chunk = chunk_number (queue_point);
  log_file << "Assigning q=" << queue_point << " as chunk " << chunk << " to "
    << dest << endl;
  MPI_Send ((&chunk), 1, MPI_INT, dest, assignment_tag, MPI_COMM_WORLD);
  ++(*active_computations);
}

void
deal_off_queue (Sample queue_point, int *active_computations)
{
  while ((queue_point < end_sample))
    {
      int finished_signal;
      MPI_Status status;
      MPI_Recv ((&finished_signal), 1, MPI_INT, MPI_ANY_SOURCE,
		chunk_finished_tag, MPI_COMM_WORLD, (&status));
      --(*active_computations);
      send_assignment (queue_point, status.MPI_SOURCE, active_computations);
      queue_point += CHUNK_SIZE;
    }
}

void
wait_for_finish (int active_computations)
{
  log_file << "active-computations " << active_computations << endl;
  while ((0 < active_computations))
    {
      int finished_signal;
      MPI_Status status;
      MPI_Recv ((&finished_signal), 1, MPI_INT, MPI_ANY_SOURCE,
		chunk_finished_tag, MPI_COMM_WORLD, (&status));
      --active_computations;
      log_file << "d active-computations " << active_computations << endl;
    }
}

void
send_finish_signals (int size)
{
  int stop_data = 0;
  for (int i = 1; (i < size); ++i)
    {
      log_file << "stopping " << i << endl;
      MPI_Send ((&stop_data), 1, MPI_INT, i, stop_tag, MPI_COMM_WORLD);
    }
  log_file << "finished-all" << endl;
  std::ofstream finished_all ("finished-all");
  finished_all.close ();
}

Sample
init_the_others (int size, int *active_computations)
{
  Sample queue_point = start_sample;
  for (int i = 1; i < size; ++i)
    {
      send_assignment (queue_point, i, active_computations);
      queue_point += CHUNK_SIZE;
    }
  return queue_point;
}

const int SCALE_VOLUME = 256;
void
overseer_process ()
{
  int size;
  MPI_Comm_size (MPI_COMM_WORLD, (&size));
  if ((size == 1))
    {
      fprintf (stderr, "need at least 2 procs\n");
      exit (1);
    }
  log_file << "start = " << start_sample << " end = " << end_sample <<
    " approx chunk = " << ((end_sample - start_sample) / CHUNK_SIZE) << endl;
  log_file << "SCALE_VOLUME = "<<SCALE_VOLUME << endl;
  log_file << "CHUNK_SIZE = "<< CHUNK_SIZE << endl;
  int active_computations = 0;
  Sample queue_point = init_the_others (size, (&active_computations));
  deal_off_queue (queue_point, (&active_computations));
  wait_for_finish (active_computations);
  send_finish_signals (size);
}

FILE *
open_data_file (const Sample sample)
{
  char fname[1000];
  int chunk = chunk_number (sample);
  sprintf (fname, "zeta-data-%04d", chunk);
  FILE *fo = fopen (fname, "w");
  assert (fo);
  return fo;
}

void
confirmation_finish (const Sample sample)
{
  char fname[1000];
  int chunk = chunk_number (sample);
  sprintf (fname, "confirmation-finish-%04d", chunk);
  std::ofstream out (fname);
  out.close ();
  MPI_Send ((&chunk), 1, MPI_INT, 0, chunk_finished_tag, MPI_COMM_WORLD);
}

void
random_sleep ()
{

}



void
do_computation (const int chunk)
{
  const Sample start_sample = invert_chunk_number (chunk);
  log_file << "start chunk " << chunk << " sample " << start_sample << endl;
  FILE *fo = open_data_file (start_sample);
  for (Sample sample = start_sample; (sample < (start_sample + CHUNK_SIZE));
       ++sample)
    {
      dfloat n = sample;
      n /= 4;
      n += 3;
      dfloat x = (n / logl (n));
      dfloat z = Z_riemann (x);
      dfloat abs_z = fabsl (z);
      if ((z_max < abs_z))
	{
	  log_file << z << " newmax sample= " << sample << " x= " << x <<
	    endl;
	  z_max = abs_z;
	}
      //z=cbrtl(z);
      z *= SCALE_VOLUME;
/*the double cast causes the value to loop around*/
/*this is probably system dependent*/
      short dat =
	static_cast < short >(static_cast < int >(floorl ((z + 0.5))));
      fwrite ((&dat), 2, 1, fo);
    }
  random_sleep ();
  fclose (fo);
  confirmation_finish (start_sample);
}

void
child_process ()
{
  log_file << "child process starts" << endl;
  for (int chunks_processed = 0;; ++chunks_processed)
    {
      MPI_Status status;
      int chunk;
      log_file << "wait assign" << endl;
      MPI_Recv ((&chunk), 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD,
		(&status));
      if ((stop_tag == status.MPI_TAG))
	{
	  break;
	}
/*Intentionally masking the global start-sample*/
      do_computation (chunk);
    }
  log_file << "stop" << endl;
}

void
open_log_file (int rank)
{
  char fname[1000];
  sprintf (fname, "log-cheby-out-%04d.dat", rank);
  log_file.open (fname);
  assert (log_file);
}

int
main (int argc, char **argv)
{
  MPI_Init ((&argc), (&argv));
  init_tables ();
  int rank;
  MPI_Comm_rank (MPI_COMM_WORLD, (&rank));
  open_log_file (rank);
  srand48 (rank);
  if ((0 == rank))
    {
      overseer_process ();
    }
  else
    {
      child_process ();
    }
  MPI_Finalize ();
}

int
main_single_processor ()
{
  init_tables ();
/*Max found 41*/
  const Sample sample_start = 1000000;
  for (Sample sample = sample_start; (sample < (sample_start + (20 * 44100)));
       ++sample)
    {
      dfloat n = sample;
      n /= 4;
      n += 3;
      dfloat x = (n / logl (n));
      dfloat z = Z_riemann (x);
      z *= 512;
      dfloat abs_z = fabsl (z);
      if ((32700 < abs_z))
	{
	  FILE *fo = fopen ("error-happened", "a");
	  fprintf (fo, "error happened %lld %20Lf %20Lf\n", sample, x, z);
	  fprintf (stderr, "error happened %lld %20Lf %20Lf\n", sample, x, z);
	  fclose (fo);
	  exit (1);
	}
/*the double cast causes the value to loop around*/
/*this is probably system dependent*/
      short dat =
	static_cast < short >(static_cast < int >(floorl ((z + 0.5))));
      fwrite ((&dat), 2, 1, stdout);
    }
  return 0;
}
