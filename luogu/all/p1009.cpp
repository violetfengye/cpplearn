#include <bits/stdc++.h>
using namespace std;
const int nn = 10005;
string jc(int n)
{
    string s;
    int a[nn]{1};
    for (int i = 1; i <= n; i++)
    {
        int carry{};
        for (int j = 0; j < nn; j++)
        {
            a[j] = a[j] * i + carry;
            carry = a[j] / 10;
            a[j] %= 10;
        }
    }
    int last;
    for (int i = nn - 1; i >= 0; i--)
    {
        if (a[i])
        {
            last = i;
            break;
        }
    }
    for (int i = last; i >= 0; i--)
    {
        s += a[i] + '0';
    }
    return s;
}
string add(string a, string b)
{
    string s;
    int c{};
    for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0 || c > 0; i--, j--)
    {
        if (i >= 0)
            c += a[i] - '0';
        if (j >= 0)
            c += b[j] - '0';
        s += c % 10 + '0';
        c = c / 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(void)
{
    int n;
    cin >> n;
    string ans;
    for (int i = 1; i <= n; i++)
    {
        string temp = jc(i);
        ans = add(ans, temp);
    }
    cout << ans;
    return 0;
}
