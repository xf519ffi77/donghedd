#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
bool cmp(PII a, PII b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), b = a;
	vector<PII> c(n + 1);
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= n; i ++ ) cin >> b[i];
	for (int i = 1; i <= n; i ++ ) c[i] = {a[i] - b[i], i};
	sort(c.begin() + 1, c.end(), cmp);
	int cnt = 0, t = c[1].first;
	vector<int> ans;
	for (int i = 1; i <= n;i ++ )
		if (c[i].first == t)
		{
			cnt ++ ;
			ans.push_back(c[i].second);
		}
	cout << cnt << endl;
	for (auto t : ans) cout << t << " ";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
