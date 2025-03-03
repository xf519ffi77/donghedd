// 分层图的建图
// i + n
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int N = 200010, M = N * 4;
int n, m;
LL x, ans = 1e18;
LL d[N * 2], w[M];
int h[N * 2], e[M], ne[M], idx;
bool st[N * 2];
void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}
void dijkstra()
{
	for (int i = 1; i <= n; i ++ ) d[i] = d[i + n] = 1e18;
	d[1] = 0;
	priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
	heap.push({0, 1});
	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();
		LL distance = t.first;
		int vertex = t.second;
		if (st[vertex]) continue;
		st[vertex] = true;
		for (int i = h[vertex]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] > distance + w[i])
			{
				d[j] = distance + w[i];
				heap.push({d[j], j});
			}
		} 
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(h, -1, sizeof(h));
	cin >> n >> m >> x;
	while (m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b, 1);
		add(b + n, a + n, 1);
	}
	for (int i = 1; i <= n; i ++ )
	{
		add(i, i + n, x);
		add(i + n, i, x);
	}
	dijkstra();
	cout << min(d[n], d[n + n]) << endl;
	return 0;
}
