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

#define  DECNUMDIGITS (16)

extern "C"
{
#include "decNumber/decDouble.h"
#include "decNumber/decimal64.h"
#include "decNumber/decNumber.h"
}

#include <cassert>

extern "C"
{

void* decDoubleFromExpSignedCoef (void* _0, int64_t _1, int32_t _2) noexcept
{
  assert (false);
  return nullptr;
}
void* decDoubleFromExpUnsignedCoef (void* _0, uint64_t _1, int32_t _2) noexcept
{
  assert (false);
  return nullptr;
}

void* decDoubleExp (void* _0, const void* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;

  decDoubleToNumber (_1, &_1num);
  
  decNumberExp (&_0num, &_1num, ctx);

  return decDoubleFromNumber (_0, &_0num, ctx);
}

void* decDoubleLn (void* _0, const void* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;

  decDoubleToNumber (_1, &_1num);
  
  decNumberLn (&_0num, &_1num, ctx);

  return decDoubleFromNumber (_0, &_0num, ctx);
}

void* decDoubleLog10 (void* _0, const void* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;

  decDoubleToNumber (_1, &_1num);

  decNumberLog10 (&_0num, &_1num, ctx);

  return decDoubleFromNumber (_0, &_0num, ctx);
}

void* decDoublePower (void* _0, const void* _1, const void* _2, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;
  decNumber _2num;

  decDoubleToNumber (_1, &_1num);
  decDoubleToNumber (_2, &_2num);
  
  decNumberPower (&_0num, &_1num, &_2num, ctx);
  
  return decDoubleFromNumber (_0, &_0num, ctx);
}

void* decDoubleSquareRoot (void* _0, const void* _1, decContext* ctx) noexcept
{
  decNumber _0num;
  decNumber _1num;

  decDoubleToNumber (_1, &_1num);

  decNumberSquareRoot (&_0num, &_1num, ctx);

  return decDoubleFromNumber (_0, &_0num, ctx);
}

} // extern "C"
