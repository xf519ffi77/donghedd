#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
int n, m;
int a[N];
LL t1[N], t2[N]; // t1[i]维护b[i]的前缀和，t2[i]维护i*b[i]的前缀和 
int lowbit(int x)
{
	return x & -x;
}
void add(int x, LL c)
{
	for (int i = x; i <= n; i += lowbit(i)) t1[i] += c, t2[i] += x * c;
}
LL sum(int x)
{
	LL res1 = 0, res2 = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) res1 += t1[i], res2 += t2[i];
	return res1 * (x + 1) - res2;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		add(i, a[i] - a[i - 1]);
	}
	while (m -- )
	{
		char c;
		int l, r;
		cin >> c >> l >> r;
		if (c == 'C')
		{
		    LL d;
			cin >> d;
			add(l, d), add(r + 1, -d);
		}
		else cout << sum(r) - sum(l - 1) << endl;
	}
	return 0;
}
