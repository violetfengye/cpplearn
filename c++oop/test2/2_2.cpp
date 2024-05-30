#include "2_2.h"
int main(void){
     string new_studentName;
     string new_studentSchool;
     string new_phoneNum;
     string new_mailBox;
     AddressBook stu[4];
     for (int i = 0; i <= 3; i++)
     {
          cout << "输入姓名：";
          cin >> new_studentName;
          cout << "输入学校：";
          cin >> new_studentSchool;
          cout << "输入电话号码：";
          cin >> new_phoneNum;
          cout << "输入邮箱：";
          cin >> new_mailBox;
          AddressBook temp(new_studentName, new_studentSchool, new_phoneNum, new_mailBox);
          stu[i] = temp;
          cout << endl;
     }
     for (int i = 0; i <= 3; i++)
          stu[i].print();
     return 0;
}
