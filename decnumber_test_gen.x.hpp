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

#ifdef decimaltype

#include <limits>
#include <cmath>

#define __concat(a, b) a ## b

#define make_func(__t__) __concat (make_, __t__)

#define __decimaltypename(__t__) #__t__
#define decimaltypename __decimaltypename(decimaltype)

// ----------------------------------------------------------------
// std::decimal::make_decimal

static decimaltype test_23_0 (int c, int e)
{
  return std::decimal:: make_func (decimaltype) (c, e);
}

static decimaltype test_23_1 (void)
{
  return std::decimal:: make_func (decimaltype) (4, 5);
}


// ----------------------------------------------------------------

static decimaltype test_100_1 (decimaltype a, decimaltype b)
{
	decimaltype r;
	r = a * b;
	return r;
}

static decimaltype test_100_2 (decimaltype a, decimaltype b)
{
	return (decimaltype)(a * b);
}

static int32_t test_101_0 (const decimaltype& a)
{
  return (int32_t)a;
}
static int64_t test_101_1 (const decimaltype& a)
{
  return (int64_t)a;
}
static uint32_t test_101_2 (const decimaltype& a)
{
  return (uint32_t)a;
}
static uint64_t test_101_3 (const decimaltype& a)
{
  return (uint64_t)a;
}

static decimaltype test_101_4 (int64_t val)
{
	return val;
}
static decimaltype test_101_5 (int32_t val)
{
	return val;
}

static int32_t test_102 (decimaltype a)
{
	return (int32_t)a;
}

static decimaltype test_103 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a * b + c * d;
}

static decimaltype test_104 (decimaltype a)
{
	return (decimaltype)a;
}

static decimaltype test_105 (decimaltype a)
{
	return std::abs (a);
}

static decimaltype test_107 (decimaltype a, decimaltype b)
{
	return std::min (a, b);
}

static decimaltype test_108 (decimaltype a, decimaltype b)
{
	return std::max (a, b);
}

static decimaltype test_114 (void)
{
	return 1;
}

/*
static decimal128 test_115 (decimal64 a, decimal128 b)
{
	return a + b;
}

static decimal64 test_116 (decimal128 a, decimal128 b)
{
	return (decimal64)(a + b);
}
*/

static decimaltype test_117_2 (decimaltype a, decimaltype b)
{
	return a + b;
}

static decimaltype test_117_3 (decimaltype a, decimaltype b)
{
	return a * b;
}

static decimaltype test_117_4 (decimaltype a, decimaltype b)
{
	return a - b;
}

static void test_118 (decimaltype& a, int b)
{
	a *= b;
}

static void test_119_1 (decimaltype& a, decimaltype b, decimaltype c)
{
	a *= b * c;
}

static decimaltype test_123 (float a)
{
	return decimaltype (a);
}

static decimaltype test_126 (decimaltype& a)
{
  return a ++;
}

static decimaltype test_126_1 (decimaltype a)
{
	return ++ a;
}

decimaltype test_129 (decimaltype a, int b)
{
	return b * a;
}

decimaltype test_130 (decimaltype a, bool b)
{
	return b * a;
}

decimaltype test_131 (decimaltype a, int b)
{
	return a / b;
}

static int32_t test_133 (decimaltype a, int32_t b, int32_t c)
{
	if (a)  // converted to bool even though the conversion op is explicit
		return b; 
	else
		return c;
}

static bool test_134_0 (decimaltype a)
{
	return (bool)a;
}

static decimaltype test_34_1 (bool a)
{
	return a; // implicit conversion ctor from bool
}

static decimaltype test_135 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a * b * c * d;
}

static decimaltype test_136 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return (a * b) * (c * d);
}

static decimaltype test_137 (decimaltype a, decimaltype b, decimaltype c, decimaltype& d)
{
	d *= a * b;
	return d;
}

static decimaltype test_138 (decimaltype a, decimaltype b, decimaltype c, decimaltype& d)
{
	d += a * b;
	return d;
}

static decimaltype test_138_1 (decimaltype a, decimaltype b, float c, float d)
{
	return a + (decimaltype)c;
}

static decimaltype test_139 (decimaltype a, decimaltype b, decimaltype c, decimaltype& d)
{
	return a * b + c;
}

static decimaltype test_140 (decimaltype a, decimaltype b, decimaltype c, decimaltype& d)
{
	return c + a * b;
}

static decimaltype test_141 (decimaltype a, decimaltype b, int c, int d)
{
	return -(a * b);
}

static decimaltype test_142 (decimaltype a, decimaltype b, decimaltype& c, int d)
{
	c -= a * b;
	return c;
}

static decimaltype test_143 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return (a * b) - (c * d);
}

static decimaltype test_144 (decimaltype a, decimaltype b, int c, decimaltype d)
{
	return (a * b) + c;
}

static decimaltype test_145 (decimaltype a, decimaltype b, int c, decimaltype d)
{
	return (a * b) - c;
}

static decimaltype test_146 (decimaltype a, decimaltype b, int c, decimaltype d)
{
	return (a * b) - c + d;
}

static decimaltype test_147 (decimaltype a, decimaltype b, int c, decimaltype d, int e)
{
	return ((a * b) - c + d) * e;
}

static decimaltype test_148 (decimaltype a, decimaltype b, int c, decimaltype d)
{
	return (a * b) / c;
}

static decimaltype test_149 (decimaltype a, decimaltype b, int c, decimaltype d)
{
	return a / b;
}

static decimaltype test_150 (decimaltype a, decimaltype b, int c, decimaltype d)
{
	return (a * b) / d;
}

static decimaltype test_151 (decimaltype a, decimaltype b, int c, decimaltype d)
{
	return d / (a * b);
}

static void test_151 (decimaltype a, decimaltype b, int c, decimaltype& d)
{
	d /= a * b;
}

static decimaltype test_152 (decimaltype a, decimaltype b, decimaltype c, decimaltype& d)
{
	return (a * b) / (c * d);
}

static decimaltype test_153 (decimaltype a, decimaltype b, decimaltype c, decimaltype& d)
{
	return a * b / c * d;
}

static decimaltype test_154 (decimaltype a, decimaltype b, decimaltype c, decimaltype& d)
{
	return a * b / c + d;
}

static decimaltype test_155 (decimaltype a, decimaltype b, decimaltype c)
{
	return (decimaltype)a;
}

static decimaltype test_156 (decimaltype a, decimaltype b, decimaltype c)
{
	return (decimaltype)a + (decimaltype)b;
}

static decimaltype test_157 (void)
{
	// implicit
	decimaltype r = 12;
	r = 18;
	return 4;	
}

static decimaltype test_158 (decimaltype a, decimaltype b, decimaltype& c, int d)
{
	auto r = a * b;
	r = c;	// implicit conversion to widened
	return d;
}

static decimaltype test_159 (decimaltype a, float b)
{
	return a + decimaltype (b);
}

static decimaltype test_160 (decimaltype a, float b)
{
	return a * decimaltype (b);
}

static decimaltype test_161 (float a, decimaltype b)
{
	return decimaltype (a) * b;
}

static decimaltype test_162 (decimaltype a)
{
	return 5 + a;
}

static decimaltype test_163 (decimaltype a)
{
	return a + 5;
}

static decimaltype test_164 (decimaltype a)
{
	return a * 5;
}

static decimaltype test_165 (decimaltype a)
{
	return 5 * a;
}

static decimaltype test_166 (decimaltype a, decimaltype b, float c)
{
	return a * (b * decimaltype (c));
}

static decimaltype test_167 (decimaltype a, decimaltype b, float c)
{
	return (a * b) * decimaltype (c);
}

static decimaltype test_168 (decimaltype a, decimaltype b, float c)
{
	return a * b * decimaltype (c);
}

static decimaltype test_169 (decimaltype a, decimaltype b, float c, int d)
{
	return a * b * decimaltype (c) + decimaltype (d);
}

static decimaltype test_170 (decimaltype a, decimaltype b, float c, int d)
{
	return a * b * decimaltype (c) * decimaltype (d);
}

static bool test_171 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a == b;
}

static bool test_172 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a != b;
}

static bool test_173 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a == b;
}

static bool test_174 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a < b;
}

static bool test_175 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a <= b;
}

static bool test_176 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a > b;
}

static bool test_177 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a >= b;
}

static bool test_178 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return !a;
}

static bool test_179 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a * b == c;
}

static bool test_180 (decimaltype a, decimaltype b, decimaltype c, decimaltype d)
{
	return a * b + c == d;
}

static const decimaltype& test_83 (void)
{
	static const decimaltype x = decimaltype (5.5);
	return x;
}

#define to_func(__t__, __f__) __concat(__t__, __f__)

static long long test_181_0 (decimaltype a)
{
  return std::decimal:: to_func (decimaltype, _to_long_long) (a);
}
static long long test_181_1 (decimaltype a)
{
  return std::decimal:: to_func (decimal, _to_long_long) (a);
}

static float test_182_0 (decimaltype a)
{
  return std::decimal:: to_func (decimaltype, _to_float) (a);
}
static float test_182_1 (decimaltype a)
{
  return std::decimal:: to_func (decimal, _to_float) (a);
}

static double test_183_0 (decimaltype a)
{
  return std::decimal:: to_func (decimaltype, _to_double) (a);
}
static double test_183_1 (decimaltype a)
{
  return std::decimal:: to_func (decimal, _to_double) (a);
}

static long double test_184_0 (decimaltype a)
{
  return std::decimal:: to_func (decimaltype, _to_long_double) (a);
}
static long double test_184_1 (decimaltype a)
{
  return std::decimal:: to_func (decimal, _to_long_double) (a);
}


#if 0

static constexpr decimaltype constexpr_add (decimaltype a, decimaltype b)
{
	return a + b;
}

static constexpr decimaltype global_z = constexpr_add (5, 6);


static decimaltype test_84 (decimaltype a, decimaltype b)
{
	return std::copysign (a, b);
}

static decimaltype test_100 (bool val)
{
	return val;
}




//CMath Extension


//Numeric_Limits



static void test_10X ()
{
	//Numeric_Limits min
	decimal64 m = std::numeric_limits<decimal64 >::min();
	std::cout << "Min.IsNormal: " << m.isNormal() << std::endl;
	std::cout << "Min.lhs.IsNormal: " << m.nextMinus().isNormal() << std::endl;
}

static void test_10XX ()
{
	//Numeric_Limits max
	decimal64 m = std::numeric_limits<decimal64 >::max();
	std::cout << "Max.IsNormal: " << m.isNormal() << std::endl;
	std::cout << "Max.IsFinite: " << std::isfinite(m) << std::endl;
	
	std::cout << "Max.rhs.IsNormal: " << m.nextPlus().isNormal() << std::endl;
	std::cout << "Max.rhs.IsFinite: " << std::isfinite(m.nextPlus()) << std::endl;
}


#endif


///////////////////////////////////////////////////////////////////////////////

#ifndef test_func
#define test_func(__t__) __concat (std_decimal_test_, __t__)
#endif

static void test_func (decimaltype) (void)
{
	decimaltype a = decimaltype (3);

	assert (a == 3);
	assert (a != 4);
	assert (test_100_1 (a, 4) == 12);
	assert (test_100_2 (3, 4) == 12);

	assert (test_101_0 (true) == 1);
	assert (test_101_0 (false) == 0);
	
	assert (test_101_4 (3) == 3);
	assert (test_101_5 (3) == 3);

	assert (test_102 (decimaltype (a)) == (int32_t)3);
	assert (test_103 (a, 3, 3, 3) == 18);


	assert (test_104 (decimaltype (a)) == 3);
	assert (decimaltype (3.45) > decimaltype (3.0));
	assert (test_105 (decimaltype (3.45)) == decimaltype (3.45) );
	assert (test_107 (decimaltype (3.45), decimaltype (3.46)) == decimaltype (3.45));
	assert (test_108 (decimaltype (3.45), decimaltype (3.46)) == decimaltype (3.46));
	assert (test_114 () == 1);
//	assert (test_115 (a, 4) == 7);
//	assert (test_116 (a, 4) == decimaltype (7));
	assert (test_117_2 (a, 4) == 7);
	assert (test_117_3 (a, 4) == 12);
	assert (test_117_4 (a, 4) == -1);

	a = 3;	
	test_118 (a, 4);
	assert (a == 12);

	
	a = 3;
	test_119_1 (a, 3, 3);
	assert (a == 27);
	
	assert (test_123 (5.0f) == decimaltype (5.0f));

	assert (test_126 (a) == 27);
	assert (a == 28);
	
	assert (test_126_1 (a) == 29);
	
	a = 3;
	assert (test_129 (a, 4) == 12);
	assert (test_130 (a, true) == 3);
	assert (test_131 (a, 2) == decimaltype (1.5));
	
	a = 256*2;
	assert (test_131 (a, 256) == 2);
	assert (test_133 (a, 1, 2) == 1);
	assert (test_134_0 (a) == 1);
	
	a = 2;
	assert (test_135 (a, a, a, a) == 16);
	assert (test_136 (a, a, a, a) == 16);

	decimaltype c = 2; a = 2;
	assert (test_137 (a, a, a, c) == 8);
	assert (test_138 (a, a, a, c) == 12);

	assert (test_138_1 (a, c, 3.0f, 4.0f) == 5);
	assert (test_139 (2, 2, 2, a) == 6);
	assert (test_140 (2, 2, 2, a) == 6); 
	assert (test_141 (2, 2, 2, 2) == -4);
	assert (test_142 (2, 2, a, 2) == -2);
	assert (test_143 (2, 2, 2, 2) == 0);
	assert (test_144 (2, 2, 2, 2) == 6);
	assert (test_145 (2, 2, 2, 2) == 2);
	assert (test_146 (2, 2, 2, 2) == 4);
	assert (test_147 (2, 2, 2, 2, 2) == 8);
	assert (test_148 (2, 2, 2, 2) == 2);
	assert (test_149 (2, 2, 2, 2) == 1);
	assert (test_150 (2, 2, 2, 2) == 2);
	assert (test_151 (2, 2, 2, 2) == decimaltype (0.5));

	c = 2;
	assert (test_152 (2, 2, 2, c) == 1);
	assert (test_153 (2, 2, 2, c) == 4);
	assert (test_154 (2, 2, 2, c) == 4);
	assert (test_155 (2, 2, 2) == 2);
	assert (test_156 (2, 2, 2) == decimaltype (4));
	assert (test_157 () == decimaltype (4));
	assert (test_158 (2, 2, c, 2) == 2);
	assert (test_159 (2, 2.0f) == decimaltype (4));
	assert (test_160 (2, 2.0f) == 4);
	assert (test_161 (1.2f, 2) == decimaltype (2.4f));
	assert (test_162 (3) == 8);
	assert (test_163 (3) == 8);
	assert (test_164 (3) == 15);
	assert (test_165 (3) == decimaltype (15.0f));
	assert (test_166 (2, 2, 3.0f) == 12);
	assert (test_167 (2, 2, 2) == 8);
	assert (test_168 (2, 2, 2) == 8);
	assert (test_169 (2, 2, 2, 4) == 12);
	assert (test_170 (2, 2, 2, 2) == 16);
	assert (test_171 (2, 2, 2, 2) == 1);
	assert (test_172 (2, 2, 2, 2) == 0);
	assert (test_173 (2, 2, 2, 2) == 1);
	assert (test_174 (2, 3, 2, 2) == 1);
	assert (test_175 (2, 2, 2, 2) == 1);
	assert (test_176 (2, 2, 2, 2) == 0);
	assert (test_177 (2, 2, 2, 2) == 1);
	assert (test_178 (2, 2, 2, 2) == 0);
	assert (test_179 (2, 2, 4, 2) == 1);
	assert (test_180 (2, 2, 2, 6) == 1);
	
	assert (test_181_0 (decimaltype (42) == 42));
	assert (test_181_1 (decimaltype (42) == 42));

	assert (test_182_0 (decimaltype (42) == 42));
	assert (test_182_1 (decimaltype (42) == 42));

	assert (test_183_0 (decimaltype (42) == 42));
	assert (test_183_1 (decimaltype (42) == 42));

	assert (test_184_0 (decimaltype (42) == 42));
	assert (test_184_1 (decimaltype (42) == 42));

	static const decimaltype sc = decimaltype (5.5f);
	assert ( test_83() == sc );

	// formatted output
	{
	  std::stringstream ss;
	  ss << decimaltype (5);
	  std::cout << ss.str () << std::endl;
	  assert (ss.str () == "5");
	}

	{
	  std::stringstream ss;
	  ss << decimaltype (5.1);
	  std::cout << ss.str () << std::endl;
//	  assert (ss.str () == "5.1");
	}
	

	// formatted input
	{
	  std::stringstream ss ("341");
	  decimaltype n;
	  ss >> n;
	
	}
	

	// cmath,algorithm,limits extensions 

	{
	  decimaltype min_val = std::numeric_limits<decimaltype>::min ();
	  std::cout << decimaltypename " min: " << min_val << std::endl;
	  assert (min_val != 0);
	}

	{
	  decimaltype max_val = std::numeric_limits<decimaltype>::max ();
	  std::cout << decimaltypename " max: " << max_val << std::endl;
	  assert (max_val != 0);
	}

	{
	  decimaltype lowest_val = std::numeric_limits<decimaltype>::lowest ();
	  std::cout << decimaltypename " lowest: " << lowest_val << std::endl;
	  assert (lowest_val != 0);
	}

	{
	  decimaltype qnan_val = std::numeric_limits<decimaltype>::quiet_NaN ();
	  std::cout << decimaltypename " qnan: " << qnan_val << std::endl;
	  assert (qnan_val != 0);
	}

	{
	  decimaltype snan_val = std::numeric_limits<decimaltype>::signaling_NaN ();
	  std::cout << decimaltypename " snan: " << snan_val << std::endl;
	  assert (snan_val != 0);
	}

	{
	  decimaltype nan_a = std::numeric_limits<decimaltype>::quiet_NaN ();
	  decimaltype nan_b = std::numeric_limits<decimaltype>::quiet_NaN ();
	  
	  assert ((nan_a == nan_b) == false);
	  assert ((nan_a == 1) == false);
	  assert ((nan_a == 0) == false);
	  assert (std::isnan (nan_a) == true);
	  assert (std::isnormal (nan_a) == false);
	  assert (std::isfinite (nan_a) == false);
	  assert (std::isinf (nan_a) == false);
	}

	
	assert (std::abs (decimaltype (-4.3)) == decimaltype (4.3));
	assert (std::min (decimaltype (3), decimaltype (4)) == decimaltype (3));
	assert (std::max (decimaltype (3), decimaltype (4)) == decimaltype (4));
	assert (std::min (decimaltype (-3), decimaltype (-4)) == decimaltype (-4));
	assert (std::max (decimaltype (-3), decimaltype (-4)) == decimaltype (-3));
	assert (std::pow (decimaltype (3), decimaltype (3)) == decimaltype (27));

	assert (std::isfinite (decimaltype (std::numeric_limits<decimaltype>::max ())));
//	assert (std::isfinite (decimaltype (std::numeric_limits<decimaltype>::max ().nextPlus ())) == false);
	assert (std::isinf (decimaltype (std::numeric_limits<decimaltype>::max ())) == false);
//	assert (std::isinf (decimaltype (std::numeric_limits<decimaltype>::max ().nextPlus ())));

	assert (std::trunc (decimaltype (3.9)) == decimaltype (3));
	assert (std::isnan (decimaltype (3.4)) == false);

	assert (! std::isnormal (std::numeric_limits<decimaltype>::denorm_min ()));

	assert (std::isnormal (std::numeric_limits<decimaltype>::denorm_min ()) == false);
	assert (std::isnormal (decimaltype (3.234894728)));

	decimaltype x = 2; 
	decimaltype y = 3; 
	decimaltype z = 4;
	assert (std::fma (x, y, z) == decimaltype (10));

	assert (std::nextafter (x, y) == x + std::numeric_limits<decimaltype>::epsilon ());
	assert (std::nexttoward (x, y) == x + std::numeric_limits<decimaltype>::epsilon ());

	assert (std::signbit (x) == 0);
	assert (std::signbit (x * (-1)) == 1);
	assert (std::copysign (x, y) == x);

	y *= -2;
	assert (std::copysign (x, y) == x * (-1));
	assert (std::round (decimaltype (3.46)) == decimaltype (3));
	assert (std::round (decimaltype (3.56)) == decimaltype (4));
}


#undef __decimaltypename
#undef decimaltypename
#undef decimaltypename
#undef test_func
#undef make_func
#undef __concat
#undef decimaltype
#endif // decimaltype