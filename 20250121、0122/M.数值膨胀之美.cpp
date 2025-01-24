#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
const int N = 100010;
int n;
int a[N];
vector<PII> v;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++ )
	{
		cin >> a[i];
		v.push_back({a[i], i});
	}
	sort(v.begin(), v.end());
//	for (auto x : v) cout << x.first << ' ' << x.second << endl;
	v.push_back({2e+9, n});
	int l = v[0].second, r = v[0].second;
	int Max = max(v[0].first * 2, v[n - 1].first);
	int ans = Max - min(v[0].first * 2, v[1].first);
	for (int i = 1; i < n; i ++ )
	{
		while (v[i].second < l)
		{
			l -- ;
			Max = max(Max, a[l] * 2);
		}
//        cout << l << endl;
		while (v[i].second > r)
		{
			r ++ ;
			Max = max(Max, a[r] * 2);
		}
//        cout << r << endl;
		ans = min(ans, Max - min(v[0].first * 2, v[i + 1].first));
	}
	cout << ans << endl;
	return 0;
}

// 枚举优化，排序/stl/线段树/ST表