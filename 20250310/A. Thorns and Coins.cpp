#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
void solve()
{
	int n, ans = 0, cnt = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i ++ )
		if (s[i] == '*')
		{
			cnt ++ ;
			if (cnt >= 2) break;
		}
		else
		{
			cnt = 0;
			if (s[i] == '@') ans ++ ;
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
