#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
LL a[N], t[N * 4], lz[N * 4];
int n;

void pushup(int o)
{
	t[o] =  t[o << 1] + t[o << 1 | 1];
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
		int lo = o << 1, ro = o << 1 | 1, mid = s + e >> 1;
		t[lo] += (mid - s + 1) * lz[o],  lz[lo] += lz[o];
		t[ro] += (e - mid) * lz[o],  lz[ro] += lz[o];
		lz[o] = 0;
	}
}

void update(int l, int r, LL v, int s = 1, int e = n, int o = 1)
{
	if (s >= l && e <= r)
	{
		//  ��ǰ�ڵ���Ҫ�޸ĵ������ĳ���ӽڵ㣬����ֹͣ�� 
		t[o]  += (e - s + 1) * v;
		lz[o] += v; // ��ʾ��ǰ�ڵ���ӽڵ㻹��vҪ�޸�
		return; 
	}
	int mid = s + e >> 1;
	pushdown(s, e, o); // ��lz�·� 
	if (mid >= l) update(l, r, v, s, mid, o << 1);
	if (mid < r) update(l, r, v, mid + 1, e, o << 1 | 1);
	pushup(o);
}

LL query(int l, int r, int s = 1, int e = n, int o = 1)
{
	if (s >= l && e <= r) return t[o];
	int mid = s + e >> 1;
	pushdown(s, e, o); // ��lz�·� 
	LL res = 0;
	if (mid >= l) res += query(l, r, s, mid, o << 1);
	if (mid < r) res += query(l, r, mid + 1, e, o << 1 | 1);
	return res;
} 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0),  cout.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	build();
	while (q -- )
	{
		int op, l, r;
		cin >> op;
		if (op == 1)
		{
			LL v;
			cin >> l >> r >> v;
			update(l, r, v);
		}
		else
		{
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
	}
	return 0;
}