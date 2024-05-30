#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int bz[N][20];
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin>>bz[i][0];
    }
    for (int j = 1; j <= 18; j++)//对于这个二维数组，它是先竖着算
    {
        for (int i = 1; i <= n; i++)
        {
            if ((i + (1 << (j - 1))) <= n)
            {
                bz[i][j] = max(bz[i][j - 1], bz[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    while (m--)
    {
        cin >> l >> r;
        int p = log2(r - l + 1);
        cout << max(bz[l][p], bz[r + 1 - (1 << p)][p]);
        cout << "\n";
    }
    return 0;
}