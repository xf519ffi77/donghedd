#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n, cnt1, cnt2;
int a[N], cnt[N];
bool st[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		cnt[a[i]] ++ ;
	}
	for (int i = 1; i <= n; i ++ )
		if (!st[a[i]])
		{
			if (cnt[a[i]] == 1) cnt1 ++ ;
			else cnt2 += cnt[a[i]] - 2;
			st[a[i]] = true;
		}
	if (cnt1 >= cnt2) cout << cnt2 + (cnt1 - cnt2) / 2 << endl;
	else cout << cnt2 << endl;
	return 0;
}
