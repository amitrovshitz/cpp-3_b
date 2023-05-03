/**
 * Demo file for the Fraction Class.
 *
 * @author Amit Rovshitz
 * @since 2023-05
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    // operators on 2 fraction.
    Fraction a(1,3), b(2,6);
    cout << "a:" << a << " b:" << b << endl;
    cout << "a+b:" << a+b << endl; 
    cout << "a-b:" << a-b << endl; 
    cout << "a/b:" << a/b << endl; 
    cout << "a*b:" << a*b << endl; 

    // operators on one fraction and one float (both side).
    float c = 0.321;
    cout << "b:" << b << " c:" << c << endl;
    cout << "b*c:" << b*c << endl;
    cout << "c*b:" << c*b << endl;  
    cout << "b/c:" << b*c << endl; 
    cout << "c/b:" << c*b << endl; 
    cout << "b+c:" << b*c << endl; 
    cout << "c+b:" << c*b << endl; 
    cout << "b-c:" << b*c << endl; 
    cout << "c-b:" << c*b << endl; 

    //operators on one fraction.
    cout << "a:" << a << endl;
    cout << "++a:" << ++a << endl;
    cout << "--a:" << --a << endl;
    cout << "a++:" << a++ << endl;
    cout << "a--:" << a-- << endl;
    cout << "a+=:" << (a+=b) << endl;
    cout << "a-=:" << (a-=b) << endl;
    
    //comparition and prints.
    cout << "c >=b ? : " << (c >= b) << endl;
    cout << "a:" << a << endl;
    if (a > -0.333) cout << " a is bigger than  -0.333" << endl;
    else cout << " a is smaller than -0.333" << endl;
    cout << "c == b ? : " << (c == b) << endl;
    if (-0.333 < Fraction(1,3)) cout << " -0.333 is smaller than 1/3" << endl;
    else cout << " 1/3 is bigger than -0.333" << endl;
}