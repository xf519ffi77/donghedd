#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n, ans = 0, l, r;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i ++ ) cin >> a[i], mp[a[i]] ++ ;
	for (int i = 0, j = 0; i < n && j < n; i ++ , j ++ )
	{
		if (mp[a[i]] > 1) continue;
		while (mp[a[j]] == 1 && j < n) j ++ ;
		if (j - i > ans)
		{
			ans = j - i;
			l = i + 1, r = j;
		}
		i = j;
	}
	if (ans == 0) cout << 0 << endl;
	else cout << l << ' ' << r << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}

