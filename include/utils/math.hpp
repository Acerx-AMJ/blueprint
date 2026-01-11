#ifndef UTIL_MATH_HPP
#define UTIL_MATH_HPP

#include <cstdlib>
#include <vector>

// Math utility

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

// Random functions

inline int random(int min, int max) {
   return min + (rand() % (max - min + 1));
}

inline float random(float min, float max) {
   return min + (float)rand() / float(RAND_MAX / (max - min));
}

inline bool chance(int percent) {
   return random(0, 100) <= percent;
}

// Random vector access functions

template<class T>
inline T& random(std::vector<T> &vector) {
   return vector[random(0, vector.size() - 1)];
}

template<class T>
inline const T& random(const std::vector<T> &vector) {
   return vector.at(random(0, vector.size() - 1));
}

template<class T>
inline T& random(std::vector<T> &&vector) {
   return vector[random(0, vector.size() - 1)];
}

#endif
