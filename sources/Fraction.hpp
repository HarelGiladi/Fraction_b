#ifndef FRA
#define FRA
#include <iostream>

using namespace std;

namespace ariel
{
    class Fraction
    {
        private:
            int numerator;
            int denominator;
        

        public:
            Fraction();

            Fraction(int, int);

            Fraction(float);



            Fraction operator++(int);

            Fraction operator++();

            Fraction operator--(int);

            Fraction operator--();


            int getNumerator();

            int getDenominator();

            
            friend bool operator>(const Fraction&, const Fraction&);

            friend bool operator>=(const Fraction&, const Fraction&);

            friend bool operator>(const Fraction&, const Fraction&);    

            friend bool operator<(const Fraction&, const Fraction&);

            friend bool operator<=(const Fraction&, const Fraction&);

            friend bool operator==(const Fraction&, const Fraction&);

            friend bool operator!=(const Fraction&, const Fraction&);
            

            friend Fraction operator+(const Fraction&, const Fraction&);

            friend Fraction operator-(const Fraction&, const Fraction&);

            friend Fraction operator*(const Fraction&, const Fraction&);

            friend Fraction operator/(const Fraction&, const Fraction&);


            friend ostream& operator<<(ostream&, const Fraction&);

            friend istream& operator>>(istream&, Fraction&);
    };
}

#endif











