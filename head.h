
/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ****************************************************************************************************************************** */
/**
   @file      slvSysC.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1998 by Mitch Richling.  All rights reserved.
   @brief     Demonstrate LAPACK's sgesv functions.@EOL
   @Keywords  claback cblas sgesv numerical linear algebra
   @Std       C99
              
*/

/* ------------------------------------------------------------------------------------------------------------------------------ */

#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdlib.h>             /* Standard Lib    ISOC  */
#ifdef __APPLE__
#include <Accelerate/Accelerate.h>    /* The MacOS X blas/lapack stuff */
typedef __CLPK_integer       CLPKinteger;
typedef __CLPK_doublereal    CLPKdoublereal;
#else
#include <lapacke.h>    	/* C LAPACK         */
typedef int       CLPKinteger;
typedef double    CLPKdoublereal;
#endif
#include <cblas.h>           /* Basic Linear Algebra I/O */
