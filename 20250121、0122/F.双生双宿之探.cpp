#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
int a[N];
bool check(int a, set<int> s)
{
	if (s.size() <= 1) return true;
	return s.count(a);
}
void solve()
{
	int n;
	LL ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= n; i ++ )
	{
		int j = i;
		set<int> s;
		s.insert(a[i]);
		while (j + 1 <= n && check(a[j + 1], s)) s.insert(a[ ++ j]);
		if (s.size() == 1) break;
		map<int, int> mp;
		mp[0] = 1;
		int sum = 0;
		for (int k = i; k <= j; k ++ )
		{
			sum += (a[k] == a[i] ? 1 : -1);
			ans += mp[sum];
			mp[sum] ++ ;
		}
		int t = j;
		while (t - 1 >= i && a[t - 1] == a[j]) t -- ;
		i = t - 1;
	}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}

// 双指针，前缀和，map