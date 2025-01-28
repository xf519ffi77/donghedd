#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N =  100010;
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
		add(i, a[i] - a[i - 1]);
	}
	while (m -- )
	{
		char c;
		cin >> c;
		if (c == 'C')
		{
			int l, r, d;
			cin >> l >> r >> d;
			add(l, d), add(r + 1, -d);
		}
		else
		{
			int x;
			cin >> x;
			cout << sum(x) << endl;
		}
	}
	return 0;
}
