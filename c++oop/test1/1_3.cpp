#include<iostream>
using namespace std;
class score{
double english_score;
public:
    void setscore(double);
    void printscore();
};
void score::setscore(double number){
    english_score=number;
}
void score::printscore(){
    cout<<"english score is "<<english_score<<"."<<endl;
}
int main(void){
    score stu1,stu2;
    stu1.setscore(85.5);
    stu2.setscore(93.5);
    cout<<"Stu1'";
    stu1.printscore();
    cout<<"Stu2'";
    stu2.printscore();
    return 0;
}
