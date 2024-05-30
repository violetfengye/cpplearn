//That is '2_2.h' file.
#include<bits/stdc++.h>
using namespace std;
class AddressBook{
private:
    string studentName,studentSchool,phoneNum,mailBox;
public:
    AddressBook(string name = "李四", string school = "哈佛大学", string phonenumber = "021-5201314", string mailbox = "1314520");
    string GetName();
    string GetSchool();
    string GetNum();
    string GetBox();
    void print();
    ~AddressBook(){cout<<"ending..."<<endl;};
};
string AddressBook::GetName() { return studentName; }
string AddressBook::GetSchool() { return studentSchool; }
string AddressBook::GetNum() { return phoneNum; }
string AddressBook::GetBox() { return mailBox; }
AddressBook::AddressBook(string name,string school,string phonenumber,string mailbox){
    studentName=name;
    studentSchool=school;
    phoneNum=phonenumber;
    mailBox=mailbox;
}
void AddressBook::print(){
    cout << studentName << " "
         << studentSchool << " "
         << phoneNum << " "
         << mailBox << endl;
}
