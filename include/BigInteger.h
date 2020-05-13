#ifndef __BIG_INTEGER__
#define __BIG_INTEGER__

#include <vector>
#include <string>
#include <cstdint>

namespace bignumber
{

#include <vector>
#include <string>

constexpr auto INTERVAL = '0'-0;

class BigInteger
{
public:
  using Self = BigInteger;
private:
  std::vector<char> num;
  bool sign = true; //부호비트
private:
  template <class Integer>
  BigInteger(Integer n, nullptr_t _)
  {
    std::string s;
    
    if(n<0)
    {
      sign = false;
      s = std::to_string(-n);
    }
    else
    {
      sign = true;
      s = std::to_string(n);
    }
    
    for(auto it = s.rbegin(); it!=s.rend(); it++)
    {
      num.push_back(*it - INTERVAL);
    }
  }
public:
  BigInteger(signed char n);
  BigInteger(short n);
  BigInteger(int n);
  BigInteger(long n);
  BigInteger(long long n);
  BigInteger(unsigned char n);
  BigInteger(unsigned short n);
  BigInteger(unsigned int n);
  BigInteger(unsigned long n);
  BigInteger(unsigned long long n);
  BigInteger(const std::string& n);
  
public:
  
public:
  BigInteger();
  virtual ~BigInteger() = default;
public:
  BigInteger(const BigInteger&) = default;
  BigInteger& operator=(const BigInteger&) = default;
  BigInteger(BigInteger&&) = default;
  BigInteger& operator=(BigInteger&&) = default;
public: //이항산술연산자
  friend BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs);
  friend BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs);
  friend BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs);
  friend BigInteger operator/(const BigInteger& lhs, const BigInteger& rhs);
  friend BigInteger operator%(const BigInteger& lhs, const BigInteger& rhs);
public:
  friend BigInteger& operator+=(const BigInteger& lhs, const BigInteger& rhs);
  friend BigInteger& operator-=(const BigInteger& lhs, const BigInteger& rhs);
  friend BigInteger& operator*=(const BigInteger& lhs, const BigInteger& rhs);
  friend BigInteger& operator/=(const BigInteger& lhs, const BigInteger& rhs);
  friend BigInteger& operator%=(const BigInteger& lhs, const BigInteger& rhs);
public: //단항연산자
  BigInteger& operator++();
  BigInteger operator++(int);
  BigInteger operator+() const;
  BigInteger& operator--();
  BigInteger operator--(int);
  BigInteger operator-() const;
public: //비교연산자
  friend bool operator<(const BigInteger& lhs, const BigInteger& rhs);
  friend bool operator>(const BigInteger& lhs, const BigInteger& rhs);
  friend bool operator<=(const BigInteger& lhs, const BigInteger& rhs);
  friend bool operator>=(const BigInteger& lhs, const BigInteger& rhs);
  friend bool operator==(const BigInteger& lhs, const BigInteger& rhs);
  friend bool operator!=(const BigInteger& lhs, const BigInteger& rhs);
  
public:
  bool is_zero() const noexcept;
  bool is_odd() const noexcept;
  bool is_even() const noexcept;
  bool is_negative() const noexcept;
  bool is_positive() const noexcept;
  std::string to_string() const;

public:
  operator int8_t() const;
  operator int16_t() const;
  operator int32_t() const;
  operator int64_t() const;
  operator uint8_t() const;
  operator uint16_t() const;
  operator uint32_t() const;
  operator uint64_t() const;
  operator std::string() const;
};

BigInteger operator ""bi(unsigned long long n);

#include <ostream>
std::ostream& operator<<(std::ostream& os, const BigInteger& n);

#include <istream>
std::istream& operator>>(std::istream& is, BigInteger& n);


}

#endif
