#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 110;
int n, m;
int a[N][N], f[N][N];
void solve()
{
	memset(f, 0, sizeof(f));
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> a[i][j];
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
	cout << f[n][m] << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
