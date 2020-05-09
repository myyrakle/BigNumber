#ifndef __BIG_INTEGER__
#define __BIG_INTEGER__

#include <vector>

constexpr int INTERVAL = '0'-0;

class BigInteger
{
public:
  using Self = BigInteger;
private:
  std::vector<char> num;
  bool sign; //부호비트
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
  BigInteger(signed char n): BigInteger(n, nullptr)
  {}
  BigInteger(short n): BigInteger(n, nullptr)
  {}
  BigInteger(int n): BigInteger(n, nullptr)
  {}
  BigInteger(long n): BigInteger(n, nullptr)
  {}
  BigInteger(long long n): BigInteger(n, nullptr)
  {}
  BigInteger(unsigned char n): BigInteger(n, nullptr)
  {}
  BigInteger(unsigned short n): BigInteger(n, nullptr)
  {}
  BigInteger(unsigned int n): BigInteger(n, nullptr)
  {}
  BigInteger(unsigned long n): BigInteger(n, nullptr)
  {}
  BigInteger(unsigned long long n): BigInteger(n, nullptr)
  {}
public:
  BigInteger()
  {
    num.push_back(0);
  }
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
  std::string to_string() const
  {
    std::string s;
    if(!sign)
    {
      s.push_back('-');
    }
    
    for(auto it = num.rbegin(); it!=num.rend(); it++)
    {
      s.push_back(*it+INTERVAL);
    }
    
    return s;
  }
};

BigInteger operator ""bi(unsigned long long n);

#endif
