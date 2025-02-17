#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, k, Max = 1;
	cin >> n >> k;
	vector<int> a(n);
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i ++ )
	{
		cin >> a[i];
		mp[a[i]] ++ ;
		Max = max(Max, a[i]);
	}
	vector<int> ans(Max + 1);
	for (int i = 1; i <= Max; i ++ )
	{
		int cnt = 0;
		for (int j = i; j <= Max; j += i) cnt += mp[j];
		if (cnt >= k)
			for (int j = i; j <= Max; j += i) ans[j] = i;
	}
	for (int i = 0; i < n; i ++ )
		cout << ans[a[i]] << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
