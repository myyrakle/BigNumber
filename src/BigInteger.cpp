#include "./../include/BigInteger.h"
#include <utility>

namespace bignumber
{

  BigInteger::BigInteger(signed char n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(short n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(int n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(long n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(long long n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(unsigned char n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(unsigned short n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(unsigned int n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(unsigned long n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(unsigned long long n): BigInteger(n, nullptr)
  {}
  BigInteger::BigInteger(const std::string& n): BigInteger(std::stoi(n))
  {}

  BigInteger::BigInteger()
  {
    num.push_back(0);
  }


  std::ostream& operator<<(std::ostream& os, const BigInteger& n)
  {
    os << n.to_string();
    return os;
  }

  std::istream& operator>>(std::istream& is, BigInteger& n)
  {
    std::string buffer;
    is>>buffer;
    //TODO
    return is;
  }

  std::string BigInteger::to_string() const
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

  //이항 사칙연산자
  BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs)
  {
    if(lhs.sign==rhs.sign)
    {
      BigInteger n;
      n.num.clear();
      
      int carry = 0;
      
      for(int i = 0; i<lhs.num.size() || i<rhs.num.size(); i++)
      {
        int l;
        int r;
        
        if(i>=lhs.num.size())
        {
          l = 0;
          r = rhs.num[i];
        }
        else if(i>=rhs.num.size())
        {
          l = lhs.num[i];
          r = 0;
        }
        else
        {
          l = lhs.num[i];
          r = rhs.num[i];
        }
        
        int sum = l+r+carry;
        //cout<<"l:"<<l<<", r:"<<r<<endl;
        //cout<<"sum:"<<sum<<endl;
        carry = 0;
        if(sum>9)
        {
          sum-=10;
          carry=1;
        }
        
        n.num.push_back(sum);
      }
      
      if(carry>0)
      {
        n.num.push_back(carry);
      }
      
      return n;
    }
    else if(lhs.sign)
    {
      return lhs-rhs;
    }
    else if(rhs.sign)
    {
      return rhs-lhs;
    }
  }

  BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs)
  {
    
  }

  BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs)
  {
    
  }

  BigInteger operator/(const BigInteger& lhs, const BigInteger& rhs)
  {
    
  }

  BigInteger operator%(const BigInteger& lhs, const BigInteger& rhs)
  {
    
  }

  BigInteger& operator+=(BigInteger& lhs, const BigInteger& rhs)
  {
    lhs = std::move(lhs+rhs);
    return lhs;
  }

  BigInteger& operator-=(BigInteger& lhs, const BigInteger& rhs)
  {
    lhs = std::move(lhs-rhs);
    return lhs;
  }

  BigInteger& operator*=(BigInteger& lhs, const BigInteger& rhs)
  {
    lhs = std::move(lhs*rhs);
    return lhs;
  }

  BigInteger& operator/=(BigInteger& lhs, const BigInteger& rhs)
  {
    lhs = std::move(lhs/rhs);
    return lhs;
  }

  BigInteger& operator%=(BigInteger& lhs, const BigInteger& rhs)
  {
    lhs = std::move(lhs%rhs);
    return lhs;
  }


  //단항연산자
  BigInteger& BigInteger::operator++()
  {
    if(sign)
    {
      
    }
    else
    {
      
    }
    
    return *this;
  }

  BigInteger BigInteger::operator++(int)
  {
    return ++(*this);
  }

  BigInteger BigInteger::operator+() const
  {
    return *this;
  }

  BigInteger& BigInteger::operator--()
  {
    
  }

  BigInteger BigInteger::operator--(int)
  {
    return --(*this);
  }

  BigInteger BigInteger::operator-() const
  {
    if(num.size()==1 && num[0]==0)
    {
      return *this;
    }

    BigInteger clone = *this;
    
    clone.sign = !clone.sign;
    return clone;
  }

  template <class Operator>
  bool _less_or_greater(const BigInteger& lhs, const BigInteger& rhs, Operator op)
  {
    if(lhs.is_negative() && rhs.is_positive())
    {
      return true;
    }
    if(lhs.is_positive() && rhs.is_negative())
    {
      return false;
    }
    
    auto positive = lhs.is_positive();
    
    auto lhs_length = lhs.num.size();
    auto rhs_length = rhs.num.size();
    if(lhs_length < rhs_length)
    {
      return positive ? true : false;
    }
    if(lhs_length > rhs_length)
    {
      return positive ? false : true;
    }
      
    for(int i = lhs_length-1; i>=0; i--)
    {
      if(lhs.num[i] < rhs.num[i])
      {
        return positive ? true : false;
      }
      if(lhs.num[i] > rhs.num[i])
      {
        return positive ? false : true;
      }
    }
      
    return false;
  }

  //비교연산자
  bool operator<(const BigInteger& lhs, const BigInteger& rhs)
  {
    
  }

  bool operator>(const BigInteger& lhs, const BigInteger& rhs)
  {
    
  }

  bool operator<=(const BigInteger& lhs, const BigInteger& rhs)
  {
    return !(lhs>rhs);
  }

  bool operator>=(const BigInteger& lhs, const BigInteger& rhs)
  {
    return !(lhs<rhs);
  }

  bool operator==(const BigInteger& lhs, const BigInteger& rhs)
  {
    if(lhs.sign!=rhs.sign || lhs.num.size()!=rhs.num.size())
    {
      return false;
    }
    
    for(int i = 0; i<lhs.num.size(); i++)
    {
      if(lhs.num[i]!=rhs.num[i])
      {
        return false;
      }
    }
    
    return true;
  }

  bool operator!=(const BigInteger& lhs, const BigInteger& rhs)
  {
    return !(lhs==rhs);
  }

  bool BigInteger::is_zero() const noexcept
  {
    return num.size()==1 && num[0]==0;
  }

  bool BigInteger::is_odd() const noexcept
  {
    return num[0]%2 == 0;
  }

  bool BigInteger::is_even() const noexcept
  {
    return !is_odd();
  }

  bool BigInteger::is_negative() const noexcept
  {
    return sign==false;
  }

  bool BigInteger::is_positive() const noexcept
  {
    return sign==true;
  }
  
}

bignumber::BigInteger operator ""bi(unsigned long long n)
{
  return bignumber::BigInteger(n);
}