#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL o[10] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
void solve()
{
	LL n;
	cin >> n;
	string s = to_string(n);
	if (s.find('7') != string::npos)
	{
		cout << 0 << endl;
		return;
	}
	int ans = 9;
	for (int i = 1; i <= 9; i ++ )
		for (int j = 1; j <= 9; j ++ )
		{
			s = to_string(n + o[i] * j);
			if (s.find('7') != string ::npos) ans = min(ans, j);
		}
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
