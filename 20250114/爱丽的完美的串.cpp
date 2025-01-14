#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2010, M = 110;
int f[N][M], s[N];
char c[N];
void solve()
{
	memset(s, 0, sizeof(s));
	memset(f, 0, sizeof(f));
	int k, d;
	cin >> k >> d >> c + 1;
	int n = strlen(c + 1);
	for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + (c[i] == '0');
	for (int i = s[d]; i <= k; i ++ ) f[d][i] = 1;
	for (int i = d + 1; i <= n; i ++ )
		for (int j = 0; j <= k; j ++ )
		{
			if (j >= s[i] - s[i - d]) f[i][j] = f[i - d][j - (s[i] - s[i - d])] + 1;
			f[i][j] = max(f[i][j], f[i - 1][j]);
		}
	int ans = 0;
	for (int i = 0; i <= k; i ++ ) ans = max(ans, f[n][i]);
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve(); 
	return 0;
}
