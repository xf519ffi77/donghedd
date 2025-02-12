#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<int> a(m);
	unordered_map<int, int> mp;
	for (int i = 0; i < m; i ++ )
	{
		cin >> a[i];
		mp[a[i]] ++ ;
		cnt ++ ;
	}
	cout << n - cnt << endl;
	for (int i = 1; i <= n; i ++ )
		if (!mp[i]) cout << i << ' ';
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
