#ifndef UTIL_MATH_HPP
#define UTIL_MATH_HPP

template<typename T>
constexpr inline T min(T a, T b) {
   return (a > b ? b : a);
}

template<typename T>
constexpr inline T max(T a, T b) {
   return (a > b ? a : b);
}

template<typename T>
constexpr inline T clamp(T v, T lo, T hi) {
   return (v < lo ? lo : (v > hi ? hi : v));
}

template<typename T>
constexpr inline T abs(T a) {
   return (a < 0 ? -a : a);
}

constexpr inline float lerp(float a, float b, float t) {
   return a + (b - a) * t;
}

#endif
