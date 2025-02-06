//存储对角线有一个小技巧：
//1） 从左上到右下的对角线满足 x + y 都相等。
//2） 从左下到右上的对角线满足 x - y 都相等。
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	unordered_map<int, LL> mp1, mp2;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
		{
			cin >> a[i][j];
			mp1[i + j] += a[i][j];
			mp2[i - j] += a[i][j];
		}
	LL ans = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			ans = max(ans, mp1[i + j] + mp2[i - j] - a[i][j]);
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}

//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//typedef long long LL;
//const int mod = 1e9 + 7;
//const int N = 1010;
//int n, m;
//LL a[N][N], l[N][N], r[N][N];
//void solve()
//{
//	LL ans = 0;
//	cin >> n >> m;
//	n -- , m --  ;
//	for (int i = 0; i <= n; i ++ )
//		for (int j = 0; j <= m; j ++ )
//		{
//			cin >> a[i][j];
//			l[i][j] = r[i][j] = 0;
//		}
//	if (m >= n)
//	{
//		for (int i = 0; i <= m; i ++ )
//		{
//			int x = 0, y = i;
//			while (x >= 0 && x <= n && y >= 0 && y <= m)
//			{
//				l[0][i] += a[x][y];
//				x ++ ;
//				y -- ;
//			}
//			x = 0, y = i;
//			while (x >= 0 && x <= n && y >= 0 && y <= m)
//			{
//				r[0][i] += a[x][y];
//				x ++ ;
//				y ++ ;
//			}
//			if (n)
//			{
//				x = n, y = i;
//				while (x >= 0 && x <= n && y >= 0 && y <= m)
//				{
//					l[n][i] += a[x][y];
//					x -- ;
//					y ++ ;
//				}
//				x = n, y = i;
//				while (x >= 0 && x <= n && y >= 0 && y <= m)
//				{
//					r[n][i] += a[x][y];
//					x -- ;
//					y -- ;
//				}
//			}
//		}
//		for (int x = 0; x <= n; x ++ )
//			for (int y = 0; y <= m; y ++ )
//			{
//				LL res = 0;
//				if (x + y > m) res += l[n][y - (n - x)];
//				else res += l[0][y + x];
//				if (x > y) res += r[n][y + (n - x)];
//				else res += r[0][y - x];
//				res -= a[x][y];
//				ans = max(ans, res);
//			}
//	}
//	else
//	{
//		for (int i = 0; i <= n; i ++ )
//		{
//			int x = i, y = 0;
//			while (x >= 0 && x <= n && y >= 0 && y <= m)
//			{
//				l[i][0] += a[x][y];
//				x -- ;
//				y ++ ;
//			}
//			x = i, y = 0;
//			while (x >= 0 && x <= n && y >= 0 && y <= m)
//			{
//				r[i][0] += a[x][y];
//				x ++ ;
//				y ++ ;
//			}
//			if (m)
//			{
//				x = i, y = m;
//				while (x >= 0 && x <= n && y >= 0 && y <= m)
//				{
//					l[i][m] += a[x][y];
//					x ++ ;
//					y -- ;
//				}
//				x = i, y = m;
//				while (x >= 0 && x <= n && y >= 0 && y <= m)
//				{
//					r[i][m] += a[x][y];
//					x -- ;
//					y -- ;
//				}
//			}
//	}	
//		for (int x = 0; x <= n; x ++ )
//			for (int y = 0; y <= m; y ++ )
//			{
//				LL res = 0;
//				if (x + y > m) res += l[x - (m - y)][m];
//				else res += l[x + y][0];
//				if (x > y) res += r[x - m + 1][0];
//				else res += r[x + (m - y)][m];
//				res -= a[x][y];
//				ans = max(ans, res);
//			}		
//	}
//	cout << ans << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}

