#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Rational
{
private:
	int numer;
	int denom;
	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		else
			return gcd(b, a % b);
	}
	int abs(int a)
	{
		return (a > 0) ? a : -a;
	}
	void simplify()
	{
		bool negative = (numer * denom < 0);
		numer = abs(numer);
		denom = abs(denom);
		int g = gcd(numer, denom);
		numer = numer / g;
		denom = denom / g;
		if (negative)
		{
			numer = -numer;
		}
	}

public:
	Rational()
	{
		numer = 0;
		denom = 1;
	}
	Rational(int n) : numer{n} { denom = 1; }
	Rational(int n, int d) : numer{n}, denom{d}
	{
		simplify();
	}
	Rational(const Rational &r)
	{
		numer = r.numer;
		denom = r.denom;
	}
	Rational &operator=(const Rational &r)
	{
		numer = r.numer;
		denom = r.denom;
		return *this;
	}
	void show() const
	{
		if (denom == 1)
			cout << numer << endl;
		else
			cout << numer << "/" << denom << endl;
	}
	int nu() const
	{
		return numer;
	}
	int de() const
	{
		return denom;
	}
	Rational &operator+=(const Rational &r);
	Rational &operator-=(const Rational &r);
	Rational &operator*=(const Rational &r);
	Rational &operator/=(const Rational &r);
	const Rational &operator++();
	const Rational &operator--();
	Rational operator++(int);
	Rational operator--(int);
};

Rational &Rational::operator+=(const Rational &r)
{
	numer = numer * r.denom + denom * r.numer;
	denom = denom * r.denom;
	simplify();
	return *this;
}

Rational &Rational::operator-=(const Rational &r)
{
	numer = numer * r.denom - denom * r.numer;
	denom = denom * r.denom;
	simplify();
	return *this;
}

Rational &Rational::operator*=(const Rational &r)
{
	numer = numer * r.numer;
	denom = denom * r.denom;
	simplify();
	return *this;
}

Rational &Rational::operator/=(const Rational &r)
{
	numer = numer * r.denom;
	denom = denom * r.numer;
	simplify();
	return *this;
}

const Rational operator+(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.nu() * rhs.de() + lhs.de() * rhs.nu(), lhs.de() * rhs.de());
}

const Rational operator-(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.nu() * rhs.de() - lhs.de() * rhs.nu(), lhs.de() * rhs.de());
}

const Rational operator*(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.nu() * rhs.nu(),
					lhs.de() * rhs.de());
}

const Rational operator/(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.nu() * rhs.de(), lhs.de() * rhs.nu());
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
	return lhs.nu() == rhs.nu() && lhs.de() == rhs.de();
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
	Rational rat = lhs - rhs;
	return rat.nu() < 0;
}

ostream &operator<<(ostream &os, const Rational &a)
{
	if (a.de() == 1)
		os << a.nu();
	else
		os << a.nu() << "/" << a.de();
	return os;
}

const Rational &Rational::operator++()
{
	numer += denom;
	return *this;
}

const Rational &Rational::operator--()
{
	numer -= denom;
	return *this;
}

Rational Rational::operator++(int)
{
	Rational rat = *this;
	++*this;
	return rat;
}

Rational Rational::operator--(int)
{
	Rational rat = *this;
	--*this;
	return rat;
}

int main()
{
	Rational r{6, -5};
	Rational t{r};
	Rational z;
	r.show();
	t.show();
	z.show();
	z = t;
	z += t;
	z += Rational(2, 3);
	z.show();
	z = t + 2;
	z.show();
	z = 2 / t;
	z.show();
	++z;
	z.show();
	z--;
	z.show();
	cout << z << endl;
	Rational a{2, 3};
	Rational b{5, 7};
	// const Rational operator+(const Rational& a, const Rational& b);
	// the following statement is wrong because the left - hand - side is const
	// a+b = 3;
	vector<Rational> vec{Rational(2, 3), Rational(3, 4), Rational(1, 2)};
	cout << "before sorting\n";
	for (auto v : vec)
		cout << v << endl;
	sort(vec.begin(), vec.end());
	cout << "after sorting\n";
	for (auto v : vec)
		cout << v << endl;
}