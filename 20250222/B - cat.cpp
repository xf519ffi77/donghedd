#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}
void solve()
{
	int n;
	cin >> n;
	vector<pair<int, string>> v(n);
	for (int i = 0; i < n; i ++ )
	{
		string s;
		cin >> s;
		int n = s.size();
		v[i] = {n, s};
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i ++ ) cout << v[i].second;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
