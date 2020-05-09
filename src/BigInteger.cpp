#include "BigInteger.h"

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

//구현
BigInteger operator ""bi(unsigned long long n)
{
  return BigInteger(n);
}

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
