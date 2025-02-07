#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 31, mod = 1e9 + 7;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> sa(n + 1, vector<int>(N, 0)); // sa[i][j]记录a数组前i个数中第j位为1的个数 
    vector<vector<int>> sb(n + 1, vector<int>(N, 0)); // sb[i][j]记录b数组前i个数中第j位为1的个数 
    vector<int> s(n + 2, 0);  
    for (int i = 1; i <= n; i ++ )
    {
    	cin >> a[i];
    	sa[i] = sa[i - 1];
    	for (int j = 0; j < N; j ++ )
    		if (a[i] & (1 << j)) sa[i][j] ++ ;
	}
	for (int i = 1; i <= n; i ++ )
	{
		cin >> b[i];
		sb[i] = sb[i - 1];
		for (int j = 0; j < N; j ++ )
			if (b[i] & (1 << j)) sb[i][j] ++ ;
	}
	for (int i = n; i >= 1; i -- )
	{
		s[i] = s[i + 1];
		for (int j = 0; j < N; j ++ )
		{
			int b1 = sb[n][j] - sb[i - 1][j];
			int b0 = (n - i + 1) - b1;
			if (a[i] & (1 << j)) s[i] += (1ll << j) * b0 % mod;
			else s[i] += (1ll << j) * b1 % mod;
            s[i] %= mod;
		}
	}
	while (q -- )
	{
		int l, r;
		cin >> l >> r;
		int ans = (s[l] - s[r + 1]) % mod;
		for (int i = 0; i < N; i ++ )
		{
			int a1 = sa[r][i] - sa[l - 1][i];
			int a0 = (r - l + 1) - a1;
			int b1 = sb[n][i] - sb[r][i];
			int b0 = (n - r) - b1;
            LL t = (LL)a1 * b0 + (LL)a0 * b1;
            ans = (ans - (1 << i) * t) % mod;
            ans = (ans + mod) % mod;
		}
		cout << ans << endl;
	}
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}
