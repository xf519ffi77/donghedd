#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
int n;
LL ans;
string s;
void dfs (int u)
{
	if (u == n + 1)
	{
		for (int i = 1; i <= n; i ++ )
		{
			int cnt1 = 0, cnt2 = 0;
			char c = s[i];
			if  (s[i] == '1') s[i] = '0';
            else s[i] = '1';
			for(int i = 1; i < n; i ++ )
			{
				if (s[i] == '0' && s[i + 1] == '1') cnt1 ++ ;
				if (s[i] == '1' && s[i + 1] == '0') cnt2 ++ ;
			}
			if (cnt1 == cnt2) ans = (ans + 1) % mod;
			s[i] = c;
		}
		return;
	}
	if (s[u] == '?')
	{
		s[u] = '0';
		dfs(u + 1);
		s[u] = '1';
		dfs(u + 1);
		s[u] = '?';
	}
	else dfs(u + 1);
}
void solve()
{
	ans = 0;
	cin >> n >> s;
	s = " " + s;
	dfs(1);
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
