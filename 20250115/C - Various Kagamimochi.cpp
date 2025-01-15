#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 500010;
int n;
LL ans;
int a[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i < n; i ++ )
	{
		int l = i + 1, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (2 * a[i] <= a[mid]) r = mid;
			else l = mid + 1;
		}
		if (2 * a[i] > a[l]) break;
		ans += (LL)n - l + 1;
	}
	cout << ans << endl;
	
	return 0;
}