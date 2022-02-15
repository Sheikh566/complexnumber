#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber{
    public:
        double r, i;
        ComplexNumber();
        ComplexNumber(double real, double imaginary);
        ComplexNumber(const ComplexNumber& vec);
        void show();
        ComplexNumber add(ComplexNumber other);
        ComplexNumber subtract(ComplexNumber other);
        ComplexNumber multiply(ComplexNumber other);
        ComplexNumber divide(ComplexNumber other);
};
#endif
