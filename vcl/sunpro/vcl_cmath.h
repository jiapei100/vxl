#ifndef vcl_sunpro_cmath_h_
#define vcl_sunpro_cmath_h_

// include system header
#include "../iso/vcl_cmath.h"

//fix system header.
#if defined(VCL_SUNPRO_CC_50)
//Conflicts with <cstdio>:
// # include <math.h> // for the HUGE_VAL macro.
# undef M_PI_4     // avoid redef. it's non-iso anyway.
#endif

#undef  vcl_abs
#define vcl_abs vcl_abs
inline int    vcl_abs(int    x) { return x >= 0    ? x : -x; }
inline long   vcl_abs(long   x) { return x >= 0L   ? x : -x; }
inline float  vcl_abs(float  x) { return x >= 0.0f ? x : -x; }
inline double vcl_abs(double x) { return x >= 0.0  ? x : -x; }

#endif // vcl_cmath_h_
