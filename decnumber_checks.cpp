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

#define __decnumber__impl__

#include "decimal"

extern "C"
{
#include "decNumber/decSingle.h"
#include "decNumber/decDouble.h"
#include "decNumber/decQuad.h"
#include "decNumber/decContext.h"
}


static_assert (sizeof (int32_t) == sizeof (rounding), "rounding enum sizeof mismatch");

static_assert (FE_DEC_DOWNWARD == DEC_ROUND_FLOOR, "FE_DEC_DOWNWARD != DEC_ROUND_FLOOR");
static_assert (FE_DEC_TONEAREST == DEC_ROUND_HALF_EVEN, "FE_DEC_TONEAREST != DEC_ROUND_HALF_EVEN");
//static_assert (FE_DEC_TONEARESTFROMZERO == , "FE_DEC_TONEARESTFROMZERO != ");
static_assert (FE_DEC_TOWARD_ZERO == DEC_ROUND_DOWN, "FE_DEC_TOWARD_ZERO != DEC_ROUND_DOWN");
static_assert (FE_DEC_UPWARD == DEC_ROUND_CEILING, "FE_DEC_UPWARD != DEC_ROUND_CEILING");


#define expand_check_field(w,f)\
static_assert (sizeof (std::decimal::decnumber_context< w >:: f) == sizeof (decContext:: f), "broken sizeof context field '" #f "'");\
static_assert (offsetof (std::decimal::decnumber_context < w >, f) == offsetof (decContext, f), "broken offsetof context field '" #f "'");\


#define expand_checks(w)\
static_assert (sizeof (std::decimal::decnumber_context< w >) == sizeof (decContext), "context sizeof mismatch"); \
expand_check_field (w, digits) \
expand_check_field (w, emax) \
expand_check_field (w, emin) \
expand_check_field (w, round) \
expand_check_field (w, traps) \
expand_check_field (w, status) \
expand_check_field (w, clamp) \


expand_checks (32)
expand_checks (64)
expand_checks (128)

#undef expand_checks
#undef expand_check_field

#define expand_checks(ww, w)\
static_assert (ww ## _Bytes == std::decimal::decnumber_traits<w>::byte_len, "decimal" #w " bad byte_len"); \
static_assert (ww ## _Pmax == std::decimal::decnumber_traits<w>::pmax, "decimal" #w " bad pmax"); \
static_assert (ww ## _Emin == std::decimal::decnumber_traits<w>::emin, "decimal" #w " bad emin"); \
static_assert (ww ## _Emax == std::decimal::decnumber_traits<w>::emax, "decimal" #w " bad emax"); \
static_assert (ww ## _EmaxD == std::decimal::decnumber_traits<w>::emaxd, "decimal" #w " bad emaxd"); \
static_assert (ww ## _Bias == std::decimal::decnumber_traits<w>::bias, "decimal" #w " bad bias"); \
static_assert (ww ## _String == std::decimal::decnumber_traits<w>::max_strlen, "decimal" #w " bad max_strlen"); \
static_assert (ww ## _EconL == std::decimal::decnumber_traits<w>::econl, "decimal" #w " bad econl"); \
static_assert (ww ## _Declets == std::decimal::decnumber_traits<w>::declets, "decimal" #w " bad declets"); \

expand_checks (DECSINGLE, 32)
expand_checks (DECDOUBLE, 64)
expand_checks (DECQUAD, 128)
