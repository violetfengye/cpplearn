#include <iostream>
#include <iomanip> // 用于设置输出的位宽

using namespace std;

int main()
{
    for (int i = 0; i <= 15; i++)
    {
        cout << "十进制：" << setw(4) << dec << i;
        cout << "    八进制：" << setw(4) << oct << i;
        cout << "    十六进制：" << setw(4) << hex << i << endl;
    }
    return 0;
}