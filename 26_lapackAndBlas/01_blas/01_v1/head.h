/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ****************************************************************************************************************************** */
/**
   @file      blas1C.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1997 by Mitch Richling.  All rights reserved.
   @breif     Demonstrate Level 1 BLAS.@EOL
   @Keywords  blas cblas C FORTRAN numerical linear algebra vector matrix
   @Std       C89

   This is a simple program intended to illustrate how to make use of several level 1 blas functions found in the cblas (ATLAS).
   Functions illustrated:

      - dswap           
      - dcopy
      - daxpy
      - ddotu
      - ddot
      - dnrm2
      - dasum     
      - dscal
      - ddotc
      - idmax
              
*/

/* ------------------------------------------------------------------------------------------------------------------------------ */

#include <stdio.h>              /* I/O lib         ISOC     */
#include <stdlib.h>             /* Standard Lib    ISOC     */
#include <cblas.h>              /* Basic Linear Algebra I/O */

