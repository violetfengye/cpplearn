#include<bits/stdc++.h>
using namespace std;
class A{
    private:
        int a;
    public:
        A(int x):a(x){}
        A(const A &x){
            a = 2*x.a;
        }
        void show(){
            cout << a << endl;
        }
};
void f1(A a){
    A b = a;
    b.show();
}
void f2(const A &a){//常引用不会调用拷贝构造函数且该对象无法被修改
    A b = a;
    b.show();
}
int main(void){
    A x(5);
    f1(x), f2(x);
    return 0;
}