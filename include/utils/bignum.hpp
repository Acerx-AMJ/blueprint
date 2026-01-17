#ifndef UTILS_BIGNUM_HPP
#define UTILS_BIGNUM_HPP

#include <string>

struct BigInt {
   // Constructors

   BigInt() = default;
   BigInt(size_t size);
   BigInt(const std::string &copy);
   BigInt(const char *copy);

   ~BigInt() = default;

   // Arithmetic operators

   [[nodiscard]] BigInt operator + (const BigInt &other) const;

   // Members

   std::string digits;
};
std::ostream &operator << (std::ostream &stream, const BigInt &bigint);

#endif
