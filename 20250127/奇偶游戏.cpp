// 带边权的并查集
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 10010;
int n, m, cnt;
int p[N], d[N];
unordered_map<int, int> S;
int get(int x)
{
	if (S.count(x) == 0) S[x] = ++ cnt;
	return S[x];
}
int find(int x)
{
	if (p[x] != x)
	{
		int root = find(p[x]);
		d[x] += d[p[x]] % 2; // d[x] ^= d[p[x]];
		p[x] = root;
	}
	return p[x];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < N; i ++ ) p[i] = i;
	int ans = m;
	for (int i = 1; i <= m; i ++ )
	{
		int a, b;
		string type;
		cin >> a >> b >> type;
		a = get(a - 1), b = get(b);
		int pa = find(a), pb = find(b);
		int t = 0;
		if (type == "odd") t = 1;
		if (pa == pb)
		{
			if (((d[a] + d[b]) % 2 + 2) % 2 != t) // if ((d[a] ^ d[b]) != t)
			{
				ans = i - 1;
				break;
			}
		}
		else
		{
			p[pa] = pb;
			d[pa] = d[a] + d[b] + t; // d[pa] = d[a] ^ d[b] ^ t;
		}
	}
	cout << ans << endl;
	return 0;
}

// 带扩展域的并查集
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 10010 * 2, base = N / 2;
int n, m, cnt;
int p[N];
unordered_map<int, int> S;
int get(int x)
{
	if (S.count(x) == 0) S[x] = ++ cnt;
	return S[x];
}
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < N; i ++ ) p[i] = i;
	int ans = m;
	for (int i = 1; i <= m; i ++ )
	{
		int a, b;
		string type;
		cin >> a >> b >> type;
		a = get(a - 1), b = get(b);
		if (type == "even")
		{
			if (find(a + base) == find(b))
			{
				ans = i - 1;
				break;
			}
			p[find(a)] = find(b);
			p[find(a + base)] = find(b + base);
		}
		else
		{
			if (find(a) == find(b))
			{
				ans = i - 1;
				break;
			}
			p[find(a)] = find(b + base);
			p[find(a + base)] = find(b);
		}
	}
	cout << ans << endl;
	return 0;
}
