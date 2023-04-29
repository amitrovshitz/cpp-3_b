#include "Fraction.hpp"
using namespace std;


 namespace ariel
 {
            Fraction::Fraction():numerator(0), denominator(1){}
            Fraction::Fraction(int num, int den):numerator(num), denominator(den) {
                if(denominator == 0)
                {
                    throw invalid_argument("not ilegal.");
                }

                if(denominator < 0)
                {
                    numerator *= -1;
                    denominator *= -1;
                }

                reduce();
            }
            Fraction::Fraction(const float& num):numerator(int(num*1000)), denominator(1000){
                reduce();
            }
            Fraction::Fraction(const Fraction& other):numerator(other.numerator), denominator(other.denominator){}
               
            Fraction::Fraction(Fraction&& other) noexcept:numerator(other.numerator), denominator(other.denominator){}

            int Fraction::gcd(int f_number, int s_number)
            {
                if (s_number == 0)
                {
                    return f_number;
                }
                return gcd(s_number, f_number % s_number);
            }

            void Fraction::reduce()
            {   
                int gcdNum = gcd(abs(numerator), abs(denominator));
                numerator /= gcdNum;
                denominator /= gcdNum;
            }

            Fraction& Fraction::operator=(const Fraction& other)
            {
                if(this != &other)
                {
                    numerator = other.numerator;
                    denominator = other.denominator;
                }
                return *this; 
            }
            Fraction& Fraction::operator=(Fraction&& other) noexcept {
                if (this != &other) {
                    numerator = other.numerator;
                    denominator = other.denominator;
                    other.numerator = 0;
                    other.denominator = 1;
                }
                return *this;
            }

            const Fraction Fraction::operator+(const Fraction& other)const 
            {
                int num1 = overflow_mul(numerator, other.denominator);
                int num2 = overflow_mul(denominator, other.numerator);
                int numerator_add = overflow_add(num1, num2);
                int denominator_add = overflow_mul(denominator, other.denominator);                
                return Fraction(numerator_add,denominator_add);
            }

            const Fraction Fraction::operator+(const float& other)const
            {
                return (*this + Fraction(other));
            }

            const Fraction operator+(const float& one, const Fraction& two)
            {
                return (Fraction(one) + two);
            }

            const Fraction Fraction::operator-(const Fraction& other)const
            {
                int num1 = overflow_mul(numerator, other.denominator);
                int num2 = overflow_mul(denominator, other.numerator);
                int numerator_add = overflow_sub(num1, num2);
                int denominator_add = overflow_mul(denominator, other.denominator);                
                return Fraction(numerator_add, denominator_add);        
            }

            const Fraction Fraction::operator-(const float& other)const
            {
                return *this - Fraction(other);
            }

            const Fraction operator-(const float& one, const Fraction& two)
            {
                return Fraction(one) - two;
            }

            const Fraction Fraction::operator*(const Fraction& other)const
            {
                int num1 = overflow_mul(numerator, other.numerator);
                int num2 = overflow_mul(denominator, other.denominator);               
                return Fraction(num1, num2);
            }

            const Fraction Fraction::operator*(const float& other)const
            {
                return *this * Fraction(other);
            }

            const Fraction operator*(const float& one, const Fraction& two)
            {
                return Fraction(one) * two;
            }

            const Fraction Fraction::operator/(const Fraction& other)const
            {
                if(other.numerator == 0)
                {
                    throw runtime_error("cant divide by zero.");
                }
                int num1 = overflow_mul(numerator, other.denominator);
                int num2 = overflow_mul(denominator, other.numerator);               
                return Fraction(num1, num2);
            }

            const Fraction Fraction::operator/(const float& other)const
            {
                return *this / Fraction(other);
            }

            const Fraction operator/(const float& one, const Fraction& two)
            {
                return Fraction(one) / two;
            }

            bool Fraction::operator==(const Fraction& other)const
            {
                int frac1 = int((numerator/(float)denominator)*1000);
                int frac2 = int((other.numerator/(float)other.denominator)*1000);
                return (frac1 == frac2);
            }

            bool Fraction::operator==(const float& other)const
            {
                return (*this == Fraction(other));
            }

            bool operator==(const float& one, const Fraction& two)
            {
                return (Fraction(one) == two);
            }

            bool Fraction::operator>(const Fraction& other)const
            {
                return ((numerator * other.denominator) > (denominator * other.numerator));
            }

            bool Fraction::operator>(const float& other)const
            {
                return (*this > Fraction(other));
            }

            bool operator>(const float& one, const Fraction& two)
            {
                return (Fraction(one) > two);
            }

            bool Fraction::operator<(const Fraction& other)const
            {
                return ((numerator * other.denominator) < (denominator * other.numerator));
            }

            bool Fraction::operator<(const float& other)const
            {
                return (*this < Fraction(other));
            }

            bool operator<(const float& one, const Fraction& two)
            {
                return (Fraction(one) < two);
            }

            bool Fraction::operator>=(const Fraction& other)const
            {
                return ((*this > other) || (*this == other));
            }

            bool Fraction::operator>=(const float& other)const
            {
                return (*this >= (Fraction(other)));
            }

            bool operator>=(const float& one, const Fraction& two)
            {
                return (Fraction(one) >= two);
            }
        
            bool Fraction::operator<=(const Fraction& other)const
            {
                return ((*this < other) || (*this == other));
            }

            bool Fraction::operator<=(const float& other)const
            {
                return (*this <= (Fraction(other)));
            }

            bool operator<=(const float& one, const Fraction& two)
            {
                return (Fraction(one) <= two);
            }

             Fraction& Fraction::operator+=(const Fraction& other)
            {
                numerator = (other.denominator * numerator) + (denominator * other.numerator);
                denominator = other.denominator * denominator;
                reduce();

                return *this;
            }

            Fraction& Fraction::operator-=(const Fraction& other)
            {
                numerator = (other.denominator * numerator) - (denominator * other.numerator);
                denominator = other.denominator * denominator;
                reduce();

                return *this;
            }

            Fraction& Fraction::operator++()
            {
                *this += Fraction(denominator, denominator);
                return *this;
            }

            const Fraction Fraction::operator++(int postfix_increment)
            {
                Fraction copy = *this;
                ++(*this);
                return copy;
            }

            Fraction& Fraction::operator--()
            {
                *this -= Fraction(denominator, denominator);
                return *this;
            }

            const Fraction Fraction::operator--(int postfix_decrement)
            {
                Fraction copy = *this;
                --(*this);
                return copy;            
            } 

            ostream& operator<<(ostream& oss, const Fraction& obj)
            {
                return oss << obj.numerator << '/' << obj.denominator;
            }

            istream& operator>>(istream& iss, Fraction& obj)
            {
                int numerator;
                int denominator = 0;

                iss >> numerator >> denominator;
                if(iss.fail())
                {
                    throw runtime_error("ilegal");
                }
                else if( denominator == 0)
                {
                    throw runtime_error("denominator can't be 0.");
                }

                obj = Fraction(numerator, denominator);
                return iss;
            }
 }