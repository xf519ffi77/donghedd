#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 100010;
int n;
int h[N], t[N], ans[N];
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int c)
{
	for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
}
int sum(int x)
{
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) res += t[i];
	return res;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i ++ ) cin >> h[i];
	for (int i = 1; i <= n; i ++ ) t[i] = lowbit(i); // add(i, 1)
	for (int i = n; i >= 1; i -- )
	{
		int k = h[i] + 1; // 在剩下高度中求出第k小的
		int l = 1, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (sum(mid) >= k) r = mid;
			else l = mid + 1;
		}
		ans[i] = l;
		add(l, -1);
	}
	for (int i = 1; i <= n; i ++ ) cout << ans[i] << endl;
	return 0;
}
