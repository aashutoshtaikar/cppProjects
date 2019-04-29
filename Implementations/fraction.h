#include<iostream>
#include <stdexcept>
class fraction
{
private:
    double num,den;

public:
    fraction()noexcept:num(0),den(1){}

    fraction(double n,double d):num(n){
        if(d) den = d;
        else{ 
            throw std::invalid_argument("demonimator cannot be zero(0)");
        }
    }

    fraction operator+(const fraction& other)const{
        fraction temp;
        if(false){

        }
        else{
            temp.num = this->num * other.den + this->den * other.num;
            temp.den = this->den * other.den;
        }
        return temp;
    }

    fraction operator-(const fraction& other)const{
        fraction temp;
        temp.num = this->num * other.den - this->den * other.num;
        temp.den = this->den * other.den;
        return temp;    
    }

    fraction operator/(const fraction& other)const{
        fraction temp;
        temp.num = this->num * other.den; 
        temp.den = other.num * this->den;
        return temp; 
    }

    fraction operator*(const fraction& other)const{
        fraction temp;
        temp.num = this->num * other.num;
        temp.den = this->den * other.den;
        return temp; 
    } 

    bool operator=(const fraction& other)const{
        return ((this->num == other.num) && (this->den == other.den));
    } 

    bool operator!=(const fraction& other)const{
        return ((this->num != other.num) && (this->den != other.den));
    }

    fraction reciprocal(){
        
    }


    friend std::ostream& operator<<(std::ostream& out,const fraction& other){
        return (out << other.num <<"/"<< other.den);
    }

    fraction(const fraction& other) = default;
    fraction& operator=(const fraction& other) = default;
    fraction(fraction&& other) = default;
    fraction& operator=(fraction&& other) = default;
    virtual ~fraction() = default;
};

