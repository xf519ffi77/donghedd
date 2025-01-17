#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e+5 + 10;
int l[N], r[N], s[2 * N], cnt[2 * N];
void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n;  i ++ ) s[i] = cnt[i] = 0;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> l[i] >> r[i];
		if (l[i] == r[i])
		{
			s[l[i]] = 1;
			cnt[l[i]] ++ ;
		}
	}
	for (int i = 1; i <= 2 * n; i ++ ) s[i] += s[i - 1];
	for (int i = 1; i <= n; i ++ )
	{
		if (l[i] == r[i])
		{
			if (cnt[l[i]] <= 1) cout << "1";
			else cout << "0";
		}
		else
		{
			if (s[r[i]] - s[l[i] - 1] < r[i] - l[i] + 1) cout << "1";
			else cout << "0";
		}
	}
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(0),  cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
// 前缀和