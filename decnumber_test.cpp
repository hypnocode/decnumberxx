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

// ----------------------------------------------------------------
// copy ctor and assignment
decimal32 test_00_0 (const decimal32& a)
{
  return a;
}

decimal64 test_00_1 (const decimal64& a)
{
  return a;
}

decimal128 test_00_2 (const decimal128& a)
{
  return a;
}

decimal32 test_00_3 (const decimal32& a)
{
  decimal32 b = 0;
  b = a;
  return b;
}

decimal64 test_00_4 (const decimal64& a)
{
  decimal64 b = 0;
  b = a;
  return b;
}

decimal128 test_00_5 (const decimal128& a)
{
  decimal128 b = 0;
  b = a;
  return b;
}

// ----------------------------------------------------------------
// implicit promotions to wider type
decimal64 test_01_0 (const decimal32& a)
{
  return a;
}

decimal128 test_01_1 (const decimal32& a)
{
  return a;
}

decimal128 test_01_2 (const decimal64& a)
{
  return a;
}

decimal64 test_01_3 (const decimal32& a)
{
  decimal64 b = 0;
  b = a;
  return b;
}

decimal128 test_01_4 (const decimal64& a)
{
  decimal128 b = 0;
  b = a;
  return b;
}

// ----------------------------------------------------------------
// explicit demotion to narrower type
decimal32 test_02_0 (const decimal64& a)
{
  return static_cast<decimal32> (a);
}

decimal32 test_02_1 (const decimal128& a)
{
  return static_cast<decimal32> (a);
}

decimal64 test_02_2 (const decimal128& a)
{
  return static_cast<decimal64> (a);
}

decimal32 test_02_3 (const decimal64& a)
{
  decimal32 b = 0;
  b = static_cast<decimal32> (a);
  return b;
}

decimal32 test_02_4 (const decimal128& a)
{
  decimal32 b = 0;
  b = static_cast<decimal32> (a);
  return b;
}

decimal64 test_02_5 (const decimal128& a)
{
  decimal64 b = 0;
  b = static_cast<decimal64> (a);
  return b;
}

// ----------------------------------------------------------------
// implicit and explicit construction from integral types
//  int8_t,  int16_t,  int32_t,  int64_t -> float is implicit
// uint8_t, uint16_t, uint32_t, uint64_t -> float is implicit

decimal32 test_03_0 (int8_t a)
{
  return a;
}
decimal32 test_03_0 (int16_t a)
{
  return a;
}
decimal32 test_03_0 (int32_t a)
{
  return a;
}
decimal32 test_03_0 (int64_t a)
{
  return a;
}

decimal64 test_03_1 (int8_t a)
{
  return a;
}
decimal64 test_03_1 (int16_t a)
{
  return a;
}
decimal64 test_03_1 (int32_t a)
{
  return a;
}
decimal64 test_03_1 (int64_t a)
{
  return a;
}

decimal128 test_03_2 (int8_t a)
{
  return a;
}
decimal128 test_03_2 (int16_t a)
{
  return a;
}
decimal128 test_03_2 (int32_t a)
{
  return a;
}
decimal128 test_03_2 (int64_t a)
{
  return a;
}


decimal32 test_03_3 (int8_t a)
{
  return decimal32 (a);
}
decimal32 test_03_3 (int16_t a)
{
  return decimal32 (a);
}
decimal32 test_03_3 (int32_t a)
{
  return decimal32 (a);
}
decimal32 test_03_3 (int64_t a)
{
  return decimal32 (a);
}

decimal64 test_03_4 (int8_t a)
{
  return decimal64 (a);
}
decimal64 test_03_4 (int16_t a)
{
  return decimal64 (a);
}
decimal64 test_03_4 (int32_t a)
{
  return decimal64 (a);
}
decimal64 test_03_4 (int64_t a)
{
  return decimal64 (a);
}

decimal128 test_03_5 (int8_t a)
{
  return decimal128 (a);
}
decimal128 test_03_5 (int16_t a)
{
  return decimal128 (a);
}
decimal128 test_03_5 (int32_t a)
{
  return decimal128 (a);
}
decimal128 test_03_5 (int64_t a)
{
  return decimal128 (a);
}


// ----------------------------------------------------------------
// explicit construction from floating point types
decimal32 test_04_0 (float a)
{
  return static_cast<decimal32> (a);
}

decimal32 test_04_1 (double a)
{
  return static_cast<decimal32> (a);
}

decimal32 test_04_2 (long double a)
{
  return static_cast<decimal32> (a);
}

decimal64 test_04_3 (float a)
{
  return static_cast<decimal64> (a);
}

decimal64 test_04_4 (double a)
{
  return static_cast<decimal64> (a);
}

decimal64 test_04_5 (long double a)
{
  return static_cast<decimal64> (a);
}

decimal128 test_04_6 (float a)
{
  return static_cast<decimal128> (a);
}

decimal128 test_04_7 (double a)
{
  return static_cast<decimal128> (a);
}

decimal128 test_04_8 (long double a)
{
  return static_cast<decimal128> (a);
}

// ----------------------------------------------------------------
// implicit conversion to integral types
int8_t test_05_0 (const decimal32& a)
{
  return a;
}
int16_t test_05_1 (const decimal32& a)
{
  return a;
}
int32_t test_05_2 (const decimal32& a)
{
  return a;
}
int64_t test_05_3 (const decimal32& a)
{
  return a;
}

uint8_t test_05_4 (const decimal32& a)
{
  return a;
}
uint16_t test_05_5 (const decimal32& a)
{
  return a;
}
uint32_t test_05_6 (const decimal32& a)
{
  return a;
}
uint64_t test_05_7 (const decimal32& a)
{
  return a;
}

// ----------------------------------------------------------------
// equal / unequal comparison of decimal with decimal
bool test_06_0 (const decimal32& a, const decimal32& b)
{
  return a == b;
}
bool test_06_1 (const decimal32& a, const decimal64& b)
{
  return a == b;
}
bool test_06_2 (const decimal32& a, const decimal128& b)
{
  return a == b;
}
bool test_06_3 (const decimal64& a, const decimal32& b)
{
  return a == b;
}
bool test_06_4 (const decimal128& a, const decimal32& b)
{
  return a == b;
}

bool test_06_5 (const decimal32& a, const decimal32& b)
{
  return a != b;
}
bool test_06_6 (const decimal32& a, const decimal64& b)
{
  return a != b;
}
bool test_06_7 (const decimal32& a, const decimal128& b)
{
  return a != b;
}
bool test_06_8 (const decimal64& a, const decimal32& b)
{
  return a != b;
}
bool test_06_9 (const decimal128& a, const decimal32& b)
{
  return a != b;
}


// ----------------------------------------------------------------
// equal / unequal comparison of decimal and integral type
bool test_07_0 (const decimal32& a, int8_t b)
{
  return a == b;
}
bool test_07_0 (const decimal32& a, int16_t b)
{
  return a == b;
}
bool test_07_0 (const decimal32& a, int32_t b)
{
  return a == b;
}
bool test_07_0 (const decimal32& a, int64_t b)
{
  return a == b;
}
bool test_07_0 (const decimal32& a, uint8_t b)
{
  return a == b;
}
bool test_07_0 (const decimal32& a, uint16_t b)
{
  return a == b;
}
bool test_07_0 (const decimal32& a, uint32_t b)
{
  return a == b;
}
bool test_07_0 (const decimal32& a, uint64_t b)
{
  return a == b;
}
bool test_07_0 (const decimal32& a)
{
  return a == 0;
}
bool test_07_0 (const decimal64& a)
{
  return a == 0;
}
bool test_07_0 (const decimal128& a)
{
  return a == 0;
}


bool test_07_1 (const decimal32& a, int8_t b)
{
  return a != b;
}
bool test_07_1 (const decimal32& a, int16_t b)
{
  return a != b;
}
bool test_07_1 (const decimal32& a, int32_t b)
{
  return a != b;
}
bool test_07_1 (const decimal32& a, int64_t b)
{
  return a != b;
}
bool test_07_1 (const decimal32& a, uint8_t b)
{
  return a != b;
}
bool test_07_1 (const decimal32& a, uint16_t b)
{
  return a != b;
}
bool test_07_1 (const decimal32& a, uint32_t b)
{
  return a != b;
}
bool test_07_1 (const decimal32& a, uint64_t b)
{
  return a != b;
}
bool test_07_1 (const decimal32& a)
{
  return a != 0;
}
bool test_07_1 (const decimal64& a)
{
  return a != 0;
}
bool test_07_1 (const decimal128& a)
{
  return a != 0;
}

bool test_07_2 (const decimal32& a)
{
  return 0 != a;
}
bool test_07_2 (const decimal64& a)
{
  return 0 != a;
}
bool test_07_2 (const decimal128& a)
{
  return 0 != a;
}

// ----------------------------------------------------------------
// less/lessequal comparisons of same decimal types
bool test_08_0 (const decimal32& a, const decimal32& b)
{
  return a < b;
}
bool test_08_0 (const decimal64& a, const decimal64& b)
{
  return a < b;
}
bool test_08_0 (const decimal128& a, const decimal128& b)
{
  return a < b;
}

bool test_08_1 (const decimal32& a, const decimal32& b)
{
  return a <= b;
}
bool test_08_1 (const decimal64& a, const decimal64& b)
{
  return a <= b;
}
bool test_08_1 (const decimal128& a, const decimal128& b)
{
  return a <= b;
}

// ----------------------------------------------------------------
// less/lessequal comparisons of different decimal types
bool test_09_1 (const decimal32& a, const decimal64& b)
{
  return a < b;
}
bool test_09_1 (const decimal32& a, const decimal128& b)
{
  return a < b;
}
bool test_09_2 (const decimal64& a, const decimal32& b)
{
  return a < b;
}
bool test_09_3 (const decimal64& a, const decimal128& b)
{
  return a < b;
}
bool test_09_4 (const decimal128& a, const decimal32& b)
{
  return a < b;
}
bool test_09_4 (const decimal128& a, const decimal64& b)
{
  return a < b;
}

bool test_09_5 (const decimal32& a, const decimal64& b)
{
  return a <= b;
}
bool test_09_6 (const decimal32& a, const decimal128& b)
{
  return a <= b;
}
bool test_09_7 (const decimal64& a, const decimal32& b)
{
  return a <= b;
}
bool test_09_8 (const decimal64& a, const decimal128& b)
{
  return a <= b;
}
bool test_09_9 (const decimal128& a, const decimal32& b)
{
  return a <= b;
}
bool test_09_10 (const decimal128& a, const decimal64& b)
{
  return a <= b;
}

// ----------------------------------------------------------------
// less/lessequal comparisons of implicitly converted types
bool test_10_0 (const decimal32& a, int8_t b)
{
  return a < b;
}
bool test_10_0 (const decimal32& a, int16_t b)
{
  return a < b;
}
bool test_10_0 (const decimal32& a, int32_t b)
{
  return a < b;
}
bool test_10_0 (const decimal32& a, int64_t b)
{
  return a < b;
}
bool test_10_0 (const decimal32& a, uint8_t b)
{
  return a < b;
}
bool test_10_0 (const decimal32& a, uint16_t b)
{
  return a < b;
}
bool test_10_0 (const decimal32& a, uint32_t b)
{
  return a < b;
}
bool test_10_0 (const decimal32& a, uint64_t b)
{
  return a < b;
}
bool test_10_ (const decimal32& a)
{
  return a < 0;
}

bool test_10_1 (const decimal32& a, int8_t b)
{
  return a <= b;
}
bool test_10_1 (const decimal32& a, int16_t b)
{
  return a <= b;
}
bool test_10_1 (const decimal32& a, int32_t b)
{
  return a <= b;
}
bool test_10_1 (const decimal32& a, int64_t b)
{
  return a <= b;
}
bool test_10_1 (const decimal32& a, uint8_t b)
{
  return a <= b;
}
bool test_10_1 (const decimal32& a, uint16_t b)
{
  return a <= b;
}
bool test_10_1 (const decimal32& a, uint32_t b)
{
  return a <= b;
}
bool test_10_1 (const decimal32& a, uint64_t b)
{
  return a <= b;
}
bool test_10_1 (const decimal32& a)
{
  return a <= 0;
}

bool test_10_2 (const decimal32& a, int8_t b)
{
  return b < a;
}
bool test_10_2 (const decimal32& a, int16_t b)
{
  return b < a;
}
bool test_10_2 (const decimal32& a, int32_t b)
{
  return b < a;
}
bool test_10_2 (const decimal32& a, int64_t b)
{
  return b < a;
}
bool test_10_2 (const decimal32& a, uint8_t b)
{
  return b < a;
}
bool test_10_2 (const decimal32& a, uint16_t b)
{
  return b < a;
}
bool test_10_2 (const decimal32& a, uint32_t b)
{
  return b < a;
}
bool test_10_2 (const decimal32& a, uint64_t b)
{
  return b < a;
}
bool test_10_2 (const decimal32& a)
{
  return 0 < a;
}

bool test_10_3 (const decimal32& a, int8_t b)
{
  return b <= a;
}
bool test_10_3 (const decimal32& a, int16_t b)
{
  return b <= a;
}
bool test_10_3 (const decimal32& a, int32_t b)
{
  return b <= a;
}
bool test_10_3 (const decimal32& a, int64_t b)
{
  return b <= a;
}
bool test_10_3 (const decimal32& a, uint8_t b)
{
  return b <= a;
}
bool test_10_3 (const decimal32& a, uint16_t b)
{
  return b <= a;
}
bool test_10_3 (const decimal32& a, uint32_t b)
{
  return b <= a;
}
bool test_10_3 (const decimal32& a, uint64_t b)
{
  return b <= a;
}
bool test_10_3 (const decimal32& a)
{
  return 0 <= a;
}

// ----------------------------------------------------------------
// unary plus, unary minus
decimal32 test_11_0 (const decimal32& a)
{
  return +a;
}
decimal64 test_11_0 (const decimal64& a)
{
  return +a;
}
decimal128 test_11_0 (const decimal128& a)
{
  return +a;
}

decimal32 test_11_1 (const decimal32& a)
{
  return -a;
}
decimal64 test_11_1 (const decimal64& a)
{
  return -a;
}
decimal128 test_11_1 (const decimal128& a)
{
  return -a;
}

// ----------------------------------------------------------------
// binary plus of two decimals of the same type
decimal32 test_12_0 (const decimal32& a, const decimal32& b)
{
  return a + b;
}
decimal32 test_12_0 (const decimal32& a, const decimal32& b, const decimal32& c, const decimal32& d)
{
  return a + b + c + d;
}
decimal64 test_12_0 (const decimal64& a, const decimal64& b)
{
  return a + b;
}
decimal64 test_12_0 (const decimal64& a, const decimal64& b, const decimal64& c, const decimal64& d)
{
  return a + b + c + d;
}
decimal128 test_12_0 (const decimal128& a, const decimal128& b)
{
  return a + b;
}
decimal128 test_12_0 (const decimal128& a, const decimal128& b, const decimal128& c, const decimal128& d)
{
  return a + b + c + d;
}

// ----------------------------------------------------------------
// binary plus of decimals of different types
// the result is automatically promoted to the wider type
decimal64 test_13_0 (const decimal64& a, const decimal32& b)
{
  auto r = a + b;
  static_assert (std::is_same< decltype (r), decimal64 >::value, "!");
  return r;
}

decimal128 test_13_0 (const decimal128& a, const decimal32& b)
{
  auto r = a + b;
  static_assert (std::is_same< decltype (r), decimal128 >::value, "!");
  return r;
}

decimal128 test_13_0 (const decimal128& a, const decimal64& b)
{
  auto r = a + b;
  static_assert (std::is_same< decltype (r), decimal128 >::value, "!");
  return r;
}

decimal64 test_13_0 (const decimal64& a, const decimal32& b, const decimal32& c, const decimal64& d)
{
  auto r = a + b + c + d;
  static_assert (std::is_same< decltype (r), decimal64 >::value, "!");
  return r;
}

decimal64 test_13_1 (const decimal64& a, const decimal32& b)
{
  auto r = b + a;
  static_assert (std::is_same< decltype (r), decimal64 >::value, "!");
  return r;
}

decimal128 test_13_1 (const decimal128& a, const decimal32& b)
{
  auto r = b + a;
  static_assert (std::is_same< decltype (r), decimal128 >::value, "!");
  return r;
}

decimal64 test_13_1 (const decimal64& a, const decimal32& b, const decimal32& c, const decimal64& d)
{
  auto r = b + a + c + d;
  static_assert (std::is_same< decltype (r), decimal64 >::value, "!");
  return r;
}


// ----------------------------------------------------------------
// binary plus of decimals and implicitely converted integral types
decimal32 test_14_0 (const decimal32& a, int b)
{
  auto r = a + b;
  static_assert (std::is_same<decltype (r), decimal32>::value, "!");
  return r;
}
decimal32 test_14_1 (const decimal32& a, int b)
{
  auto r = b + a;
  static_assert (std::is_same<decltype (r), decimal32>::value, "!");
  return r;
}
decimal32 test_14_2 (const decimal32& a)
{
  auto r = a + 4;
  static_assert (std::is_same<decltype (r), decimal32>::value, "!");
  return r;
}
decimal32 test_14_3 (const decimal32& a)
{
  auto r = 4 + a;
  static_assert (std::is_same<decltype (r), decimal32>::value, "!");
  return r;
}

// ----------------------------------------------------------------
// compound plus
void test_15_0 (decimal32& a, const decimal32& b)
{
  a += b;
}
void test_15_1 (decimal64& a, const decimal32& b)
{
  a += b;
}
void test_15_2 (decimal128& a, const decimal32& b)
{
  a += b;
}

void test_15_3 (decimal32& a, int8_t b)
{
  a += b;
}
void test_15_3 (decimal32& a, int16_t b)
{
  a += b;
}
void test_15_3 (decimal32& a, int32_t b)
{
  a += b;
}
void test_15_3 (decimal32& a, int64_t b)
{
  a += b;
}

void test_15_3 (decimal32& a, uint8_t b)
{
  a += b;
}
void test_15_3 (decimal32& a, uint16_t b)
{
  a += b;
}
void test_15_3 (decimal32& a, uint32_t b)
{
  a += b;
}
void test_15_3 (decimal32& a, uint64_t b)
{
  a += b;
}

void test_15_4 (decimal32& a, int b)
{
  a += b;
}


// ----------------------------------------------------------------
// explicit conversion to bool

bool test_16_0 (const decimal32& a)
{
  return static_cast<bool> (a);
}


// ----------------------------------------------------------------
// unary increment
decimal32 test_17_0 (decimal32& a)
{
  return ++a;
}
decimal32 test_17_1 (decimal32& a, const decimal32& b)
{
  return ++a + b;
}
decimal32 test_17_2 (decimal32& a)
{
  return a++;
}
decimal32 test_17_3 (decimal32& a, const decimal32& b)
{
  return a++ + b;
}
decimal32 test_17_4 (decimal32& a, const decimal32& b)
{
  return b + a++;
}
decimal64 test_17_4 (decimal32& a, const decimal64& b)
{
  return b + a++;
}



// ----------------------------------------------------------------
// binary minus of two decimals of the same type
decimal32 test_18_0 (const decimal32& a, const decimal32& b)
{
  return a - b;
}
decimal32 test_18_0 (const decimal32& a, const decimal32& b, const decimal32& c, const decimal32& d)
{
  return a - b - c - d;
}
decimal64 test_18_0 (const decimal64& a, const decimal64& b)
{
  return a - b;
}
decimal64 test_18_0 (const decimal64& a, const decimal64& b, const decimal64& c, const decimal64& d)
{
  return a - b - c - d;
}
decimal128 test_18_0 (const decimal128& a, const decimal128& b)
{
  return a - b;
}
decimal128 test_18_0 (const decimal128& a, const decimal128& b, const decimal128& c, const decimal128& d)
{
  return a - b - c - d;
}

// ----------------------------------------------------------------
// binary minus of decimals of different types
// the result is automatically promoted to the wider type
decimal64 test_19_0 (const decimal64& a, const decimal32& b)
{
  auto r = a - b;
  static_assert (std::is_same< decltype (r), decimal64 >::value, "!");
  return r;
}

decimal128 test_19_0 (const decimal128& a, const decimal32& b)
{
  auto r = a - b;
  static_assert (std::is_same< decltype (r), decimal128 >::value, "!");
  return r;
}

decimal128 test_19_0 (const decimal128& a, const decimal64& b)
{
  auto r = a - b;
  static_assert (std::is_same< decltype (r), decimal128 >::value, "!");
  return r;
}

decimal64 test_19_0 (const decimal64& a, const decimal32& b, const decimal32& c, const decimal64& d)
{
  auto r = a - b - c - d;
  static_assert (std::is_same< decltype (r), decimal64 >::value, "!");
  return r;
}

decimal64 test_19_1 (const decimal64& a, const decimal32& b)
{
  auto r = b - a;
  static_assert (std::is_same< decltype (r), decimal64 >::value, "!");
  return r;
}

decimal128 test_19_1 (const decimal128& a, const decimal32& b)
{
  auto r = b - a;
  static_assert (std::is_same< decltype (r), decimal128 >::value, "!");
  return r;
}

decimal64 test_19_1 (const decimal64& a, const decimal32& b, const decimal32& c, const decimal64& d)
{
  auto r = b - a - c - d;
  static_assert (std::is_same< decltype (r), decimal64 >::value, "!");
  return r;
}


// ----------------------------------------------------------------
// binary minus of decimals and implicitely converted integral types
decimal32 test_20_0 (const decimal32& a, int b)
{
  auto r = a - b;
  static_assert (std::is_same<decltype (r), decimal32>::value, "!");
  return r;
}
decimal32 test_20_1 (const decimal32& a, int b)
{
  auto r = b - a;
  static_assert (std::is_same<decltype (r), decimal32>::value, "!");
  return r;
}
decimal32 test_20_2 (const decimal32& a)
{
  auto r = a - 4;
  static_assert (std::is_same<decltype (r), decimal32>::value, "!");
  return r;
}
decimal32 test_20_3 (const decimal32& a)
{
  auto r = 4 - a;
  static_assert (std::is_same<decltype (r), decimal32>::value, "!");
  return r;
}


// ----------------------------------------------------------------
// compound minus
void test_21_0 (decimal32& a, const decimal32& b)
{
  a -= b;
}
void test_21_1 (decimal64& a, const decimal32& b)
{
  a -= b;
}
void test_21_2 (decimal128& a, const decimal32& b)
{
  a -= b;
}

void test_21_3 (decimal32& a, int8_t b)
{
  a -= b;
}
void test_21_3 (decimal32& a, int16_t b)
{
  a -= b;
}
void test_21_3 (decimal32& a, int32_t b)
{
  a -= b;
}
void test_21_3 (decimal32& a, int64_t b)
{
  a -= b;
}

void test_21_3 (decimal32& a, uint8_t b)
{
  a -= b;
}
void test_21_3 (decimal32& a, uint16_t b)
{
  a -= b;
}
void test_21_3 (decimal32& a, uint32_t b)
{
  a -= b;
}
void test_21_3 (decimal32& a, uint64_t b)
{
  a -= b;
}

void test_21_4 (decimal32& a)
{
  a -= 5;
}

// ----------------------------------------------------------------
// unary decrement
decimal32 test_22_0 (decimal32& a)
{
  return --a;
}
decimal32 test_22_1 (decimal32& a, const decimal32& b)
{
  return --a + b;
}
decimal32 test_22_2 (decimal32& a)
{
  return a--;
}
decimal32 test_22_3 (decimal32& a, const decimal32& b)
{
  return a-- + b;
}
decimal32 test_22_4 (decimal32& a, const decimal32& b)
{
  return b + a--;
}
decimal64 test_22_4 (decimal32& a, const decimal64& b)
{
  return b + a--;
}

// ----------------------------------------------------------------
// std::decimal::make_decimal

decimal32 test_23_0 (int c, int e)
{
  return std::decimal::make_decimal32 (c, e);
}

decimal32 test_23_1 (void)
{
  return std::decimal::make_decimal32 (4, 5);
}


// ----------------------------------------------------------------
// using _Decimal32, _Decimal64, _Decimal128

_Decimal128 test_24_0 (_Decimal32 a, _Decimal64 b)
{
  return a + b;
}