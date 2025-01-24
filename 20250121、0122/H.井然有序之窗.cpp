#include <bits/stdc++.h>
#define endl '\n'
#define l first
#define r second
using namespace std;
typedef pair<int, int> PII;
const int N = 100010;
int n;
int ans[N];
struct interval
{
	int l, r, id;
}a[N];
bool cmp1(interval a, interval b)
{
	if (a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}
struct cmp2
{
	bool operator () (const interval &a, const interval &b)
	{
		return a.r > b.r;
	}
};
int main()     
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i].l >> a[i].r, a[i].id = i;
	sort(a + 1, a + n + 1, cmp1);
	priority_queue<interval, vector<interval>, cmp2> heap;
	int now = 1;
	for (int i = 1; i <= n; i ++ )
	{
		while (a[now].l <= i && now <= n) heap.push(a[now ++ ]);
		if (heap.empty() || heap.top().r < i)
		{
			cout << -1 << endl;
			return 0;
		}
		ans[heap.top().id] = i;
		heap.pop();
	}
	for (int i = 1; i <= n; i ++ ) cout << ans[i] << endl;
	return 0;
}

// map/堆