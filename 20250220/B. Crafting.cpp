#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	for (int i = 0; i < n; i ++ ) cin >> b[i];
	int cnt = -1;
	for (int i = 0; i < n; i ++ )
		if (a[i] < b[i])
		{
			if (cnt != -1)
			{
				cout << "NO\n";
				return;
			}
			cnt = b[i] - a[i];
		}
	for (int i = 0; i < n; i ++ )
		if (a[i] >= b[i] && a[i] - b[i] < cnt)
		{
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
