#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	string s, c;
	vector<int> ind(m);
	cin >> s;
	for (int i = 0; i < m; i ++ ) cin >> ind[i];
	cin >> c;
	sort(ind.begin(), ind.end());
	ind.erase(unique(ind.begin(), ind.end()), ind.end());
	sort(c.begin(), c.end());
	for (int i = 0; i < ind.size(); i ++ )
		s[ind[i] - 1] = c[i];
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
