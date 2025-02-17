#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n;
	string s;
	cin >> n >> s;
	int t = -1, ans = 1;
	for (int i = 0; i < n; i ++ )
		if (s[i] == '1')
		{
			t = i;
			break;
		}
	if (t == -1)
	{
		cout << 0 << endl;
		return;
	}
	bool flag = 1;
	if (s[n - 1] == '0')
	{
		flag = 0;
		ans ++ ;
	}
	for (int i = n - 1; i > t; i -- )
	{
		if (!flag && s[i] == '1') flag = 1;
		if (flag && s[i] == '0')
		{
			flag = 0;
			ans += 2;
		}
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
