#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
void solve()
{
	int n, m;
	cin >> n >> m;
	set<PII> s;
	for (int i = 0; i < m; i ++ )
	{
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (u != v) s.insert({u, v});
	}
	cout << m - s.size() << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
