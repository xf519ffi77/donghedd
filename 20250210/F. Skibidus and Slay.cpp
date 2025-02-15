#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> e(n + 1);
	string s = string(n, '0');
	for (int i = 0; i < n; i ++ ) cin >> a[i], a[i] -- ;
	for (int i = 0; i < n - 1; i ++ )
	{
		int u, v;
		cin >> u >> v;
		u -- , v -- ;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 0; i < n; i ++ )
	{
		map<int, int> mp;
		for (auto u : e[i]) mp[a[u]] ++ ;
		mp[a[i]] ++ ;
		for (const auto& item : mp)
    		if (item.second >= 2) s[item.first] = '1';
//      C++17结构化绑定 
//    	for (auto [a, b] : mp)
//    		if (b >= 2) s[a] = '1';
	}
	cout << s << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
