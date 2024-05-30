#include<iostream>
using namespace std;
class counter{
private:
    int value;
public:
    counter(int);
   void increment();
   void decrement();
   int getvalue();
   void print();
};
counter::counter(int number){value=number;}
void counter::increment(){value++;}
void counter::decrement(){value--;}
int counter::getvalue(){return value;}
void counter::print(){cout<<"计数器的值为 "<<value<<endl;}
int main(void){
  counter ct(0);
  int top,low;
  for(int i=1;i<=20;i++){
    ct.increment();
    ct.print();
    top = ct.getvalue();
  }
   for(int i=1;i<=20;i++){
    ct.decrement();
    ct.print();
    low=ct.getvalue();
   }
   cout<<"top="<<top<<",low="<<low<<endl;
    return 0;
}
