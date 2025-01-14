#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 200010;
LL a[N], t[N * 4];
int n, q;

void pushup(int o)
{
	t[o] = t[o << 1] + t[o << 1 | 1];
}

void build(int s = 1, int e = n, int o = 1)
{
	if (s == e)
	{
		t[o] = a[s];
		return;
	}
	int mid = s + e >> 1;
	build(s, mid, o << 1), build(mid + 1, e, o << 1 | 1);
	pushup(o);
}

void update(int l, int r, int s = 1, int e = n, int o = 1)
{
	if (t[o] == e - s + 1) return;
	if (s == e)
	{
		t[o] = sqrt(t[o]);
		return;
	}
	int mid = s + e >> 1;
	if (mid >= l) update(l, r, s, mid, o << 1);
	if (mid < r) update(l, r, mid + 1, e, o << 1 | 1);
	pushup(o);
}

LL query(int l, int r, int s = 1, int e = n, int o = 1)
{
	if (s >= l && e <= r) return t[o];
	int mid = s + e >> 1;
	LL res = 0;
	if (mid >= l) res += query(l, r, s, mid, o << 1);
	if (mid < r) res += query(l, r, mid + 1, e, o << 1 | 1);
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	build();
	while (q -- )
	{
		int op, l, r;
		cin >> op >> l >> r;
		if (op == 1) update(l, r);
		else cout << query(l, r) << endl;
	}
	return 0;
}
