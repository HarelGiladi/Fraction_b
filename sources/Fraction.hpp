#ifndef FRA
#define FRA
#include <iostream>

using namespace std;

#define intMax (int)(std::numeric_limits<int>::max())
#define intMin (int)(std::numeric_limits<int>::min())

namespace ariel
{
    class Fraction
    {
        private:
            int numerator;
            int denominator;
            void reduction();
        

        public:
            Fraction();
            Fraction(int, int);
            Fraction(float);



            Fraction operator++(int);
            Fraction &operator++();

            Fraction operator--(int);
            Fraction &operator--();


            int getNumerator() const;
            int getDenominator() const;

            
            bool operator>(float) const;
            bool operator>(const Fraction &) const;
            friend bool operator>(float, const Fraction&);


            bool operator>=(float) const;
            bool operator>=(const Fraction &) const;
            friend bool operator>=(float, const Fraction&);


            bool operator<(float) const;
            bool operator<(const Fraction &) const;
            friend bool operator<(float, const Fraction&);

            bool operator<=(float) const;
            bool operator<=(const Fraction &) const;
            friend bool operator<=(float, const Fraction&);


            bool operator==(float) const;
            bool operator==(const Fraction &) const;
            friend bool operator==(float, const Fraction&);


            bool operator!=(float) const;
            bool operator!=(const Fraction &) const;
            friend bool operator!=(float, const Fraction&);
            


            Fraction operator+(float);
            Fraction operator+(const Fraction &);
            friend Fraction operator+(float, const Fraction&);


            Fraction operator-(float);
            Fraction operator-(const Fraction &);
            friend Fraction operator-(float, const Fraction&);


            Fraction operator*(float);
            Fraction operator*(const Fraction &);
            friend Fraction operator*(float, const Fraction&);


            Fraction operator/(float);
            Fraction operator/(const Fraction &);
            friend Fraction operator/(float, const Fraction&);


            friend ostream& operator<<(ostream&, const Fraction&);
            friend istream& operator>>(istream&, Fraction&);
    };
}

#endif











