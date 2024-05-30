#include<iostream>
using namespace std;
const double PI=3.14;
class column{
    double r,h;
public:
    column(double,double);
    double S();
    double V();
    ~column() { cout << "执行析构函数" << endl; }
};
column::column(double a,double b){r=a;h=b;}
double column::S(){return 2*PI*r*r+2*PI*r*h;}
double column::V(){return PI*r*r*h;}
int main(void){
    column c(2,3);
    cout<<"S="<<c.S()<<",V="<<c.V()<<endl;
    return 0;
}
