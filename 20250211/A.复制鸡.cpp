#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	unordered_set<int> s;
	for (int i = 0; i < n; i ++ )
	{
		cin >> a[i];
		if (!i || !s.count(a[i]))
		{
			s.insert(a[i]);
			ans ++ ;
		}
		else
		{
			if (a[i] != a[i - 1]) ans ++ ;
		}
	}
	cout << ans << endl; 
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
