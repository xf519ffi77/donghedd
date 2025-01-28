#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 2e+5 + 10;
int n;
int a[N], t[N];
int lower[N], Greater[N];
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int c)
{
	for (int i = x; i <= n; i += lowbit(i))  t[i] += c;
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
	 LL res1 = 0, res2 = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
// 	for (int i = 1; i <= n; i ++ )
// 	{
// 		int y = a[i];
// 		// 统计前i个数中比a[i]小和大的数的个数
// 		lower[i] = sum(y - 1);
// 		Greater[i] = sum(n) - sum(y);
// 		update(y, 1);
// 	}
// 	memset(t, 0, sizeof(t));
// 	for (int i = n; i >= 1; i -- )
// 	{
// 		int y = a[i];
// 		// 统计后i个数中比a[i]小和大的数的个数
// 		res1 += (LL)Greater[i] * (sum(n) - sum(y));
// 		res2 += (LL)lower[i] * sum(y - 1);
// 		update(y, 1);
// 	}
    // y1～yn是1到n的一个排列
    for (int i = 1; i <= n; i ++ )
    {
        int y = a[i];
        lower[i] = sum(y - 1);
        Greater[i] = sum(n) - sum(y);
        res1 += (LL)Greater[i] * (n - a[i] - Greater[i]);
        res2 += (LL)lower[i] * (a[i] - 1 - lower[i]);
        update(y, 1);
    }
	cout << res1 << ' ' << res2 << endl;
	return 0;
}
