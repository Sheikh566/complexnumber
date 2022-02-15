#include <iostream>
#include <string>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber::ComplexNumber() {}
ComplexNumber::ComplexNumber(double real, double imaginary) {
    r = real;
    i = imaginary;
}
ComplexNumber::ComplexNumber(const ComplexNumber& vec) {
    r = vec.r;
    i = vec.i;
}
void ComplexNumber::show() {
    cout << to_string(r) << " + (" << to_string(i) << "i)" << endl;
}
ComplexNumber ComplexNumber::add(ComplexNumber other) {
    double real_part = r + other.r;
    double imaginary_part = i + other.i;
    return ComplexNumber(real_part, imaginary_part);
}
ComplexNumber ComplexNumber::subtract(ComplexNumber other) {
    double real_part = r - other.r;
    double imaginary_part = i - other.i;
    return ComplexNumber(real_part, imaginary_part);
}
ComplexNumber ComplexNumber::multiply(ComplexNumber other) {
    double imaginary_part = (r * other.i) + (i * other.r);
    double real_part = (r * other.r) + -(i * other.i);
    return ComplexNumber(real_part, imaginary_part);
}
ComplexNumber ComplexNumber::divide(ComplexNumber other) {
    ComplexNumber conjugate(other.r, -other.i);
    ComplexNumber nominator = conjugate.multiply(ComplexNumber(r, i));
    ComplexNumber denominator = conjugate.multiply(other); // Here imaginary part will be zero
    double real_part = nominator.r/denominator.r;
    double imaginary_part = nominator.i/denominator.r; // Fractional part will dropped due to integer division
    return ComplexNumber(real_part, imaginary_part);
}

int main() {
    ComplexNumber a(3, 2);
    ComplexNumber b(4, -5);
    ComplexNumber result = a.add(b);
    result.show();
    return 0;
}