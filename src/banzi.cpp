#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)//手动开启o2优化
int main(void){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // 提高程序效率，但 "cout<<endl;"应改为 "cout<<"\n" "
}

inline int read() // 快读-22行
{
    int x = 0, f = 1;//x放每个数位，f存储正负
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void write(int x)//快写-32行
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

int gcd(int a, int b)//求最大公约数-37行
{
    return !b ? a : gcd(b, a % b);
}

string gjd_add(string a, string b)//高精度加法-54行
{
    string c; // 用于存储结果
    int d{};  // 存进位
    for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0 || d > 0; i--, j--)
    {
        if (i >= 0)
            d += a[i] - '0'; // 字符转整数
        if (j >= 0)
            d += b[j] - '0';
        c += (d % 10) + '0'; // 将每一位进行拼接
        d /= 10;
    }
    reverse(c.begin(), c.end()); // 将结果倒置成正序
    return c;
}

bool zs(int a)//判断质数-71行
{
    if (a == 0 || a == 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return 0;
            break;
        }
    }
    return 1;
}

ll quick(ll a, ll b)//快速幂-84行
{
    ll ans{1};
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int sieve(int n)//欧拉筛/线性筛质数-105行
{
    int z[10005], vis[10005], ans{};//把这三兄弟放全局
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            z[++ans] = i;
        }
        for (int j = 1; j <= ans && i * z[j] <= n; j++)
        {
            vis[i * z[j]] = 1;
            if (i % z[j] == 0)
            {
                break;
            }
        }
    }
    return ans;
}

string gjd_jc(int n)//高精度阶乘-136行
{
    const int nn = 10005;
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

//矩阵快速幂-172行
const ll mod = 1e9 + 7;
struct sq
{
    ll zj[105][105];
    sq()
    {
        memset(zj, 0, sizeof zj);
    }
};
sq operator*(sq a, sq b)
{
    sq c;
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            for (int k = 0; k < 105; k++)
                c.zj[i][j] = (c.zj[i][j] + a.zj[i][k] * b.zj[k][j] % mod) % mod;
    return c;
}
sq quick_mol(sq c, ll k)
{
    sq ans;
    for (int i = 1; i < 105; i++)
    {
        ans.zj[i][i] = 1;
    }
    while (k)
    {
        if (k & 1)
            ans = ans * c;
        c = c * c;
        k >>= 1;
    }
    return ans;
}