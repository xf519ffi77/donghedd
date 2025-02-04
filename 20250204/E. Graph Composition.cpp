#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
const int N = 200010;
int p1[N], p2[N];
int find1(int x)
{
	if (p1[x] != x) p1[x] = find1(p1[x]);
	return p1[x];
}
int find2(int x)
{
	if (p2[x] != x) p2[x] = find2(p2[x]);
	return p2[x];
}
void solve()
{
	int n, m1, m2, ans = 0;
	cin >> n >> m1 >> m2;
	vector<PII> e1(m1), e2(m2); 
	for (int i = 1; i <= n; i ++ ) p1[i] = p2[i] = i;
	for (int i = 0; i < m1; i ++ )
	{
		int u, v;
		cin  >> u >> v;
		e1[i] = {u, v};	
	}
	for (int i = 0; i < m2; i ++ )
	{
		int u, v;
		cin >> u >> v;
		e2[i] = {u, v};
	}
	for (auto e: e2)
	{
		int u = e.first, v = e.second;
		int x = find2(u), y = find2(v);
		if (x == y) continue;
		p2[x] = y;
	}
	for (auto e: e1)
	{
		int u = e.first, v = e.second;
		int x = find2(u), y = find2(v);
		if (x == y)
		{
			int x = find1(u), y = find1(v);
			if (x == y) continue;
			p1[x] = y;
		}
		else ans ++ ;
	}
	for (auto e: e2)
	{
		int u = e.first, v = e.second;
		int x = find1(u), y = find1(v);
		if (x == y) continue;
		ans ++ ;
		p1[x] = y;
	}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}

