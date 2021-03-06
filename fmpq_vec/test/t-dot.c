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

    Copyright (C) 2014 Abhinav Baid

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "flint.h"
#include "fmpq.h"
#include "fmpq_vec.h"
#include "ulong_extras.h"

int
main(void)
{
    int i, result;
    FLINT_TEST_INIT(state);

    flint_printf("dot....");
    fflush(stdout);

    

    /* Check commutative law */
    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        fmpq *a, *b;
        fmpq_t res1, res2;
        slong len = n_randint(state, 100);

        a = _fmpq_vec_init(len);
        b = _fmpq_vec_init(len);
        _fmpq_vec_randtest(a, state, len, 200);
        _fmpq_vec_randtest(b, state, len, 200);
        
        fmpq_init(res1);
        fmpq_init(res2);

        _fmpq_vec_dot(res1, a, b, len);
        _fmpq_vec_dot(res2, b, a, len);

        result = fmpq_equal(res1, res2);
        if (!result)
        {
            flint_printf("FAIL:\n");
            abort();
        }

        _fmpq_vec_clear(a, len);
        _fmpq_vec_clear(b, len);
		fmpq_clear(res1);
		fmpq_clear(res2);
    }

    FLINT_TEST_CLEANUP(state);
    
    flint_printf("PASS\n");
    return 0;
}
