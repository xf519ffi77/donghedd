#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 200010;
struct Query
{
	int x, id;
};
void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n), f(n, 0x3f3f3f3f), ans(q);
	vector<vector<Query>> qs(n);
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	for (int i = 0; i < q; i ++ )
	{
		int r, x;
		cin >> r >> x;
		r -- ;
		qs[r].push_back({x, i});
	}
	for (int i = 0; i < n; i ++ )
	{
		int t = lower_bound(f.begin(), f.end(), a[i]) - f.begin();
		f[t] = a[i];
		for (auto q : qs[i])
			ans[q.id] = upper_bound(f.begin(), f.end(), q.x) - f.begin();
	}
	for (int i = 0; i < q; i ++ ) cout << ans[i] << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}


//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//const int N = 200010;
//struct Query
//{
//	int x, id;
//};
//void solve()
//{
//	int n, q;
//	cin >> n >> q;
//	vector<int> a(n + 1), ans(q + 1, 0);
//	vector<int> t(n + q + 1);
//	vector<vector<Query>> qs(n + 1);
//	for (int i = 1; i <= n; i ++ ) cin >> a[i];
//	for (int i = 1; i <= q; i ++ )
//	{
//		int r, x;
//		cin >> r >> x;
//		qs[r].push_back({x, i});
//	}
//	// ¿Î…¢ªØ 
//	auto disc = [&]()
//	{
//		vector<int> alls;
//		for (int i = 1; i <= n; i ++ )
//			alls.push_back(a[i]);
//		for (int i = 1; i <= n; i ++ )
//			for (auto q : qs[i])
//				alls.push_back(q.x);
//		sort(alls.begin(), alls.end());
//		alls.erase(unique(alls.begin(), alls.end()), alls.end());
//		for (int i = 1; i <= n; i ++ )
//			a[i] = lower_bound(alls.begin(), alls.end(), a[i]) - alls.begin() + 1;
//		for (int i = 1; i <= n; i ++ )
//			for (auto &q : qs[i])
//				q.x = lower_bound(alls.begin(), alls.end(), q.x) - alls.begin() + 1;
//	};
//	auto lowbit = [&](int x)
//	{
//		return x & -x;
//	};
//	auto update = [&](int x, int c)
//	{
//		for (int i = x; i <= n + q + 1; i += lowbit(i)) t[i] = max(t[i], c);
//	};
//	auto get_max = [&](int x)
//	{
//		int ans = 0;
//		for (int i = x; i >= 1; i -= lowbit(i)) ans = max(ans, t[i]);
//		return ans;
//	};
//	disc();
//	for (int i = 1; i <= n; i ++ )
//	{
//		int cur = get_max(a[i] - 1) + 1;
//		update(a[i], cur);
//		for (auto q : qs[i])
//			ans[q.id] = get_max(q.x);
//	}
//	for (int i = 1; i <= q; i ++ )
//		cout << ans[i] << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
////	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}
