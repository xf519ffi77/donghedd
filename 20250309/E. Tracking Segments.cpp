//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//typedef long long LL;
//typedef pair<int, int> PII;
//const int mod = 1e9 + 7;
//void solve()
//{
//	int n, m, q, lastmid = 0;
//	cin >> n >> m;
//	map<PII, int> mp;
//	map<int, int> st;
//	while (m -- )
//	{
//		int l, r;
//		cin >> l >> r;
//		if (mp[{l, r}]) continue;
//		mp[{l, r}] = (r - l + 1) / 2 + 1;
//	}
//	cin >> q;
//	vector<int> ass(q + 1);
//	vector<int> t(n + 1, 0);
//	for (int i = 1; i <= q; i ++ ) cin >> ass[i];
//	auto lowbit = [&](int x)
//	{
//		return x & -x;
//	};
//	auto add = [&](int x, int c)
//	{
//		for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
//	};
//	auto sum = [&](int x)
//	{
//		int res = 0;
//		for (int i = x; i >= 1; i -= lowbit(i)) res += t[i];
//		return res;
//	};
//	auto get = [&](int l, int r)
//	{
//		return sum(r) - sum(l - 1);
//	};
//	auto check = [&](int x)
//	{
//		for (int i = lastmid + 1; i <= x; i ++ )
//		{
//			if (!st[ass[i]]) add(ass[i], 1);
//			st[ass[i]] ++ ;
//		}
//		for (auto t : mp)
//		{
//			auto l = t.first.first, r = t.first.second, res = t.second;
//			if (get(l, r) >= res) return true; 
//		}
//		return false;
//	};
//	int l = 1, r = q;
//	while (l < r)
//	{
//		int mid = l + r >> 1;
//		if (lastmid > mid)
//		{
//			for (int i = mid + 1; i <= lastmid; i ++ )
//			{
//				st[ass[i]] -- ;
//				if (!st[ass[i]]) add(ass[i], -1);
//			}
//		}
//		if (check(mid)) r = mid;
//		else l = mid + 1;
//		lastmid = mid;
//	}
//	if (!check(l)) l = -1; 
//	cout << l << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}


#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
void solve()
{
	int n, m, q;
	cin >> n >> m;
	map<PII, int> mp;
	while (m -- )
	{
		int l, r;
		cin >> l >> r;
		if (mp[{l, r}]) continue;
		mp[{l, r}] = (r - l + 1) / 2 + 1;
	}
	cin >> q;
	vector<int> ass(q + 1);
	for (int i = 1; i <= q; i ++ ) cin >> ass[i];
	auto check = [&](int x)
	{
		vector<int> s(n + 1);
		for (int i = 1; i <= x; i ++ ) s[ass[i]] = 1;
		for (int i = 1; i <= n; i ++ ) s[i] += s[i - 1];
		for (auto t : mp)
		{
			auto l = t.first.first, r = t.first.second, res = t.second;
			if (s[r] - s[l - 1] >= res) return true;
		}
		return false;
	};
	int l = 1, r = q;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (!check(l)) l = -1; 
	cout << l << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}

