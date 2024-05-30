#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    // 乘法运算符重载
    Complex operator*(const Complex &other) const
    {
        Complex result;
        result.real = this->real * other.real - this->imag * other.imag;
        result.imag = this->real * other.imag + this->imag * other.real;
        return result;
    }

    // 除法运算符重载
    Complex operator/(const Complex &other) const
    {
        double divisor = other.real * other.real + other.imag * other.imag;
        Complex result;
        result.real = (this->real * other.real + this->imag * other.imag) / divisor;
        result.imag = (this->imag * other.real - this->real * other.imag) / divisor;
        return result;
    }

    void show() const
    {
        if (imag > 0) { cout << real << "+" << imag << "i" << endl; }
        else { cout << real << imag << "i" << endl; }
    }

private:
    double real;
    double imag;
};

int main()
{
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);

    Complex multiply = c1 * c2;
    Complex divide = c1 / c2;

    cout << "multiply:";
    multiply.show();
    cout << "divide:";
    divide.show();

    return 0;
}