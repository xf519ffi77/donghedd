#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 30010;
int p[N], d[N], Size[N];
int find(int x)
{
	if (p[x] != x)
	{
		int root = find(p[x]);
		d[x] += d[p[x]];
		p[x] = root;
	}
	return p[x];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i < N; i ++ ) p[i] = i, Size[i] = 1;
	int t;
	cin >> t;
	while (t -- )
	{
		int a, b;
		char c;
		cin >> c >> a >> b;
		int pa = find(a), pb = find(b);
		if (c == 'M')
		{
			if (pa == pb) continue;
			d[pa] = Size[pb];
			Size[pb] += Size[pa];
			p[pa] = pb;
		}
		else
		{
			if (pa != pb) cout << -1 << endl;
			else cout << max(0, abs(d[a] - d[b]) - 1) << endl;
		}
	}
	return 0;
}
