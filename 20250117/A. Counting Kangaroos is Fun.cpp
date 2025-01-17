#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5e+5 + 10;
int n;
int a[N];
bool check(int mid)
{
	for (int i = 1; i <= mid; i ++ )
		if (a[i] * 2 > a[i + n - mid]) return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n / 2;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	if (l == 1 && a[1] * 2 > a[n]) l = 0;
	cout << n - l << endl;
	return 0;
}
// 二分，贪心