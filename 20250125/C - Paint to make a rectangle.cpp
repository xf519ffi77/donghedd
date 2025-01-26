#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int n, m;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i ++ ) cin >> s[i];
	int l = m, r = 0, u = n, d = 0;
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < m; j ++ )
			if (s[i][j] == '#')
			{
				l = min(l, j);
				r = max(r, j);
				u = min(u, i);
				d = max(d, i);
			}
	for (int i = u; i <= d; i ++ )
		for (int j = l; j <= r; j ++ )
			if (s[i][j] == '.')
			{
				cout << "No" << endl;
				return 0;
			}
	cout << "Yes" << endl;
	return 0;
}
