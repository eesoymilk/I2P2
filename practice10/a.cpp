#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_Bit 5
#define MAX 100000

class BigInt{
    public:
        long long operator [](int i) const { return m[i]; }
        long long &operator [](int i) { return m[i]; }
        BigInt(){ l=1, m[0]=0; sign=1; }
        friend istream& operator>>(istream&, BigInt&);   
        friend ostream& operator<<(ostream&, BigInt);   
        BigInt operator +( const BigInt &y );  
        BigInt operator -( const BigInt &y );
    private:
        long long m[1000];
        int l;
        int sign;
};

istream& operator>>(istream &in,  BigInt &b)  
{
    string ch;
    in >> ch;
    if( ch[0] == '-' ) ch = ch.substr(1, ch.length()-1), b.sign = -1;
    else b.sign = 1;
    reverse(ch.begin(), ch.end());
    int id=0;
    for(int i = 0 ; i < ch.length() ; i += MAX_Bit)
    {
        string sub = ch.substr(i, MAX_Bit);
        reverse(sub.begin(), sub.end());
        b.m[ id++ ] = stoi( sub );
    }
    b.l = id;
    return in;
}
ostream& operator<<(ostream &out,  BigInt b)  
{
    out << ((b.sign == -1) ? "-" : "");
    out << b.m[b.l - 1];
    for(int i = b.l-2 ; i >= 0 ; i--)
    {
        out.width(MAX_Bit); 
        out.fill('0');
        out << b.m[i];
    } 
    return out;
}
BigInt BigInt::operator +(const BigInt &y)
{
    BigInt x(*this);
	int i;
	long long h;
	for(h = 0, i = 0 ; i < x.l || i < y.l || h ; i++)
    {
		h += (i < x.l)*x[i]*x.sign + (i < y.l)*y[i]*y.sign;
		x[i] = h % MAX;
		h /= MAX;
	}
	x.l = i;
	
	x.sign=(x[x.l-1] > 0 ? 1 : -1);
	if(x[x.l-1]>0)
    { 
      for(i = 0 ; i < x.l ; i++) 
        if(x[i] < 0) x[i+1]--, x[i] += MAX; 
    } else
    { 
      for(i = 0 ; i < x.l ; i++) 
        if(x[i] > 0) x[i+1]++, x[i] -= MAX;
    }  
	for(i = 0 ; i < x.l ; i++) x[i] *= x.sign; 
    for(; x.l > 1 && !x[x.l - 1] ; x.l--);
	if(x.sign == -1 && x.l == 1 && x[0] == 0) x.sign=1; 
	return x;
}
BigInt BigInt::operator -( const BigInt &y ){
    BigInt x(*this);
	int i;
	long long h;
	for(h = 0, i = 0; i < x.l || i < y.l || h; i++)
    {
		h+=(i < x.l)*x[i]*x.sign-( i < y.l)*y[i]*y.sign;
		x[i]=h % MAX;
		h /= MAX;
	}
	x.l = i;
	x.sign = (x[x.l-1] > 0 ? 1 : -1);
	if(x[x.l-1]>0){ 
      for(i = 0; i < x.l; i++)
        if(x[i] < 0) x[i+1]--, x[i] += MAX; 
    }
	else
    {
      for(i = 0; i < x.l; i++) 
        if(x[i] > 0) x[i+1]++, x[i] -= MAX;
    }
	for(i = 0; i < x.l; i++) x[i] *= x.sign;
    for(; x.l > 1 && !x[x.l-1]; x.l--);
	if(x.sign == -1 && x.l == 1 && x[0] == 0) x.sign = 1;
	return x;
}