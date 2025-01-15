#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, m, cnt1 = 0, cnt2 = 0;
	cin >> n >> m;
	for (int i = 1, j = n; i <= m; i ++ , j -- )
	{
		int a = i, b = j;
		while (a % 2 == 0)
		{
			a /= 2;
			cnt1 -- ;
		}
		while (a % 5 == 0)
		{
			a /= 5;
			cnt2 -- ;
		}
		while (b % 2 == 0)
		{
			b /= 2;
			cnt1 ++ ;
		}
		while (b % 5 == 0)
		{
			b /= 5;
			cnt2 ++ ;
		}
	}
	cout << min(cnt1, cnt2) << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}