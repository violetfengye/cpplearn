#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
private:
    double a, b, c;

public:
    Triangle(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}
    friend istream &operator>>(istream &in, Triangle &t)
    {
        in >> t.a >> t.b >> t.c;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Triangle &t)
    {
        double p = (t.a + t.b + t.c) / 2;
        double s = sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
        out << "Triangle: a = " << t.a << ", b = " << t.b << ", c = " << t.c << ", area = " << s << endl;
        return out;
    }
};

int main()
{
    Triangle t1, t2;
    cout << "Please input the sides of triangle 1: ";
    cin >> t1;
    cout << "Please input the sides of triangle 2: ";
    cin >> t2;
    cout << "Triangle 1: " << t1;
    cout << "Triangle 2: " << t2;
    return 0;
}