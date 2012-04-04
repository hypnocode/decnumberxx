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

#ifndef dectype
  #error dectype must be defined to use this x-maro
#else

#ifdef gen_extern_c_declarations

#define __concat(a, b, c) a ## b ## c

#define decarg __concat (dec, dectype)


#define func(__type__, __ret__, __func__, ...) extern "C" __ret__ __concat (dec, __type__, __func__) (__VA_ARGS__) noexcept;

#undef gen_extern_c_declarations
#endif // gen_extern_c_declarations


#ifdef gen_cpp_wrappers

#define __concat(a, b, c) a ## b ## c

#define __pu_concat(a, b) __pu_concat_impl(a, b)
#define __pu_concat_impl(a, b) a ## b

#define __pu_va_args_count_impl(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N
#define __pu_va_args_count(...) __pu_va_args_count_impl(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1)

#define __pu_repeat_impl0(__macro__, __data__)
#define __pu_repeat_impl1(__macro__, __data__) __macro__ (0, __data__)
#define __pu_repeat_impl2(__macro__, __data__) __macro__ (0, __data__), __macro__ (1, __data__)
#define __pu_repeat_impl3(__macro__, __data__) __macro__ (0, __data__), __macro__ (1, __data__), __macro__ (2, __data__)
#define __pu_repeat_impl4(__macro__, __data__) __macro__ (0, __data__), __macro__ (1, __data__), __macro__ (2, __data__), __macro__ (3, __data__)
#define __pu_repeat_impl5(__macro__, __data__) __macro__ (0, __data__), __macro__ (1, __data__), __macro__ (2, __data__), __macro__ (3, __data__), __macro__ (4, __data__)
#define __pu_repeat_impl6(__macro__, __data__) __macro__ (0, __data__), __macro__ (1, __data__), __macro__ (2, __data__), __macro__ (3, __data__), __macro__ (4, __data__), __macro__ (5, __data__)
#define __pu_repeat_impl7(__macro__, __data__) __macro__ (0, __data__), __macro__ (1, __data__), __macro__ (2, __data__), __macro__ (3, __data__), __macro__ (4, __data__), __macro__ (5, __data__), __macro__ (6, __data__)

#define __pu_repeat(__count__, __macro__, __data__) __pu_concat (__pu_repeat_impl, __count__) (__macro__, __data__)


#define __arg_invoke(__n__, __data__) _##__n__

#define func(__type__, __ret__, __func__, ...) static inline __ret__ __func__ (__VA_ARGS__) noexcept \
{ return __concat (dec, __type__, __func__) ( __pu_repeat (__pu_va_args_count (__VA_ARGS__), __arg_invoke, ) ); }

#undef gen_cpp_wrappers
#endif // gen_cpp_wrappers


#ifndef func
  #error undefined expansion type
#else 

// Utilities and conversions, extractors, etc.)
func (dectype, void*,		FromBCD,			void* _0, int32_t _1, const uint8_t* _2, int32_t _3)
func (dectype, void*,		FromInt32,			void* _0, int32_t _1)
func (dectype, void*,		FromPacked,			void* _0, int32_t _1, const uint8_t* _2)
func (dectype, void*,		FromPackedChecked,	void* _0, int32_t _1, const uint8_t* _2)
func (dectype, void*,		FromString,			void* _0, const char* _1, void* _2)
func (dectype, void*,		FromUInt32,			void* _0, uint32_t _1)
func (dectype, void*,		FromWider,			void* _0, const void* _1, void* _2)
func (dectype, int32_t,		GetCoefficient,		const void* _0, uint8_t* _1)
func (dectype, int32_t,		GetExponent,		const void* _0)
func (dectype, void*,		SetCoefficient,		void* _0, const uint8_t* _1, int32_t _2)
func (dectype, void*,		SetExponent,		void* _0, void* _1, int32_t _2)
func (dectype, void,		Show,				const void* _0, const char* _1)
func (dectype, int32_t,		ToBCD,				const void* _0, int32_t* _1, uint8_t* _2)
func (dectype, char*,		ToEngString,		const void* _0, char* _1)
func (dectype, int32_t,		ToInt32,			const void* _0, void* _1, int32_t _2)
func (dectype, int32_t,		ToInt32Exact,		const void* _0, void* _1, int32_t _2)
func (dectype, int32_t,		ToPacked,			const void* _0, int32_t* _1, uint8_t* _2)
func (dectype, char*,		ToString,			const void* _0, char* _1)
func (dectype, uint32_t,	ToUInt32,			const void* _0, void* _1, int32_t _2)
func (dectype, uint32_t,	ToUInt32Exact,		const void* _0, void* _1, int32_t _2)
func (dectype, void*,		ToWider,			const void* _0, void* _1)
func (dectype, void*,		Zero,				void* _0)

// decnumberxx extensions
func (dectype, void*,		FromExpSignedCoef,	void* _0, int64_t _1, int32_t _2)
func (dectype, void*,		FromExpUnsignedCoef,void* _0, uint64_t _1, int32_t _2)


// Computational (result is a decDouble)
func (dectype, void*, Abs,				void* _0, const void* _1, void* _2)
func (dectype, void*, Add,				void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, And,				void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Divide,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, DivideInteger,	void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, FMA,				void* _0, const void* _1, const void* _2, const void* _3, void* _4)
func (dectype, void*, Invert,			void* _0, const void* _1, void* _2)
func (dectype, void*, LogB, 			void* _0, const void* _1, void* _2)
func (dectype, void*, Max,				void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, MaxMag,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Min,				void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, MinMag,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Minus,			void* _0, const void* _1, void* _2)
func (dectype, void*, Multiply,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, NextMinus,		void* _0, const void* _1, void* _2)
func (dectype, void*, NextPlus,			void* _0, const void* _1, void* _2)
func (dectype, void*, NextToward,		void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Or,				void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Plus,				void* _0, const void* _1, void* _2)
func (dectype, void*, Quantize,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Reduce,			void* _0, const void* _1, void* _2)
func (dectype, void*, Remainder,		void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, RemainderNear,	void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Rotate,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, ScaleB,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Shift,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, Subtract,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, ToIntegralValue,	void* _0, const void* _1, void* _2, int32_t _3)
func (dectype, void*, ToIntegralExact,	void* _0, const void* _1, void* _2)
func (dectype, void*, Xor,				void* _0, const void* _1, const void* _2, void* _3)

// decnumberxx extensions - done by converting to decNumber and back
func (dectype, void*, Exp,				void* _0, const void* _1, void* _2)
func (dectype, void*, Ln,				void* _0, const void* _1, void* _2)
func (dectype, void*, Log10,			void* _0, const void* _1, void* _2)
func (dectype, void*, Power,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, SquareRoot,		void* _0, const void* _1, void* _2)


// Comparisons
func (dectype, void*, Compare,			void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, CompareSignal,	void* _0, const void* _1, const void* _2, void* _3)
func (dectype, void*, CompareTotal,		void* _0, const void* _1, const void* _2)
func (dectype, void*, CompareTotalMag,	void* _0, const void* _1, const void* _2)

// Copies
func (dectype, void*, Canonical,	void* _0, const void* _1)
func (dectype, void*, Copy,			void* _0, const void* _1)
func (dectype, void*, CopyAbs,		void* _0, const void* _1)
func (dectype, void*, CopyNegate,	void* _0, const void* _1)
func (dectype, void*, CopySign,		void* _0, const void* _1, const void* _2)

// Non-computational
func (dectype, int32_t,		Class,			const void* _0)
func (dectype, const char*, ClassString,	const void* _0)
func (dectype, uint32_t,	Digits,			const void* _0)
func (dectype, uint32_t,	IsCanonical,	const void* _0)
func (dectype, uint32_t,	IsFinite,		const void* _0)
func (dectype, uint32_t,	IsInfinite,		const void* _0)
func (dectype, uint32_t,	IsInteger,		const void* _0)
func (dectype, uint32_t,	IsLogical,		const void* _0)
func (dectype, uint32_t,	IsNaN,			const void* _0)
func (dectype, uint32_t,	IsNegative,		const void* _0)
func (dectype, uint32_t,	IsNormal,		const void* _0)
func (dectype, uint32_t,	IsPositive,		const void* _0)
func (dectype, uint32_t,	IsSignaling,	const void* _0)
func (dectype, uint32_t,	IsSigned,		const void* _0)
func (dectype, uint32_t,	IsSubnormal,	const void* _0)
func (dectype, uint32_t,	IsZero,			const void* _0)
func (dectype, uint32_t,	Radix,			const void* _0)
func (dectype, uint32_t,	SameQuantum,	const void* _0)



#undef func
#endif // func check

#undef dectype
#undef decarg
#endif // dectype check

#ifdef dectype
#endif

#ifdef __concat
#undef __concat
#endif 

