#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), t(n + 1, 0), ans(n + 1);
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	auto lowbit = [&](int x)
	{
		return x & -x;
	};
	auto add = [&](int x, int c)
	{
		for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
	};
	auto sum = [&](int x)
	{
		int res = 0;
		for (int i = x; i >= 1; i -= lowbit(i)) res += t[i];
		return res;
	};
	for (int i = n; i >= 1; i -- )
	{
		int l = 1, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (mid - sum(mid) >= a[i]) r = mid;
			else l = mid + 1;
		}
		ans[l] = i;
		add(l, 1);
	}
	for (int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();	
	return 0;
}
