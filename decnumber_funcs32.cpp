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

#define  DECNUMDIGITS (7)

extern "C"
{
#include "decNumber/decSingle.h"
#include "decNumber/decimal32.h"
#include "decNumber/decQuad.h"
#include "decNumber/decDouble.h"
#include "decNumber/decNumber.h"
}

#define __decnumber__impl__
#include "decimal"

#include <cassert>

extern "C"
{

void* decSingleFromExpSignedCoef (void* _0, int64_t _1, int32_t _2) noexcept
{
  assert (false);
  return nullptr;
}
void* decSingleFromExpUnsignedCoef (void* _0, uint64_t _1, int32_t _2) noexcept
{
  assert (false);
  return nullptr;
}

void* decSingleFromInt32 (void* _res, int32_t ival) noexcept
{
  decNumber _resnum;
  decNumberFromInt32 (&_resnum, ival);
  std::decimal::decimal32::context ctx;
  return decSingleFromNumber (_res, &_resnum, (decContext*)&ctx);
}

/*
void* decSingleFromInt32 (void* res, int32_t ival) noexcept
{
  decimal64 r = ival;
  decimal32::context ctx;
  return decSingleFromWider (res, &r, &ctx);
}
*/

void* decSingleFromUInt32 (void* _res, uint32_t val) noexcept
{
  decNumber _resnum;
  decNumberFromUInt32 (&_resnum, val);
  std::decimal::decimal32::context ctx;
  return decSingleFromNumber (_res, &_resnum, (decContext*)&ctx);
}

/*
void* decSingleFromUInt32 (void* res, uint32_t val) noexcept
{
  decimal64 r = val;
  decimal32::context ctx;
  return decSingleFromWider (res, &r, &ctx);
}
*/

/*
int32_t decSingleToInt32 (const void* _0, void* _1, int32_t _2) noexcept
{
  decNumber _0num;
  decSingleToNumber (_0, &_0num);
  return 
}*/

int32_t decSingleToInt32 (const decSingle* _0, decContext* ctx, int32_t _2) noexcept
{
  decDouble r;
  decSingleToWider (_0, &r);
  return decDoubleToInt32 (&r, ctx, (enum rounding)_2);
}

int32_t decSingleToInt32Exact (const decSingle* _0, decContext* _1, int32_t _2) noexcept
{
  decDouble r;
  decSingleToWider (_0, &r);
  return decDoubleToInt32Exact (&r, _1, (enum rounding)_2);
}

uint32_t decSingleToUInt32 (const decSingle* _0, decContext* _1, int32_t _2) noexcept
{
  decDouble r;
  decSingleToWider (_0, &r);
  return decDoubleToUInt32 (&r, _1, (enum rounding)_2);
}

uint32_t decSingleToUInt32Exact (const decSingle* _0, decContext* _1, int32_t _2) noexcept
{
  decDouble r;
  decSingleToWider (_0, &r);
  return decDoubleToUInt32Exact (&r, _1, (enum rounding)_2);
}

void* decSingleToIntegralValue (decSingle* _0, const decSingle* _1, decContext* ctx, int32_t rnd) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  enum rounding prev_rnd = ctx->round;
  ctx->round = (enum rounding)rnd;
  decNumberToIntegralValue (&_0num, &_1num, ctx);
  ctx->round = prev_rnd;
  return decSingleFromNumber (_0, &_0num, ctx);
}


void* decSingleAbs (decSingle* _0, const decSingle* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  decNumberAbs (&_0num, &_1num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleAdd (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberAdd (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleDivide (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberDivide (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleMultiply (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberMultiply (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleSubtract (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberSubtract (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleShift (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberShift (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleFMA (decSingle* _0, const decSingle* _1, const decSingle* _2, const decSingle* _3, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decNumber _3num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decSingleToNumber (_3, &_3num);
  decNumberFMA (&_0num, &_1num, &_2num, &_3num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleExp (void* _0, const void* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  decNumberExp (&_0num, &_1num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleLn (void* _0, const void* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  decNumberLn (&_0num, &_1num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleLog10 (void* _0, const void* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  decNumberLog10 (&_0num, &_1num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSinglePower (void* _0, const void* _1, const void* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberPower (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleSquareRoot (void* _0, const void* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  decNumberSquareRoot (&_0num, &_1num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleNextMinus (decSingle* _0, const decSingle* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  decNumberNextMinus (&_0num, &_1num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleNextPlus (decSingle* _0, const decSingle* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  decNumberNextPlus (&_0num, &_1num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleCompare (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberCompare (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}


static inline bool is_signed (uint32_t word) noexcept
{
  return (word & std::decimal::decimal32::sign_mask) != 0;
}

static inline bool is_zero (uint32_t word) noexcept
{
  return (word & 0x1c0fffff) == 0
  		  && (word & 0x60000000) != 0x60000000;
}

static inline bool is_nan (uint32_t word) noexcept
{
  const auto nan_mask = std::decimal::decimal32::nan_mask;
  return (word & nan_mask) == nan_mask;
}


uint32_t decSingleIsNegative (const void* _0) noexcept
{
// see decBasic.c, decNumberLocal.h
  const uint32_t word = *((const uint32_t*)_0);
  return is_signed (word) && !is_zero (word) && !is_nan (word);
}

uint32_t decSingleIsPositive (const decSingle* _0) noexcept
{
// see decBasic.c, decNumberLocal.h
  const uint32_t word = *((const uint32_t*)_0);
  return !is_signed (word) && !is_zero (word) && !is_nan (word);
}

uint32_t decSingleIsZero (const void* _num) noexcept
{
  // see decNumberLocal.h
  return is_zero (*((const uint32_t*)_num));  
}

uint32_t decSingleIsNaN (const decSingle* _num) noexcept
{
  return is_nan (*((const uint32_t*)_num));
}

void* decSingleLogB (decSingle* _0, const decSingle* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decSingleToNumber (_1, &_1num);
  decNumberLogB (&_0num, &_1num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleMax (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberMax (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleMin (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberMin (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleNextToward (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberNextToward (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleRemainder (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberRemainder (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

void* decSingleScaleB (decSingle* _0, const decSingle* _1, const decSingle* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;
  decSingleToNumber (_1, &_1num);
  decSingleToNumber (_2, &_2num);
  decNumberScaleB (&_0num, &_1num, &_2num, ctx);
  return decSingleFromNumber (_0, &_0num, ctx);
}

uint32_t decSingleIsNormal (const decSingle* _0) noexcept
{
  decNumber _0num;
  decSingleToNumber (_0, &_0num);
  std::decimal::decimal32::context ctx;
  return decNumberIsNormal (&_0num, (decContext*)&ctx);
}

uint32_t decSingleIsFinite (const decSingle* _0) noexcept
{
  decNumber _0num;
  decSingleToNumber (_0, &_0num);
  return decNumberIsFinite (&_0num);
}

uint32_t decSingleIsInfinite (const decSingle* _0) noexcept
{
  decNumber _0num;
  decSingleToNumber (_0, &_0num);
  return decNumberIsInfinite (&_0num);
}

void* decSingleCopySign (decSingle* _0, const decSingle* _1, const decSingle* _2) noexcept
{
  uint32_t* _0w = (uint32_t*)_0;
  uint32_t _1w = *(const uint32_t*)_1;
  uint32_t _2w = *(const uint32_t*)_2;

  uint32_t res = _1w & ~std::decimal::decimal32::sign_mask;  // clear sign
  res |= _2w & std::decimal::decimal32::sign_mask; // set sign
  *_0w = res;
  return _0;
}

/*
decSingleDivideInteger
decSingleInvert
decSingleMaxMag
decSingleMinMag
decSingleMinus

decSingleOr
decSinglePlus
decSingleQuantize
decSingleReduce
decSingleRemainderNear
decSingleRotate

decSingleToIntegralExact
decSingleXor

decSingleCompareSignal
decSingleCompareTotal
decSingleCompareTotalMag

decSingleCanonical
decSingleCopy
decSingleCopyAbs

decSingleClass
decSingleClassString
decSingleDigits
decSingleIsCanonical
decSingleIsInteger
decSingleIsLogical

decSingleIsSignaling
decSingleIsSigned
decSingleIsSubnormal
decSingleSameQuantum
*/

} // extern "C"
