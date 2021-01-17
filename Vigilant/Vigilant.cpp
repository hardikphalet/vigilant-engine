#include "Polynomial.h"
#include <iostream>

int main()
{
    std::cout << "Vigilant starting..." << std::endl;
    Polynomial poly(2);
    double arr[] = {
        1.0, -2.0, 1.0
    };
    poly.setCoeff(arr);
    std::cout << "Value of polynomial at 1 is " << poly.valueAt(1.1) << std::endl;
    std::cout << "Value of polynomial at 1 is " << poly.valueAt(2) << std::endl;
                                              
    std::cout << "Value of derivative at 1 is " << poly.derivative().valueAt(1) << std::endl;
    std::cout << "Value of derivative at 1 is " << poly.derivative().valueAt(2) << std::endl;
    std::cout << "Zero of the given Polynomial is " << poly.newtonRaphson(1.1) << std::endl;

    std::cout << "Program has ended. Please press enter to exit." << std::endl;
    std::cin.get();
    return 0;
}