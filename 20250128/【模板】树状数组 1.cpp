#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], t[N];
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
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		add(i, a[i]);
	}
	while (m -- )
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, c;
			cin >> x >> c;
			add(x, c);
		}
		else
		{
			int x, y;
			cin >> x >> y;
			cout << sum(y) - sum(x - 1) << endl;
		}
	}
	return 0;
}

// 修改单点值，求区间和