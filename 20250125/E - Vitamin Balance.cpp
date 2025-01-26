#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5010;
int n, x, ans;
int f[N][4];
int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i ++ )
	{
		int v, a, c;
		cin >> v >> a >> c;
		for (int j = x; j >= c; j -- ) f[j][v] = max(f[j][v], f[j - c][v] + a);
	}
//	for (int i = 1; i <= 3; i ++ )
//		for (int j = 1; j <= x; j ++ )
//			f[j][i] = max(f[j][i], f[j - 1][i]);
	for (int i = 0; i <= x; i ++ )
		for (int j = 0; i + j <= x; j ++ )
			ans = max(ans, min(min(f[i][1], f[j][2]), f[x - i - j][3]));
	cout << ans << endl;
    return 0;
}
