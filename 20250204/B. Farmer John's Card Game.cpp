#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2010;
int flag[N];
bool cmp(vector<int> a, vector<int> b)
{
	return a[0] < b[0];
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i ++ )
	{
		for (int j = 0; j < m; j ++ )
		{
			int t;
			cin >> t;
			a[i].push_back(t);
		}
		sort(a[i].begin(), a[i].end());
		flag[a[i][0]] = i + 1;
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < m; j ++ )
			if (i + j * n != a[i][j])
			{
				cout << -1 << endl;
				return;
			}
	for (int i = 0; i < n; i ++ )
		cout << flag[a[i][0]] << ' ';
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
