#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(1,3), b(2,6);
    float c =4.567;
    cout << "a:" << a << ",b:" << b << endl;
    cout << "a+b:" << a+b << endl; 
    cout << "a-b:" << a-b << endl; 
    cout << "a/b:" << a/b << endl; 
    cout << "a*b:" << a*b << endl; 
    cout << "2.3*b:" << 2.3*b << endl; 
    cout << "a+2.421:" << a+2.421 << endl; 
    cout << ++a << endl;
    cout << b-- << endl;

    cout << "a: " << a << ",c: " << c << endl;
    cout << "a+c:" << a+c << endl; 
    cout << "a-c:" << a-c << endl; 
    cout << "c/a:" << c/a << endl; 
    cout << "c*a:" << c*a << endl;

    cout << "a:" << a << endl;
    cout << "a+=b:" << (a+=b) << endl; 
    cout << "a-=b:" << (a-=b) << endl; 

    Fraction d(-2,3);
    Fraction e(-5,6);
    cout << "d >=e ? : " << (d >= e) << endl;
    (d > -0.555)? (cout << " d is bigger than -0.555" << endl): (cout << " d is smaller than -0.555" << endl);
}
