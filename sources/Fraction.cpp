#include <iostream>
#include <limits>
#include <algorithm>
#include "Fraction.hpp"

using namespace std;


 void ariel::Fraction::reduction(){
    int gcd = __gcd(this->numerator, this->denominator); 

    this->numerator = this->numerator / gcd;
    this->denominator = this->denominator / gcd;

    if (this->denominator < 0 && this->numerator > 0) {this->numerator *= -1; this->denominator *= -1;  }
}

namespace ariel
{

    Fraction::Fraction() : numerator(0), denominator(1) {} 
    Fraction::Fraction(float number) : Fraction(1000 * number, 1000) {} 
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        if (denominator == 0) {throw invalid_argument("DEVISON ERORR devison by zero");}
        else{
            if ((numerator == intMax && denominator == intMax) || (numerator == intMin && denominator == intMin)){
                this->numerator = 1; this->denominator = 1;}
            else if ((numerator == intMax && denominator == intMin) || (numerator == intMin && denominator == intMax)){
                this->numerator = -1; this->denominator = 1;}
        }
        this->reduction(); 
    }


    Fraction &Fraction::operator++(){   this->numerator = this->numerator + this->denominator; return *this;}
    Fraction Fraction::operator++(int number){Fraction temp = *this; ++*this; return temp;}

    Fraction &Fraction::operator--(){this->numerator = this->numerator - this->denominator; return *this;}
    Fraction Fraction::operator--(int number){Fraction temp = *this; --*this; return temp;}



    int Fraction::getNumerator() const {return this->numerator;}
    int Fraction::getDenominator() const{return this->denominator;}

    bool Fraction::operator==(float number) const{return this->numerator == number * this->denominator;}
    bool Fraction::operator==(const Fraction &otherFraction) const{return this->numerator == otherFraction.numerator && this->denominator == otherFraction.denominator;}
    bool operator==(float number, const Fraction &otherFraction){return Fraction(number) == otherFraction;}


    bool Fraction::operator!=(float number) const{return !(*this == number);}
    bool Fraction::operator!=(const Fraction &otherFraction) const{return !(*this == otherFraction);}
    bool operator!=(float number, const Fraction &otherFraction){return !(number == otherFraction);}


    bool Fraction::operator>(float number) const{return this->numerator > number * this->denominator;}
    bool Fraction::operator>(const Fraction &otherFraction) const{return this->numerator * otherFraction.denominator > otherFraction.numerator * this->denominator;}
    bool operator>(float number, const Fraction &otherFraction){return !(number <= otherFraction);}


    bool Fraction::operator<(float number) const{return this->numerator < number * this->denominator;}
    bool Fraction::operator<(const Fraction &otherFraction) const{return this->numerator * otherFraction.denominator < otherFraction.numerator * this->denominator;}
    bool operator<(float number, const Fraction &otherFraction){return !(number >= otherFraction);}


    bool Fraction::operator>=(float number) const{return *this > number || *this == number;}
    bool Fraction::operator>=(const Fraction &otherFraction) const{return *this > otherFraction || *this == otherFraction;}
    bool operator>=(float number, const Fraction &otherFraction){return Fraction(number) >= otherFraction;}


    bool Fraction::operator<=(float number) const{return *this < number || *this == number;}
    bool Fraction::operator<=(const Fraction &otherFraction) const{   return *this < otherFraction || *this == otherFraction;}
    bool operator<=(float number, const Fraction &otherFraction){return Fraction(number) <= otherFraction;}


    Fraction Fraction::operator+(float number){return *this + Fraction(number);}
    Fraction operator+(float other, const Fraction &otherFraction){return Fraction(other) + otherFraction;}
    Fraction Fraction::operator+(const Fraction &otherFraction){
        long long numerator = (long long)(this->numerator * otherFraction.denominator) + (long long)(otherFraction.numerator * this->denominator);
        long long denominator = (long long)(this->denominator) * (long long)(otherFraction.denominator);
        if (numerator > intMax || numerator < intMin || denominator > intMax || denominator < intMin){throw overflow_error("OVER FLOW ERORR");}
        return Fraction(numerator, denominator);
    }



    Fraction Fraction::operator-(float number){return *this - Fraction(number);}
    Fraction operator-(float number, const Fraction &otherFraction){return Fraction(number) - otherFraction;}
    Fraction Fraction::operator-(const Fraction &otherFraction){
        long long numerator = (long long)(this->numerator * otherFraction.denominator) - (long long)(otherFraction.numerator * this->denominator);
        long long denominator = (long long)(this->denominator) * (long long)(otherFraction.denominator);
        if (numerator > intMax || numerator < intMin || denominator > intMax || denominator < intMin){throw overflow_error("OVER FLOW ERORR");}
        return Fraction(numerator, denominator);
    }



    Fraction Fraction::operator*(float number){return *this * Fraction(number);}
    Fraction operator*(float number, const Fraction &otherFraction){return Fraction(number) * otherFraction;}
    Fraction Fraction::operator*(const Fraction &otherFraction){
        long long numerator = (long long)(this->numerator) * (long long)(otherFraction.numerator);
        long long denominator = (long long)(this->denominator) * (long long)(otherFraction.denominator);
        if (numerator > intMax || numerator < intMin || denominator > intMax || denominator < intMin){throw overflow_error("OVER FLOW ERORR");}
        return Fraction(numerator, denominator);
    }



    Fraction operator/(float number, const Fraction &otherFraction){return Fraction(number) / otherFraction;}
    Fraction Fraction::operator/(const Fraction &otherFraction){
        if (otherFraction.numerator == 0){throw runtime_error("DEVISON ERORR devison by zero");}
        return *this * Fraction(otherFraction.denominator, otherFraction.numerator);
    }
    Fraction Fraction::operator/(float number){        
        if (number == 0){throw runtime_error("DEVISON ERORR devison by zero");}
        return *this / Fraction(number);
    }


    

    ostream &operator<<(ostream &stream, const Fraction &otherFraction){stream << otherFraction.numerator << "/" << otherFraction.denominator; return stream;}

    istream &operator>>(istream &stream, Fraction &otherFraction){
        if (stream >> otherFraction.numerator >> otherFraction.denominator){
            if (otherFraction.denominator == 0){throw runtime_error("DEVISON ERORR devison by zero");}
            otherFraction.reduction(); 
            return stream;
        }
        else{throw runtime_error("must enter two numbers");}
    }
}