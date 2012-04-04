<html><head><title>decnumberxx</title></head><body>
<div>
  <style type="text/css">
    .na { background-color: #FFCCCC }
    .partial { background-color: #F0F0A0 }
    .ok { background-color: #A0FFA0 }
    th { background-color: #D0D0D0 }
	h4 { color: #D00000 }
  </style>
</div>

<div>
<h1>decnumberxx</h1>

This is a partial implementation of the C++ standards draft <a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2009/n2849.pdf">N2849</a>.
It adds the <code>decimal32</code>, <code>decimal64</code> and <code>decimal128</code> types which can be used as drop-in replacements for
fundamental types such as <code>float</code> or <code>double</code>.
<br><br>
This implementation is based on the <code>decNumber</code> library and is licensed under a 4 clause BSD license, except for the <code>decNumber</code> library,
which has its own <a href="decNumber/ICU-license.html">license</a>.


<p>
<h4><i><u>Notice 0</u></i></h4>
This requires a C++11 supporting compiler and STL.<br>
On iOS and OSX it is recommended to use a more recent version of libcxx than is shipped with OSX 10.7 and iOS 5.0.
</p>

<p>
<h4><i><u>Notice 1</u></i></h4>
The standards draft has not been finalized yet and this implementation deviates from the draft in some aspects.<br>
For more details check the implementation status table below.
</p>

<p>
<h4><i><u>Notice 2</u></i></h4>
All additions to the various related standard headers are included in the single header <code>decimal</code> in this implementation.
Thus, when including this implementation's <code>decimal</code> header, it will pull in also various other standard headers.
</p>

<p>
<h4><i><u>Notice 3</u></i></h4>
The <code>decimal32</code> type is actually only meant to be used for storage.  In this implementation, it is also possible
to carry out arithmetic operations on it. However, internally the <code>decimal32</code> arguments are converted to e.g. <code>decimal64</code>
or some other internal representation such as <code>decNumber</code> in order to carry out the operations.  After the operation the return value
is then converted to <code>decimal32</code>. This works, but is slow.
</p>

</div>

<div>
<h2>Implementation status</h2>

<table border="1" cellspacing="0" cellpadding="4">

    <tr>
      <td align="center"><i>Function Description</></td>
	  <td align="center" width="100"><i>N2849 Section</i></td>
      <td align="center" width="100"><i>Status</i></td>
	  <td align="center"><i>Remarks</i></td>
    </tr>

    <tr class="separator">
      <th align="center" colspan="4">2.4 Namespaces and headers</th>
    </tr>

    <tr>
      <td><code>std::decimal::</code></td>
	  <td align="center" width="100"></td>
      <td class="ok" align="center" width="100">OK</td>
	  <td></td>
    </tr>


    <tr class="separator">
      <th align="center" colspan="4">3.2 Decimal Types</th>
    </tr>

    <tr>
      <td><code>decimal32</code></td>
	  <td align="center" width="100">3.2.2</td>
      <td class="ok" align="center" width="100">OK</td>
	  <td></td>
    </tr>
    <tr>
      <td><code>decimal64</code></td>
	  <td align="center">3.2.3</td>
      <td class="ok" align="center">OK</td>
	  <td></td>
    </tr>
    <tr>
      <td><code>decimal128</code></td>
	  <td align="center">3.2.4</td>
      <td class="ok" align="center">OK</td>
	  <td></td>
    </tr>
    <tr>
      <td>Initialization from coefficient and exponent</td>
	  <td align="center">3.2.5</td>
      <td class="na" align="center">N/A</td>
	  <td></td>
    </tr>
    <tr>
      <td>Conversion to generic floating-point type</td>
	  <td align="center">3.2.6</td>
      <td class="ok" align="center">OK</td>
	  <td>Uses C++11 explicit conversion operators. <code>is_iec559</code> is ignored.</td>
    </tr>
    <tr>
      <td>Unary arithmetic operators</td>
	  <td align="center">3.2.7</td>
      <td class="ok" align="center">OK</td>
	  <td></td>
    </tr>
    <tr>
      <td>Binary arithmetic operators with implicit promotions</td>
	  <td align="center">3.2.8</td>
      <td class="ok" align="center">OK</td>
	  <td></td>
    </tr>
    <tr>
      <td>Comparison operators with implicit promotions</td>
	  <td align="center">3.2.9</td>
      <td class="ok" align="center">OK</td>
	  <td></td>
    </tr>
    <tr>
      <td>Formatted input</td>
	  <td align="center">3.2.10</td>
      <td class="na" align="center">N/A</td>
	  <td>Class stubs only.  No implementation.</td>
    </tr>
    <tr>
      <td>Formatted output</td>
	  <td align="center">3.2.11</td>
      <td class="partial" align="center">Partial</td>
	  <td>Class stubs only.  <code>operator &lt;&lt; </code> implemented without locale support.</td>
    </tr>


    <tr class="separator">
      <th align="center" colspan="4">3.3 Additions to <code> &lt;limits&gt;</code></th>
    </tr>
	<tr>
	  <td><code>numeric_limits&lt;decimal::decimal32&gt;</code></td>
	  <td align="center"></td>
	  <td class="ok" align="center">OK</td>
	  <td><code>min_exponent = -95</code>; <code>max_exponent = 96</code><br>
	  		As defined by <a href="http://en.wikipedia.org/wiki/IEEE_754#Basic_formats">IEEE 754</a>.</td>
	</tr>
	<tr>
	  <td><code>numeric_limits&lt;decimal::decimal64&gt;</code></td>
	  <td align="center"></td>
	  <td class="ok" align="center">OK</td>
	  <td><code>min_exponent = -383</code>; <code>max_exponent = 384</code><br>
	  		As defined by <a href="http://en.wikipedia.org/wiki/IEEE_754#Basic_formats">IEEE 754</a>.</td>
	</tr>
	<tr>
	  <td><code>numeric_limits&lt;decimal::decimal128&gt;</code></td>
	  <td align="center"></td>
	  <td class="ok" align="center">OK</td>
	  <td><code>min_exponent = -6143</code>; <code>max_exponent = 6144</code><br>
	  		As defined by <a href="http://en.wikipedia.org/wiki/IEEE_754#Basic_formats">IEEE 754</a>.</td>
	</tr>

    <tr class="separator">
      <th align="center" colspan="4">3.4 Additions to <code>&lt;cfloat&gt;</code> and <code>&lt;float.h&gt;</code></th>
    </tr>
	
	<tr>
	  <td>
	    <code>#define DEC32_MANT_DIG</code><br>
	  	<code>#define DEC64_MANT_DIG</code><br>
	  	<code>#define DEC128_MANT_DIG</code>
	  </td>
	  <td align="center">3.4.1</td>
	  <td class="na" align="center">N/A</td>
	  <td><code>numeric_limits</code> only.</td>
	</tr>

	<tr>
	  <td>
	    <code>#define DEC32_MIN_EXP</code><br>
	    <code>#define DEC64_MIN_EXP</code><br>
	    <code>#define DEC128_MIN_EXP</code>
	  </td>
	  <td align="center">3.4.1</td>
	  <td class="na" align="center">N/A</td>
	  <td><code>numeric_limits</code> only.</td>
	</tr>

	<tr>
	  <td>
	    <code>#define DEC32_MAX_EXP</code><br>
	    <code>#define DEC64_MAX_EXP</code><br>
	    <code>#define DEC128_MAX_EXP</code>
	  </td>
	  <td align="center">3.4.1</td>
	  <td class="na" align="center">N/A</td>
	  <td><code>numeric_limits</code> only.</td>
	</tr>

	<tr>
	  <td>
	    <code>_Decimal32</code> typedef<br>
	    <code>_Decimal64</code> typedef<br>
	    <code>_Decimal128</code> typedef
	  </td>
	  <td align="center">3.4.2</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>

	<tr>
	  <td>
	    <code>#define DEC32_MAX</code><br>
		<code>#define DEC64_MAX</code><br>
		<code>#define DEC128_MAX</code>
	  </td>		  
	  <td align="center">3.4.3</td>
	  <td class="na" align="center">N/A</td>
	  <td><code>numeric_limits</code> only.</td>
	</tr>

	<tr>
	  <td>
	    <code>#define DEC32_EPSILON</code><br>
	    <code>#define DEC64_EPSILON</code><br>
	    <code>#define DEC128_EPSILON</code>
	  </td>
	  <td align="center">3.4.4</td>
	  <td class="na" align="center">N/A</td>
	  <td><code>numeric_limits</code> only.</td>
	</tr>

	<tr>
	  <td>
	    <code>#define DEC32_MIN</code><br>
	    <code>#define DEC64_MIN</code><br>
	    <code>#define DEC128_MIN</code>
	  </td>
	  <td align="center">3.4.5</td>
	  <td class="na" align="center">N/A</td>
	  <td><code>numeric_limits</code> only.</td>
	</tr>

	<tr>
	  <td>
	    <code>#define DEC32_SUBNORMAL</code><br>
	    <code>#define DEC64_SUBNORMAL</code><br>
	    <code>#define DEC128_SUBNORMAL</code>
	  </td>
	  <td align="center">3.4.6</td>
	  <td class="na" align="center">N/A</td>
	  <td><code>numeric_limits</code> only.</td>
	</tr>

	<tr>
	  <td><code>#define DEC_EVAL_METHOD</code></td>
	  <td align="center">3.4.7</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>


    <tr class="separator">
      <th align="center" colspan="4">3.5 Additions to <code>&lt;cfenv&gt;</code> and <code>&lt;fenv.h&gt;</code></th>
    </tr>

	<tr>
	  <td><code>#define FE_DEC_DOWNWARD</code></td>
	  <td align="center">3.5.2</td>
	  <td class="ok" align="center">OK</td>
	  <td></td>
	</tr>
	<tr>
	  <td><code>#define FE_DEC_TONEAREST</code></td>
	  <td align="center">3.5.2</td>
	  <td class="ok" align="center">OK</td>
	  <td></td>
	</tr>
	<tr>
	  <td><code>#define FE_DEC_TONEARESTFROMZERO</code></td>
	  <td align="center">3.5.2</td>
	  <td class="na" align="center">N/A</td>
	  <td>Not supported by decNumber library</td>
	</tr>
	<tr>
	  <td><code>#define FE_DEC_TOWARD_ZERO</code></td>
	  <td align="center">3.5.2</td>
	  <td class="ok" align="center">OK</td>
	  <td></td>
	</tr>
	<tr>
	  <td><code>#define FE_DEC_UPWARD</code></td>
	  <td align="center">3.5.2</td>
	  <td class="ok" align="center">OK</td>
	  <td></td>
	</tr>

	<tr>
	  <td><code>fe_dec_getround</code> function</td>
	  <td align="center">3.5.3</td>
	  <td class="na" align="center">N/A</td>
	  <td>Requires thread local decNumber context storage.  Rounding mode is fixed to <code>FE_DEC_TONEAREST</code>.</td>
	</tr>
	<tr>
	  <td><code>fe_dec_setround</code> function</td>
	  <td align="center">3.5.4</td>
	  <td class="na" align="center">N/A</td>
	  <td>Requires thread local decNumber context storage.  Rounding mode is fixed to <code>FE_DEC_TONEAREST</code>.</td>
	</tr>

    <tr class="separator">
      <th align="center" colspan="4">3.6 Additions to <code>&lt;cmath&gt;</code></th>
    </tr>

	<tr>
	  <td>
	    <code>#define HUGE_VAL_D32</code><br>
	    <code>#define HUGE_VAL_D64</code><br>
	    <code>#define HUGE_VAL_D128</code><br>
	    <code>#define DEC_INFINITY</code><br>
	    <code>#define DEC_NAN</code><br>
	    <code>#define FP_FAST_FMAD32</code><br>
	    <code>#define FP_FAST_FMAD64</code><br>
	    <code>#define FP_FAST_FMAD128</code>
	  </td>
	  <td align="center">3.6.2</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>

	<tr>
	  <td><code>decimal32_t</code></td>
	  <td align="center">3.6.3</td>
	  <td class="ok" align="center">OK</td>
	  <td>Same as <code>std::decimal::decimal32</code></td>
	</tr>

	<tr>
	  <td><code>decimal64_t</code></td>
	  <td align="center">3.6.3</td>
	  <td class="ok" align="center">OK</td>
	  <td>Same as <code>std::decimal::decimal64</code></td>
	</tr>

	<tr>
	  <td><code>decimal128_t</code></td>
	  <td align="center">3.6.3</td>
	  <td class="ok" align="center">OK</td>
	  <td>Same as <code>std::decimal::decimal128</code></td>
	</tr>

	<tr>
	  <td>
	    <code>samequantumd32</code><br>
	    <code>samequantumd64</code><br>
	    <code>samequantumd128</code>
	  </td>
	  <td align="center">3.6.4</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>

	<tr>
	  <td>
	    <code>quantexpd32</code><br>
	    <code>quantexpd64</code><br>
	    <code>quantexpd128</code>
	  </td>
	  <td align="center">3.6.5</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>

	<tr>
	  <td>
	    <code>quantized32</code><br>
	    <code>quantized64</code><br>
	    <code>quantized128</code>
	  </td>
	  <td align="center">3.6.6</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>

	<tr>
	  <td><code>acos</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>asin</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>atan</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>atan2</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>ceil</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>cos</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>cosh</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>fabs</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>floor</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>fmod</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>frexp</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>ldexp</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>log</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>log10</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>modf</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>pow</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>sin</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>sinh</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>sqrt</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>tan</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>tanh</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>acosh</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>asinh</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>atanh</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>cbrt</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>copysign</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>erf</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>erfc</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>  <td></td>
	</tr>
	<tr>
	  <td><code>exp</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>exp2</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td>Inexact</td>
	</tr>
	<tr>
	  <td><code>expm1</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td>Inexact</td>
	</tr>
	<tr>
	  <td><code>fdim</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td>Inexact</td>
	</tr>
	<tr>
	  <td><code>fma</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>fmax</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>fmin</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>  <td></td>
	</tr>
	<tr>
	  <td><code>hypot</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Inexact</td>
	</tr>
	<tr>
	  <td><code>ilogb</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td></td>
	</tr>
	<tr>
	  <td><code>lgamma</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td>Inexact</td>
	</tr>
	<tr>
	  <td><code>llrint</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Uses <code>nearbyint</code></td>
	</tr>
	<tr>
	  <td><code>llround</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Uses <code>round</code></td>
	</tr>
	<tr>
	  <td><code>lrint</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Uses <code>nearbyint</code></td>
	</tr>
	<tr>
	  <td><code>lround</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Uses <code>round</code></td>
	</tr>
	<tr>
	  <td><code>log1p</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Inexact</td>
	</tr>
	<tr>
	  <td><code>log2</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td>Inexact</td>
	</tr>
	<tr>
	  <td><code>logb</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td></td>
	</tr>
	<tr>
	  <td><code>nan</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td></td>
	</tr>
	<tr>
	  <td><code>nearbyint</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Changing the current rounding mode is not supported.</td>
	</tr>
	<tr>
	  <td><code>nextafter</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Same as <code>nexttoward</code></td>
	</tr>
	<tr>
	  <td><code>nexttoward</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td></td>
	</tr>
	<tr>
	  <td><code>remainder</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td></td>
	</tr>
	<tr>
	  <td><code>remquo</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td></td>
	</tr>
	<tr>
	  <td><code>rint</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td>Uses <code>nearbyint</code></td>
	</tr>
	<tr>
	  <td><code>round</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td></td>
	</tr>
	<tr>
	  <td><code>scalbn</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td></td>
	</tr>
	<tr>
	  <td><code>scalbln</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td></td>
	</tr>
	<tr>
	  <td><code>tgamma</code></td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td></td>
	</tr>
	<tr>
	  <td><code>trunc</code></td>	  <td align="center">3.6.7</td>	  <td class="ok" align="center">OK</td>	<td></td>
	</tr>

	<tr>
	  <td><code><i>func</i>d32</code> variants</td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td></td>
	</tr>
	<tr>
	  <td><code><i>func</i>d64</code> variants</td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td></td>
	</tr>
	<tr>
	  <td><code><i>func</i>d128</code> variants</td>	  <td align="center">3.6.7</td>	  <td class="na" align="center">N/A</td>	<td></td>
	</tr>
	<tr>
	  <td><code>abs</code> overloads</td>	  <td align="center">3.6.7.1</td>	  <td class="ok" align="center">OK</td>	<td></td>
	</tr>

	<tr>
	  <td>
	    <code>#define _Decimal32_t</code><br>
	    <code>#define _Decimal64_t</code><br>
	    <code>#define _Decimal128_t</code>
	  </td>
	  <td align="center">3.6.8.1</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>


    <tr class="separator">
      <th align="center" colspan="4">3.7 Additions to <code>&lt;cstdio&gt;</code> and <code>&lt;stdio.h&gt;</code></th>
    </tr>

	<tr>
	  <td><code>H</code> specifier</td>
	  <td align="center"></td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>
	<tr>
	  <td><code>D</code> specifier</td>
	  <td align="center"></td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>
	<tr>
	  <td><code>DD</code> specifier</td>
	  <td align="center"></td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>


    <tr class="separator">
      <th align="center" colspan="4">3.8 Additions to <code>&lt;cstdlib&gt;</code> and <code>&lt;stdlib.h&gt;</code></th>
    </tr>

	<tr>
	  <td>
	    <code>strtod32</code><br>
	    <code>strtod64</code><br>
	    <code>strtod128</code>
	  </td>
	  <td align="center">3.8.2</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>


    <tr class="separator">
      <th align="center" colspan="4">3.9 Additions to <code>&lt;cwchar&gt;</code> and <code>&lt;wchar.h&gt;</code></th>
    </tr>

	<tr>
	  <td>
	    <code>wcstod32</code><br>
	    <code>wcstod64</code><br>
	    <code>wcstod128</code>
	  </td>
	  <td align="center">3.9.2</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>


    <tr class="separator">
      <th align="center" colspan="4">3.10 Facets</th>
    </tr>

	<tr>
	  <td>Class template <code>extended_num_get</code></td>
	  <td align="center">3.10.2</td>
	  <td class="na" align="center">N/A</td>
	  <td>Stubs only. No implementation.</td>
	</tr>
	<tr>
	  <td>Class template <code>extended_num_put</code></td>
	  <td align="center">3.10.3</td>
	  <td class="na" align="center">N/A</td>
	  <td>Stubs only. No implementation.</td>
	</tr>


    <tr class="separator">
      <th align="center" colspan="4">3.11 Type traits</th>
    </tr>

	<tr>
	  <td><code>std::is_scalar</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_compound</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_integral</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>false_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_floating_point</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_fundamental</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>false_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_arithmetic</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_pod</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_trivial</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_trivially_copyable</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_class</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_signed</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>true_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_unsigned</code></td>	<td align="center"></td>	<td class="ok" align="center">OK</td>	<td>Evaluates to <code>false_type</code></td>
	</tr>
	<tr>
	  <td><code>std::is_decimal_floating_point</code></td>	<td align="center">3.11.2</td>	<td class="na" align="center">N/A</td>	<td>Requires modification of <code>&lt;type_traits&gt;</code>.</td>
	</tr>

    <tr class="separator">
      <th align="center" colspan="4">3.12 Hash functions</th>
    </tr>

	<tr>
	  <td>
	    <code><code>template&lt;&gt; struct hash&lt;decimal::decimal32&gt;</code><br>
	    <code><code>template&lt;&gt; struct hash&lt;decimal::decimal64&gt;</code><br>
	    <code><code>template&lt;&gt; struct hash&lt;decimal::decimal128&gt;</code>
	  </td>
	  <td align="center">3.12.2</td>
	  <td class="na" align="center">N/A</td>
	  <td></td>
	</tr>

    <tr class="separator">
      <th align="center" colspan="4">4.1 Literals</th>
    </tr>
	<tr>
	  <td>Decimal floating point literals with <code>DF</code> suffix.</td>
	  <td align="center"></td>
	  <td class="na" align="center">N/A</td>
	  <td>Requires C++11 user defined literals.</td>
	</tr>


    <tr class="separator">
      <th align="center" colspan="4">4.2 Conversions</th>
    </tr>

	<tr>
	  <td>
	    <code><code>decimal_to_float</code><br>
	    <code><code>decimal_to_double</code><br>
	    <code><code>decimal_to_long_double</code><br>
	    <code><code>decimal32_to_float</code><br>
	    <code><code>decimal32_to_double</code><br>
	    <code><code>decimal32_to_long_double</code><br>
	    <code><code>decimal64_to_float</code><br>
	    <code><code>decimal64_to_double</code><br>
	    <code><code>decimal64_to_long_double</code><br>
	    <code><code>decimal128_to_float</code><br>
	    <code><code>decimal128_to_double</code><br>
	    <code><code>decimal128_to_long_double</code><br>
	  </td>
	  <td align="center"></td>
	  <td class="na" align="center">N/A</td>
	  <td>Implemented via C++11 explicit conversion operators, which makes these functions obsolete for C++. See 3.2.6.</td>
	</tr>

</table>
</div>
</body>
</html>