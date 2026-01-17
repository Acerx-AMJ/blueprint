#include "utils/bignum.hpp"
#include <cstring>

// Constructors

BigInt::BigInt(size_t size) {
   digits.resize(size);
}

BigInt::BigInt(const std::string &copy) {
   size_t size = copy.size();
   digits.resize(size);

   for (size_t i = 0; i < size; ++i)
      digits[i] = copy[size - i - 1];
}

BigInt::BigInt(const char *copy) {
   size_t size = strlen(copy);
   digits.resize(size);

   for (size_t i = 0; i < size; ++i)
      digits[i] = copy[size - i - 1];
}

// Arithmetic operators

BigInt BigInt::operator + (const BigInt &other) const {
   const size_t size1 = digits.size();
   const size_t size2 = other.digits.size();
   const size_t size  = (size1 > size2 ? size1 : size2);
   
   BigInt result (size + 1);
   char carry = 0;

   for (size_t i = 0; i < size; ++i) {
      const char value1 = (i < size1 ? digits[i] - '0' : 0);
      const char value2 = (i < size2 ? other.digits[i] - '0' : 0);
      const char total  = value1 + value2 + carry;

      carry = (total > 9);
      result.digits[i] = (total - carry * 10) + '0';
   }

   if (carry)
      result.digits.push_back('1');
   return result;
}

// Conversion functions

std::ostream &operator << (std::ostream &stream, const BigInt &bigint) {
   for (auto it = bigint.digits.rbegin(); it != bigint.digits.rend(); ++it)
      putchar(*it);
   return stream;
}
