#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
double findx(double l, double r)
{
    double mid{};
    while (fabs(mid - (l + r) / 2) > 1e-4)
    {
        mid = (l + r) / 2;
        if (f(mid) * f(l) < 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return mid;
}
int main(void)
{
    cin >> a >> b >> c >> d;
    double x1 = (-b - sqrt(b * b - 3 * a * c)) / (3 * a), x2 = (-b + sqrt(b * b - 3 * a * c)) / (3 * a);
    cout << fixed << setprecision(2) << findx(-100, x1) << " " << findx(x1, x2) << " " << findx(x2, 100);
    return 0;
}