#include<iostream>
#include<cmath>
using namespace std;
const double PI=3.14;
class A{
private:
    int r;
    int d=3;
public:
    A(int);
    double value();
};
A::A(int a){r=a;}
double A::value(){
    double v1,v2;
    v1=35*2*PI*(r+d);
    v2=20*PI*(pow(r+d,2)-r*r);
    return v1+v2;
}
int main(void){
    int n;
    cin>>n;
    A yc(n);
    cout<<yc.value();
    return 0;
}
