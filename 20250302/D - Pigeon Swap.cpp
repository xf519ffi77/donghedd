#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 1000010;
int n, q;
int p[N], f[N], g[N]; // f[i]表示某点所在位置，g[i]表示某位置的顶点 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) p[i] = f[i] = g[i] = i;
	while (q -- )
	{
		int op, a, b;
		cin >> op;
		if (op == 1)
		{
			cin >> a >> b;
			p[a] = g[b]; 
		}
		else if (op == 2)
		{
			cin >> a >> b;
			f[g[b]] = a;
			f[g[a]] = b;
			swap(g[a], g[b]);
		}
		else
		{
			cin >> a;
			cout << f[p[a]] << endl;
		}
	}
	return 0;
}
