#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	int ans = 0, l = 1, r = 1;
	for (int i = 1; i <= n; i ++ )
	{
		int cnt1 = 0, cnt2 = 0;
		for (int j = i + 1; j <= n; j ++ )
		{
			if (a[j] > a[i]) cnt1 ++ ;
			if (a[j] < a[i]) cnt2 ++ ;
			if (cnt2 - cnt1 > ans)
			{
				ans = cnt2 - cnt1;
				l = i, r = j;
			}
		}
	}
	cout << l << " " << r << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
