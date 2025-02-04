#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 200010;
int a[N];
void solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0;
	while (l < r)
	{
		if (a[l] + a[r] == k)
		{
			l ++ ;
			r -- ;
			ans ++ ;
		}
		else if (a[l] + a[r] > k) r -- ;
		else l ++ ;
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
