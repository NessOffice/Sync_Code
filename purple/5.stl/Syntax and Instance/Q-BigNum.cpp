#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct BigNum
{
	static const int BASE = 100000000;
	static const int WIDTH =8;
	vector<int> s;
	
	BigNum(long long num = 0){*this = num;}
	BigNum operator = (long long num)
	{
		s.clear();
		do{
			s.push_back(num % BASE);
			num /= BASE;
		}while(num);
		return *this;
	}
	BigNum operator = (string str)
	{
		s.clear();
		int x, len = (str.length() - 1)/WIDTH + 1;
		for(int i=0;i<len;i++)
		{
			int end = str.length() - i*WIDTH;
			int start = max(0,end - WIDTH);
			sscanf(str.substr(start,end).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	BigNum operator + (const BigNum& b) const//why const?
	{
		BigNum c;
		c.s.clear();
		for(int i=0,g=0;;i++)
		{
			if(g==0 && i>=s.size() && i>=b.s.size()) break;
			int x = g;
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x+=b.s[i];
			c.s.push_back(x % BASE);
			g = x / BASE; 
		}
		return c;
	}
	BigNum operator += (const BigNum& b)
	{
		*this = *this + b;
		return *this;
	}
	bool operator < (const BigNum& b) const
	{
		if(s.size() != b.s.size()) return s.size()<b.s.size();
		for(int i = s.size() - 1;i >= 0;i--)
			if(s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}
	bool operator > (const BigNum& b) const{return b < *this;}
	bool operator >= (const BigNum& b) const{return !(*this < b);}
	bool operator <= (const BigNum& b) const{return !(b < *this);}
	bool operator != (const BigNum& b) const{return b < *this || *this < b;}
	bool operator == (const BigNum& b) const{return !(b < *this) && !(*this < b);}
	BigNum operator - (BigNum& b)
	{
		BigNum c;
		c.s.clear();
		if(b > *this) return b - *this;
		for(int i=0;i<s.size();i++)
		{
			int x = s[i];
			if(i<b.s.size()) x -= b.s[i];
			if(x<0)
			{
				x += BASE;
				s[i+1]--;
			}
			c.s.push_back(x);
		}
		int len = c.s.size();
		while(c.s[len - 1] == 0) len--;
		c.s.resize(len);
		return c;
	}
	BigNum operator -= (BigNum& b)
	{
		*this = *this - b;
		return *this;
	}
	BigNum operator * (const BigNum& b)
	{
		BigNum c;
		int len = 0;
		c.s.clear();
		for(int i=0;i<b.s.size();i++)
		{
			for(int j=0;j<s.size();j++)
			{
				int x = b.s[i] * s[j];
				int x1 = x % BASE;
				int x2 = x / BASE;
				if(len < i + j + 1){c.s.push_back(x1);len++;}
				else c.s[i+j+1] += x1;
				if(len < i + j + 2 && x2){c.s.push_back(x2);len++;}
				else if(x2) c.s[i+j+2] += x2;
			}
		}
		for(int i=0;i<c.s.size();i++)
		{
			int x = c.s[i] / BASE;
			if(x)
			{
				if(i==c.s.size()-1) c.s.push_back(x);
				else c.s[i+1] += x;
				c.s[i] %= BASE;
			}
		}
		return c;
	}
}; 
ostream& operator << (ostream &out, const BigNum& x)
{
	out << x.s.back();//dont understand
	for(int i=x.s.size()-2;i>=0;i--)
	{
		char buf[20];
		sprintf(buf,"%08d",x.s[i]);
		for(int j=0;j<strlen(buf);j++)
			out<<buf[j];
	}
	return out;
}
istream& operator >> (istream &in, BigNum& x)
{
	string s;
	if(!(in>>s)) return in;
	x = s;
	return in;
}

int main()
{
	BigNum a,b,c;//unknown problem?
	string i;
	cin>>i;
	a=i;
	cout<<a<<endl;
	for(int i=0;i<a.s.size();i++)
		cout<<a.s[i]<<endl;
	return 0;
} 
