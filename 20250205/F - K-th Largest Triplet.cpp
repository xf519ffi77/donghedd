#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 200010;
LL a[N], b[N], c[N];
LL get(int i, int j, int k)
{
	return a[i] * b[j] + a[i] * c[k] + b[j] * c[k];
}
bool cmp(int a, int b)
{
	return a > b;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= n; i ++ ) cin >> b[i];
	for (int i = 1; i <= n; i ++ ) cin >> c[i];
	sort(a + 1, a + n + 1, cmp), sort(b + 1, b + n + 1, cmp), sort(c + 1, c + n + 1, cmp);
	priority_queue<array<LL, 4>> heap;
	set<array<int, 3>> s;
	heap.push({get(1, 1, 1), 1, 1, 1});
	while (heap.size())
	{
		auto t = heap.top();
		LL v = t[0];
		int i = t[1], j = t[2], k = t[3];
		// auto [v, i, j, k] = heap.top();
		heap.pop();
		array<int, 3> it = {i, j, k};
		if (s.count(it)) continue;
		s.insert(it);
		m -- ;
		if (!m)
		{
			cout << v << endl;
			return;
		}
		if (i + 1 <= n) heap.push({get(i + 1, j, k), i + 1, j, k});
		if (j + 1 <= n) heap.push({get(i, j + 1, k), i, j + 1, k});
		if (k + 1 <= n) heap.push({get(i, j, k + 1), i, j, k + 1});
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
