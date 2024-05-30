#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    // 加法运算符重载
    friend Complex operator+(const Complex &c1, const Complex &c2)
    {
        Complex result;
        result.real = c1.real + c2.real;
        result.imag = c1.imag + c2.imag;
        return result;
    }

    // 减法运算符重载
    friend Complex operator-(const Complex &c1, const Complex &c2)
    {
        Complex result;
        result.real = c1.real - c2.real;
        result.imag = c1.imag - c2.imag;
        return result;
    }

    void show() const{
        if(imag>0){
            cout<<real<<"+"<<imag<<"i"<<endl;
        }
        else{
            cout<<real<<imag<<"i"<<endl;
        }
    }

private:
    double real;
    double imag;
};

int main()
{
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);

    Complex addition = c1 + c2;
    Complex subtraction = c1 - c2;

    cout << "addition:";
    addition.show();
    cout<<"subtraction:";
    subtraction.show();
    return 0;
}