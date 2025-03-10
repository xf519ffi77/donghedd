#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<vector<LL>> a(n + 1, vector<LL>(m + 1, 0));
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> a[i][j];
	int x = 1, y = 1;
	for (int i = 0; i < n + m - 2; i ++ )
	{
		LL t = 0;
		if (s[i] == 'D')
		{
			for (int j = 1; j <= m; j ++ ) t += a[x][j];
			a[x ++ ][y] = -t;
		}
		else
		{
			for (int j = 1; j <= n; j ++ ) t += a[j][y];
			a[x][y ++ ] = -t;
		}
	}
	for (int i = 1; i < n; i ++ ) a[n][m] -= a[i][m];
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			if (j == m) cout << a[i][j] << endl;
			else cout << a[i][j] << " ";
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
//typedef pair<int, int> PII;
//void solve()
//{
//	int n, m;
//	string s ;
//	cin >> n >> m >> s;
//	vector<vector<LL>> a(n + 1, vector<LL>(m + 1, 0));
//	vector<int> cnt1(n + 1, 0), cnt2(m + 1, 0);
//	vector<LL> s1(n + 1, 0), s2(m + 1, 0);
//	vector<PII> site(n + m - 1);
//	int d = 1, r = 1;
//	cnt1[1] = cnt2[1] = 1;
//	site[0] = {1, 1};
//	for (int i = 0; i < n + m - 2; i ++ )
//	{
//		if (s[i] == 'R')
//		{
//			cnt2[ ++ r] ++ ;
//			cnt1[d] ++ ;
//		}
//		else
//		{
//			cnt1[ ++ d] ++ ;
//			cnt2[r] ++ ;
//		}
//		site[i + 1] = {d, r};
//	}
//	for (int i = 1; i <= n; i ++ )
//		for (int j = 1; j <= m; j ++ )
//		{
//			cin >> a[i][j];
//			s1[i] += a[i][j];
//			s2[j] += a[i][j];
//		}
//	vector<vector<LL>> b = a;
//	int cnt = 0;
//	function<void()> dfs = [&]()
//	{
//		for (int i = 0; i < n + m - 1; i ++ )
//		{
//			int x = site[i].first, y = site[i].second;
//			if (cnt1[x] == 1)
//			{
//				cnt ++ ;
//				cnt1[x] -- ;
//				cnt2[y] -- ;
//				b[x][y] = -s1[x];
//				s2[y] += b[x][y];
//			}
//			else
//			{
//				if (cnt2[y] == 1)
//				{
//					cnt ++ ;
//					cnt1[x] -- ;
//					cnt2[y] -- ;
//					b[x][y] = -s2[y];
//					s1[x] += b[x][y];
//				}
//			}
//		}
//		if (cnt < n + m - 1) dfs();	
//	};
//	dfs();
//	for (int i = 1; i <= n; i ++ )
//		for (int j = 1; j <= m; j ++ )
//			if (j == m) cout << b[i][j] << endl;
//			else cout << b[i][j] << " ";
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}