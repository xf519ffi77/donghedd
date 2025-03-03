#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
bool cmp(PII a, PII b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
void solve()
{
	int n, ans = 0x3f3f3f3f;
	cin >> n;
	vector<int> a(n + 1);
	unordered_map<int, vector<int>> b;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		b[a[i]].push_back(i);
	}
	for (auto t : b)
	{
		auto c = t.second;
		if (c.size() <= 1) continue;
		for (int i = 0, j = 1; j < c.size(); i ++ , j ++ ) ans = min(ans, c[j] - c[i] + 1);
	}
	if (ans == 0x3f3f3f3f) cout << -1 << endl;
	else cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
