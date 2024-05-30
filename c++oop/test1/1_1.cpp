#include<iostream>
using namespace std;
const double PI=3.14;
class circle{
private:
    double r=0;
public:
    void initr(double);
    double circumference();
    double area();
};
void circle::initr(double a){
    r=a;
}
double circle::circumference(){
    return 2*PI*r;
}
double circle::area(){
    return PI*r*r;
}
int main(void){
    double r;
    circle o;
    cout<<"请输入半径："<<endl;
    cin>>r;
    o.initr(r);
    cout<<"周长是："<<o.circumference()<<"，面积是："<<o.area();
    return 0;
}
