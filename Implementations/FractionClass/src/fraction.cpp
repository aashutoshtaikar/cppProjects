#include "fraction.h"

fraction::fraction()noexcept:nr(0),dr(1.0l){}

fraction::fraction(long double n)
{
    *this = fraction(n,1).get_simplify();
}

fraction::fraction(long double n,long double d)
{

    while(fmod(n,10)!=0 && fmod(d,10)!=0){
        n *= 10;
        d *= 10;
    }

    if(fmod(n,10)==0 && fmod(d,10)==0){
        n/=10;
        d/=10;
    }

    int sign = 1;
    if(d<0){
        sign *= -1;
        d *= -1;
    }
    if(n<0){
        sign *= -1;
        n *= -1;
    }

    set_dr(d);
    set_nr(n*sign);
}

////////////////////////////////
//fraction operator overloads//
//////////////////////////////
fraction fraction::operator+(const fraction &other) const
{
    fraction temp;
    if(dr==other.dr){
        temp.set_nr(nr + other.nr);
        temp.set_dr(dr);
    }
    else{
        temp.set_nr(nr * other.dr + dr * other.nr);
        temp.set_dr(dr * other.dr);
    }
    return temp;
}

fraction fraction::operator-(const fraction &other) const
{
    fraction temp;
    if(dr==other.dr){
        temp.set_nr(nr - other.nr);
        temp.set_dr(dr);
    }
    else{
        temp.nr = nr * other.dr - dr * other.nr;
        temp.dr = dr * other.dr;
    }
    return temp;
}

fraction fraction::operator/(const fraction &other) const{
    fraction temp;
    temp.set_nr(nr * other.dr);
    temp.set_dr(dr * other.nr);
    return temp;
}

fraction fraction::operator*(const fraction &other) const{
    fraction temp;
    temp.set_nr(nr * other.nr);
    temp.set_dr(dr * other.dr);
    return temp;
}

///////////////////////////////////////////
//fraction operator assignment overloads//
/////////////////////////////////////////
fraction& fraction::operator+=(const fraction &other){
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction &other){
    *this = *this- other;
    return *this;
}

fraction& fraction::operator/=(const fraction &other){
    *this = *this/other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other){
   *this = *this*other;
    return *this;
}

/////////////////////////
//relational operators//
///////////////////////
bool fraction::operator>(const fraction &other) const
{
    return ((double)this->get_simplify() > (double)other.get_simplify());
}

bool fraction::operator<(const fraction &other) const
{
    return ((double)this->get_simplify() < (double)other.get_simplify());
}

bool fraction::operator>=(const fraction &other) const
{
    return ((double)this->get_simplify() >= (double)other.get_simplify());
}

bool fraction::operator<=(const fraction &other) const
{
    return ((double)this->get_simplify() <= (double)other.get_simplify());
}

bool fraction::operator==(const fraction &other) const{
    return ((double)this->get_simplify() == (double)other.get_simplify());
}

bool fraction::operator!=(const fraction &other) const{
    return ((double)this->get_simplify() != (double)other.get_simplify());
}

///////////////////
//cast operators//
/////////////////
fraction::operator double(){
    return (double)nr/dr;
}

fraction::operator float(){
    return (float)nr/dr;
}

fraction::operator int(){
    return (int)nr/dr;
}


/////////////////////
//public accessors//
///////////////////
long double fraction::get_nr() const{
    return nr;
}

long double fraction::get_dr() const{
    return dr;
}

void fraction::set_nr(const long double& n)
{
   nr = n;
   if(nr==0) set_dr(1);
}

void fraction::set_dr(const long double& d)
{
    if(d!=0) dr = d;
    else{
        throw std::invalid_argument("demonimator cannot be zero(0)");
    }
}

////////////////////
//logic functions//
//////////////////
fraction fraction::get_reciprocal()const{
    try {
        return (fraction(dr,nr));
    } catch (std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
        return fraction(0,1);
    }
}

void fraction::reciprocal(){
    try {
        *this = get_reciprocal();
    } catch (std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
        *this = fraction(0,1);
    }
}

long double fraction::gcd(const long double& x,const long double& y)
{
    long double divisor = x<y?x:y;
    long double divident = x>y?x:y;
    long double remainder = 1; //dummy remainder

    while(remainder){
        remainder = fmod(divident,divisor);
        divident = divisor;
        if (remainder) divisor = remainder;
    }
    return divisor;
}

fraction fraction::get_simplify() const
{
    if(nr!=0.0l){
        long double divisor = gcd(nr,dr);
        long double num = nr/divisor;
        long double denom = dr/divisor;
        return fraction(num,denom);
    }
    return fraction(0,1);
}


const fraction& fraction::simplify()
{
    *this = get_simplify();
    return *this;
}

//////////////////////////////
//global operator overloads//
////////////////////////////
std::ostream& operator<<(std::ostream &out, const fraction &f)
{
    if(f.get_dr()==1.0l || f.get_nr()==0.0l){
        out << f.get_nr();
    }
    else{
        out << f.get_nr() <<"/"<< f.get_dr();
    }
    return out;
}

fraction operator+(const long double& number, const fraction &frac){
    return fraction(number) + frac;
}

fraction operator+(const fraction &frac, const long double& number){
    return  fraction(number,1) + frac;
}

fraction operator-(const long double& number, const fraction &frac){
    return  fraction(number,1) - frac;
}

fraction operator-(const fraction &frac, const long double& number){
    return frac - fraction(number,1);
}

fraction operator*(const long double& number, const fraction &frac){
    return fraction(number,1) * frac;
}

fraction operator*(const fraction &frac, const long double& number){
    return fraction(number,1) * frac;
}

fraction operator/(const long double& number, const fraction &frac){
    return fraction(number,1) / frac;
}

fraction operator/(const fraction &frac, const long double& number){
     return frac / fraction(number,1);
}
