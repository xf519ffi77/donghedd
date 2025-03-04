#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve()
{
	int n;
	cin >> n;
	vector<LL> x(n + 1), s(n + 1, 0);
	for (int i = 1; i <= n; i ++ ) cin >> x[i];
	vector<LL> y = x;
	sort(x.begin() + 1, x.end());
	for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + x[i];
	for (int i = 1; i <= n; i ++ )
	{
		LL ans = 0;
		int t = lower_bound(x.begin() + 1, x.end(), y[i]) - x.begin();
		cout << (t - 1) * y[i] - s[t - 1] + s[n] - s[t - 1] - (n - t + 1) * y[i] + n << " ";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
