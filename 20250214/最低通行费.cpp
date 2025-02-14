#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 110;
int n;
int a[N][N], f[N][N];
void solve()
{
	memset(f, 0, sizeof(f));
	cin >> n;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			cin >> a[i][j];
	for (int i = 1; i <= n; i ++ )
	{
		f[1][i] = f[1][i - 1] + a[1][i];
		f[i][1] = f[i - 1][1] + a[i][1];
	}
	for (int i = 2; i <= n; i ++ )
		for (int j = 2; j <= n; j ++ )
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
	cout << f[n][n] << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
