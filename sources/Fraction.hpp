#pragma once
#include <iostream>
#include <limits> // include the <limits> header
using namespace std;

namespace ariel
{
    class Fraction
    {
        private:

            int numerator;
            int denominator;
            void reduce();
            static int gcd(int f_number, int s_number);
            static int overflow_add(int num1, int num2)
            {
                int max = std::numeric_limits<int>::max();
                int min = std::numeric_limits<int>::min(); 
                if(((num1 > 0) && (num2 > max - num1)) || ((num1 < 0) && (num2 < min - num1)))
                {
                    throw overflow_error("overflow");
                }
                return (num1 + num2); 

            }
            static int overflow_sub(int num1, int num2)
            {
                int max = std::numeric_limits<int>::max();
                int min = std::numeric_limits<int>::min(); 
                if(((num2 < 0) && (num1 > max + num2)) || ((num2 > 0) && (num1 < min + num2)))
                {
                    throw overflow_error("overflow");
                } 
                return (num1 - num2); 
  
            }
            static int overflow_mul(int num1, int num2)
            {
                int max = std::numeric_limits<int>::max();
                if(((num1 > 0) && (num2 > max / num1)) || ((num1 < 0) && (num2 < max - num1)))
                {
                    throw overflow_error("overflow");
                } 
                return (num1 * num2); 
            }

        public:
            Fraction();    
            Fraction(int numerator, int denominator);
            Fraction(const float& other);
            Fraction(const Fraction& other);
            Fraction(Fraction&& other) noexcept;
            ~Fraction() = default;

            Fraction& operator=(const Fraction& other);
            Fraction& operator=(Fraction&& other)noexcept;

            int getNumerator()const{return numerator;}
            int getDenominator()const{return denominator;}


            const Fraction operator+(const Fraction& other)const;
            const Fraction operator+(const float& other)const;
            friend const Fraction operator+(const float& one, const Fraction& two);

            const Fraction operator-(const Fraction& other)const;
            const Fraction operator-(const float& other)const;
            friend const Fraction operator-(const float& one, const Fraction& two);

            const Fraction operator*(const Fraction& other)const;
            const Fraction operator*(const float& other)const;
            friend const Fraction operator*(const float& one, const Fraction& two);

            const Fraction operator/(const Fraction& other)const;
            const Fraction operator/(const float& other)const;
            friend const Fraction operator/(const float& one, const Fraction& two);

            bool operator==(const Fraction& other)const;
            bool operator==(const float& other)const;
            friend bool operator==(const float& one, const Fraction& two);

            bool operator>(const Fraction& other)const;
            bool operator>(const float& other)const;
            friend bool operator>(const float& one, const Fraction& two);

            bool operator<(const Fraction& other)const;
            bool operator<(const float& other)const;
            friend bool operator<(const float& one, const Fraction& two);

            bool operator>=(const Fraction& other)const;
            bool operator>=(const float& other)const;
            friend bool operator>=(const float& one, const Fraction& two);
        
            bool operator<=(const Fraction& other)const;
            bool operator<=(const float& other)const;
            friend bool operator<=(const float& one, const Fraction& two);

            Fraction& operator+=(const Fraction& other);
            Fraction& operator-=(const Fraction& other);

            Fraction& operator++();
            const Fraction operator++(int postfix_increment);

            Fraction& operator--();
            const Fraction operator--(int postfix_decrement);    

            friend std::ostream& operator<<(std::ostream& oss, const Fraction& obj);
            friend std::istream& operator>>(std::istream& iss, Fraction& obj);
    };
}