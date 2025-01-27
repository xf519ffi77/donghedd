// 带扩展域的并查集 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 50010, M = N * 3;
int n, m, ans;
int p[M];
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < M; i ++ ) p[i] = i;
	while (m -- )
	{
		int d, x, y;
		cin >> d >> x >> y;
		if (x > n || y > n || (x == y && d == 2))
		{
		    ans ++ ;
		    continue;
		}
		if (d == 1)
		{
			if (find(x) == find(y + N) || find(x + N) == find(y))
			{
			    ans ++ ;
			    continue;
			}
			else
			{
				p[find(x)] = find(y);
				p[find(x + N)] = find(y + N);
				p[find(x + N * 2)] = find(y + N * 2);
			}
		}
		else
		{
			if (find(x) == find(y) || find(y) == find(x + N))
			{
			    ans ++ ;
			    continue;
			}
			else
			{
				p[find(x)] = find(y + N);
				p[find(x + N)] = find(y + N * 2);
				p[find(x + N * 2)] = find(y);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

// 带边权的并查集
#include <iostream>
using namespace std;
const int N = 50010;
int n, k, cnt;
int p[N], d[N];
int find(int x)
{
	if (p[x] != x)
	{
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	return p[x];
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) p[i] = i; 
	while (k -- )
	{
		int D, x, y;
		cin >> D >> x >> y;
		if (x > n || y > n) cnt ++ ;
		else
		{
			int px = find(x), py = find(y);
			if (D == 1)
			{
				if (px == py && (d[x] - d[y]) % 3) cnt ++ ;
				else if (px != py)
				{
					p[px] = py;
					d[px] = d[y] - d[x];
				}
			}
			else
			{
				if (px == py && (d[x] - d[y] - 1) % 3) cnt ++ ;
				else if (px != py)
				{
					p[px] = py;
					d[px] = d[y] + 1 - d[x];
				}
			}
		}
	}
	cout << cnt << endl; 
	return 0;
}