/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2012 Andres Goens
    Copyright (C) 2013 Mike Hansen

******************************************************************************/
#include "flint.h"
#include "fq.h"
#include <stdio.h>
#include "profiler.h"

#ifndef REPS
#define REPS 1000000
#endif

int
main()
{
    timeit_t t0;

    slong i;
    fmpz_t p;
    slong d,cpu,wall;
    fq_ctx_t ctx;
    fq_t a,b,c;

    FLINT_TEST_INIT(state);
    
    fmpz_init(p);
    fmpz_set_ui(p, n_randprime(state, 2+ n_randint(state,3),1));
    d = n_randint(state,10)+1;
    fq_ctx_init_conway(ctx,p,d,"a");

    fq_init(a, ctx);
    fq_init(b, ctx);
    fq_init(c, ctx);

    fq_randtest_not_zero(a,state,ctx);
    fq_randtest_not_zero(b,state,ctx);

    flint_printf ( " cpu = %wd ms, wall = %wd ms \n " , cpu , wall );

    FLINT_TEST_CLEANUP(state);

    return 0;

}
