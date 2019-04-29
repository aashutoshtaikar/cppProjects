#include<iostream>
#include<sstream>
#include <stdexcept>
#include <cmath>
#include<variant>

class fraction
{
private:
    long double nr;
    long double dr;

//    fraction nf;
//    fraction df;

public:
    fraction()noexcept;
    fraction(long double n);
    fraction(long double n,long double d);

    //operators
    fraction operator+(const fraction& other)const;
    fraction operator-(const fraction& other)const;
    fraction operator/(const fraction& other)const;
    fraction operator*(const fraction& other)const;

    //assignment or short hand operators
    fraction& operator+=(const fraction& other);
    fraction& operator-=(const fraction& other);
    fraction& operator/=(const fraction& other);
    fraction& operator*=(const fraction& other);

    //relational operators
    bool operator>(const fraction& other)const;
    bool operator<(const fraction& other)const;
    bool operator>=(const fraction& other)const;
    bool operator<=(const fraction& other)const;
    bool operator==(const fraction& other)const;
    bool operator!=(const fraction& other)const;

    //casting operators
    operator int();
    operator float();
    operator double();

    //operations
    fraction get_reciprocal()const;
    void reciprocal();
    static long double gcd(const long double& x,const long double& y);
    fraction get_simplify()const;
    const fraction& simplify();

    //public accessors
    long double get_nr()const;
    long double get_dr()const;
    void set_nr(const long double& n);
    void set_dr(const long double& d);

    //defaults for the big 5
    fraction(const fraction& other) = default;
    fraction& operator=(const fraction& other) = default;
    fraction(fraction&& other) = default;
    fraction& operator=(fraction&& other) = default;
    virtual ~fraction() = default;
};

std::ostream& operator<<(std::ostream &out, const fraction &frac);


fraction operator+(const long double& number, const fraction& frac);

fraction operator+(const fraction& frac,const long double& number);

fraction operator-(const long double& number, const fraction& frac);
fraction operator-(const fraction& frac,const long double& number);

fraction operator*(const long double& number, const fraction& frac);
fraction operator*(const fraction& frac,const long double& number);

fraction operator/(const long double& number, const fraction& frac);
fraction operator/(const fraction& frac,const long double& number);

