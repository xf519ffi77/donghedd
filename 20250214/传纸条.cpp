#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 51;
int n, m;
int a[N][N], f[N * 2][N][N];
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> a[i][j];
	for (int k = 2; k <= n + m; k ++ )
		for (int i1 = 1; i1 <= n; i1 ++ )
		{
			if  (i1 > k || k - i1 > m) continue;
			for (int i2 = 1; i2 <= n; i2 ++ )
			{
				if (i2 > k || k - i2 > m) continue;
				f[k][i1][i2] = max(max(f[k - 1][i1][i2], f[k - 1][i1][i2 - 1]), max(f[k - 1][i1 - 1][i2], f[k - 1][i1 - 1][i2 - 1]));
				f[k][i1][i2] += a[i1][k - i1];
				if (i1 != i2) f[k][i1][i2] += a[i2][k - i2];
			}
		}
	cout << f[n + m][n][n] << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
