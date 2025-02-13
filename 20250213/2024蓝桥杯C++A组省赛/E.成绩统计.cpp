#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
	int n, k, t;
	cin >> n >> k >> t;
	vector<LL> a(n + 1), s1(n + 1, 0), s2 = s1;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	auto check = [&](int x)
	{
		vector<LL> b = a;
		sort(b.begin() + 1, b.begin() + 1 + x);
		for (int i = 1; i <= x; i ++ )
		{
			s1[i] = s1[i - 1] + b[i];
			s2[i] = s2[i - 1] + b[i] * b[i];
		}
		for (int l = 1, r = k; r <= x; l ++ , r ++ )
			if (k * (s2[r] - s2[l - 1]) - (s1[r] - s1[l - 1]) * (s1[r] - s1[l - 1]) < (ULL)k * k * t) return true;
		return false;
	};
	if (check(n))
	{
		int l = k, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	else cout << -1 << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
