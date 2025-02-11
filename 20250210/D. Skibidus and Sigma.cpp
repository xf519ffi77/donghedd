#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
bool cmp(int a, int b)
{
	return a > b;
}
void solve()
{
	int n, m;
	LL ans = 0;
	cin >> n >> m;
	vector<LL> s(n);
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < m; j ++ )
		{
			LL t;
			cin >> t;
			s[i] += t;
			ans += (m - j) * t;
		}
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < n; i ++ )
		ans += s[i] * m * (n - 1 - i);
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
