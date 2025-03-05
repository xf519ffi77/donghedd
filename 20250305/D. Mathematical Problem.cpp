#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n;
	string s;
	cin >> n >> s;
	if (n == 2) cout << (s[0] - '0') * 10 + (s[1] - '0') << endl;
	else if (n == 3)
	{
		int a = s[0] - '0', b = a * 10 + (s[1] - '0'), c = s[2] - '0', d = (s[1] - '0') * 10 + c;
		cout << min({a + d, a * d, b + c, b * c}) << endl;
	}
	else
	{
		int cnt = 0, ans = 1e9, flag;
		for (int i = 0; i < n; i ++ )
			if (s[i] == '0')
			{
				cout << "0\n";
				return;
			}
		for (int i = 0; i < n - 1; i ++ )
		{
			int res = 0;
			for (int j = 0; j < n; j ++ )
			{
				int now = s[j] - '0';
				if (j == i) now = now * 10 + (s[++ j] - '0');
				if (now != 1) res += now;
			}
			ans = min(ans, res);
		}
		cout << ans << endl;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
