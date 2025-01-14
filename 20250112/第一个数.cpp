#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 200010;
int a[N], t[N * 4], lz[N * 4];
int n, m;

void pushup(int o)
{
	t[o] = max(t[o << 1], t[o << 1 | 1]);
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

void pushdown(int s, int e, int o)
{
	if (lz[o])
	{
		int lo = o << 1, ro = o << 1 | 1;
		t[lo] = lz[o], lz[lo] = lz[o];
		t[ro] = lz[o], lz[ro] = lz[o];
		lz[o] = 0;
	}
}

void update(int l, int r, int v, int s = 1, int e = n, int o = 1)
{
	if (s >= l && e <= r)
	{
		t[o] = v;
		lz[o] = v;
		return;
	}
	int mid = s + e >> 1;
	pushdown(s, e, o);
	if (mid >= l) update(l, r, v, s, mid, o << 1);
	if (mid < r) update(l, r, v, mid + 1, e, o << 1 | 1);
	pushup(o);
}

int query(int l, int r, int s = 1, int e = n, int o = 1)
{
	if (s >= l && e <= r) return t[o];
	int mid = s + e >> 1;
	pushdown(s, e, o);
	int res = 0;
	if (mid >= l) res = max(res, query(l, r, s, mid, o << 1));
	if (mid < r) res = max(res, query(l, r, mid + 1, e, o << 1 | 1));
	return res;
}

int main()
{
	ios::sync_with_stdio(0),  cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	build();
	cin >> m;
	while (m -- )
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, y;
			cin >> x >> y;
			update(x, x, y);
		}
		else
		{
			int p;
			cin >> p;
			int l = 1, r = n;
			while (l < r)
			{
				int mid = l + r >> 1;
				if (query(l, mid) >= p) r = mid;
				else l = mid + 1;
			}
			if (l == n && p > a[1]) cout << -1 << endl;
			else cout << l << endl;
		}
	}
	return 0;
}
