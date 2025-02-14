#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 11;
int n;
int a[N][N], f[N * 2][N][N];
void solve()
{
	memset(f, 0, sizeof(f));
	cin >> n;
	int i, j, v;
	while (cin >> i >> j >> v, i && j && v) a[i][j] = v;
	for (int k = 2; k <= n  * 2; k ++ )
		for (int i1 = 1; i1 <= n; i1 ++ )
		{
			if (i1 > k || k - i1 > n) continue;
			for (int i2 = 1; i2 <= n; i2 ++ )
			{
				if (i2 > k || k - i2 > n) continue;
				f[k][i1][i2] = max(max(f[k - 1][i1 - 1][i2 - 1], f[k - 1][i1 - 1][i2]), max(f[k - 1][i1][i2 - 1], f[k - 1][i1][i2]));
				if (i1 == i2) f[k][i1][i2] += a[i1][k - i1];
				else f[k][i1][i2] += a[i1][k - i1] + a[i2][k - i2];
			}
		}
	cout << f[2 * n][n][n] << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
