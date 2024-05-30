#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // 写入文件
    ofstream outfile("test.dat");
    if (outfile.is_open())
    {
        // 写入数字
        outfile << "1.2  2.3  4.6" << endl;
        // 写入字符串
        outfile << "Computer Science" << endl;
        outfile << "ECUST" << endl;
        // 关闭文件
        outfile.close();
        cout << "成功写入文件" << endl;
    }
    else
    {
        cout << "打开文件失败" << endl;
        return 0;
    }

    // 读取文件
    ifstream infile("test.dat");
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            cout << line << endl;
        }
        // 关闭文件
        infile.close();
    }
    else
    {
        cout << "打开文件失败" << endl;
        return 0;
    }
    return 0;
}