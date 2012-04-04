/*------------------------------------------------------------------------------

decnumberxx

Copyright (c) 2012, Hypnocode GmbH
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the Hypnocode GmbH.
4. Neither the name of Hypnocode GmbH nor the names of its contributors may
   be used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY HYPNOCODE GMBH ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL HYPNOCODE GMBH BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
------------------------------------------------------------------------------*/

#include <iostream>
#include <cassert>
#include <cmath>

#include "decimal"

using std::decimal::decimal32;
using std::decimal::decimal64;
using std::decimal::decimal128;

#define decimaltype decimal32
#define test_func(__t__) test_all

#include "decnumber_test_gen.x.hpp"

void std_decimal_test_decimal32 (void)
{
  test_all ();

/*
  assert (test_101_0 (a) == 3);
  assert (test_101_0 (1 << 30) == (1 << 30));
  assert (test_101_0 ((1 << 30)-1) == ((1 << 30)-1));

  assert (test_101_2 (a) == 3);
  assert (test_101_2 (1 << 30) == (1 << 30));
  assert (test_101_2 ((1 << 30)-1) == ((1 << 30)-1));

  assert (test_101_1 (a) == 3);
  assert (test_101_1 (1LL << 53) == (1LL << 53));
  assert (test_101_1 ((1LL << 53)-1) == ((1LL << 53)-1));

  assert (test_101_3 (a) == 3);
  assert (test_101_3 (1LL << 53) == (1LL << 53));
  assert (test_101_3 ((1LL << 53)-1) == ((1LL << 53)-1));
*/

  {
	std::stringstream stream;
	stream << std::numeric_limits<decimal32>::lowest();
	assert (stream.str () == "-9.999999E+96");
  }

  {
	std::stringstream stream;
	stream << std::numeric_limits<decimal32>::min();
	assert (stream.str () == "1E-95");
  }

  {
	std::stringstream stream;
	stream << std::numeric_limits<decimal32>::max();
	assert (stream.str () == "9.999999E+96");
  }
}
