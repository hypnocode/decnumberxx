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

#include "decimal"
#include <cassert>

namespace std
{
namespace decimal
{

#define expand_static_constants(__width__)\
  template <> const decimal##__width__ decimal##__width__::__const_one = decimal##__width__ (1);\
  template <> const decimal##__width__ decimal##__width__::__const_two = decimal##__width__ (2);\
  template <> const decimal##__width__ decimal##__width__::__const_zero = decimal##__width__ (0);\
  template <> const decimal##__width__ decimal##__width__::__const_int32_max = decimal##__width__ (std::numeric_limits<int32_t>::max ());\
  template <> const decimal##__width__ decimal##__width__::__const_uint32_max = decimal##__width__ (std::numeric_limits<uint32_t>::max ());\
  template <> const decimal##__width__ decimal##__width__::__const_uint32_max_plus_one = decimal##__width__ ((int64_t)std::numeric_limits<uint32_t>::max () + 1);\
  template <> const decimal##__width__ decimal##__width__::__const_e = decimal##__width__ ("2.71828182845904523536028747135266249775724709369995", ctor_from_string);\
  template <> const decimal##__width__ decimal##__width__::__const_ten = decimal##__width__ (10);\
  template <> const decimal##__width__ decimal##__width__::__const_emin = decimal##__width__ (decimal##__width__::emin);\
  template <> const decimal##__width__ decimal##__width__::__const_quiet_NaN = decimal##__width__ (ctor_quiet_nan);\
  template <> const decimal##__width__ decimal##__width__::__const_signaling_NaN = decimal##__width__ (ctor_signaling_nan);\

expand_static_constants (32)
expand_static_constants (64)
expand_static_constants (128)


#undef expand_static_constants


// calculated constants that cannot be calculated from within static initializers because
// they use runtime functions

#define expand_static_const_funcs(__width__)\
  template <> const decimal##__width__ & decimal##__width__::__const_min (void) noexcept\
  {\
    static const decimal##__width__ r = decimal##__width__ (ctor_min); return r;\
  }\
  template <> const decimal##__width__ & decimal##__width__::__const_infinity (void) noexcept\
  {\
    static const decimal##__width__ r = decimal##__width__ (ctor_infinity); return r;\
  }\
  template <> const decimal##__width__ & decimal##__width__::__const_lowest (void) noexcept\
  {\
    static const decimal##__width__ r = decimal##__width__ (ctor_lowest); return r;\
  }\
  template <> const decimal##__width__ & decimal##__width__::__const_max (void) noexcept\
  {\
    static const decimal##__width__ r = decimal##__width__ (ctor_max); return r; \
  }\
  template <> const decimal##__width__ & decimal##__width__::__const_epsilon (void) noexcept \
  {\
    static const decimal##__width__ r = decimal##__width__ (ctor_epsilon); return r;\
  }\
  template <> const decimal##__width__ & decimal##__width__::__const_round_error (void) noexcept \
  {\
    static const decimal##__width__ r = decimal##__width__ (ctor_round_error); return r;\
  }\
  template <> const decimal##__width__ & decimal##__width__::__const_denorm_min (void) noexcept \
  {\
    static decimal##__width__ r = decimal##__width__ (ctor_denorm_min); return r;\
  }\
  
expand_static_const_funcs (32)
expand_static_const_funcs (64)
expand_static_const_funcs (128)

#undef expand_static_const_funcs


template<> void decnumber_promote_demote<32, 64>::convert (void* dst, const void* src, void* ctx) noexcept
{
  decSingleToWider (src, dst);
}
template<> void decnumber_promote_demote<32, 128>::convert (void* dst, const void* src, void* ctx) noexcept
{
  decimal64 tmp;
  decSingleToWider (src, &tmp);
  decDoubleToWider (&tmp, dst);
}
template<> void decnumber_promote_demote<64, 128>::convert (void* dst, const void* src, void* ctx) noexcept
{
  decDoubleToWider (src, dst);
}

template<> void decnumber_promote_demote<64, 32>::convert (void* dst, const void* src, void* ctx) noexcept
{
  decSingleFromWider (dst, src, ctx);
}
template<> void decnumber_promote_demote<128, 32>::convert (void* dst, const void* src, void* ctx) noexcept
{
  decimal64 tmp;
  decDoubleFromWider (&tmp, src, ctx);
  decSingleFromWider (dst, &tmp, ctx);
}
template<> void decnumber_promote_demote<128, 64>::convert (void* dst, const void* src, void* ctx) noexcept
{
  decDoubleFromWider (dst, src, ctx);
}

} // namespace decimal
} // namespace std

