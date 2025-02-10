#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<LL> a(n), b(m);
	for (auto &t : a) cin >> t;
	for (auto &t : b) cin >> t;
	sort(b.begin(), b.end());
	a[0] = min(a[0], b[0] - a[0]);
	for (int i = 1; i < n; i ++ )
	{
		int t = lower_bound(b.begin(),  b.end(), a[i] + a[i - 1]) - b.begin();
		if (t == m) t -- ;
		if (a[i] < a[i - 1] && b[t] - a[i] < a[i - 1])
		{
			cout << "No" << endl;
			return;
		}
		if (a[i] >= a[i - 1] && b[t] - a[i] >= a[i - 1]) a[i] = min(a[i], b[t] - a[i]);
		if (a[i] < a[i - 1]) a[i] = b[t] - a[i];
	}
	cout << "Yes" << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
