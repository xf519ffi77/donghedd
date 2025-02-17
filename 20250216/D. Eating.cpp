#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 31;
void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> w(n), s(n, 0);
	vector<vector<int>> last(n, vector<int>(N, 0)); // last[i][j]表示前i个数中，距离i最近且第j位为1的点（编号） 
	for (int i = 0; i < n; i ++ ) cin >> w[i];
	s[0] = w[0];
	for (int i = 1; i < n; i ++ ) s[i] = s[i - 1] ^ w[i];
	for (int i = 0; i < n; i ++ )
	{
		if (i) last[i] = last[i - 1];
		last[i][__lg(w[i])] = i;
		for (int j = N - 2; j >= 0; j -- )
			last[i][j] = max(last[i][j], last[i][j + 1]);
	}
	while (q -- )
	{
		int x;
		cin >> x;
		int idx = n - 1;
		while (idx >= 0 && x > 0)
		{
			int msb = __lg(x);
			int nxt = last[idx][msb];
			x ^= s[idx] ^ s[nxt];
			idx = nxt;
			if (nxt == -1 || w[nxt] > x) break;
			x ^= w[nxt];
			idx -- ;
		}
		cout << n - idx - 1 << " ";
	}
	cout << endl;
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
//const int N = 31;
//void solve()
//{
//	int n, q;
//	cin >> n >> q;
//	vector<int> w(n + 1);
//	vector<vector<int>> v(N, vector<int>(n + 1, 0));
//	for (int i = 1; i <= n; i ++ ) cin >> w[i];
//	for (int i = 1; i <= n; i ++ )
//		for (int j = 0; j < N; j ++ )
//			if ((w[i] >> j) & 1)
//				v[j].push_back(i);
//	while (q -- )
//	{
//		int x;
//		cin >> x;
//		int l = 1, r = n + 1;
//		for (int j = N - 1; j >= 0; j -- )
//		{
//			int t = lower_bound(v[j].begin(), v[j].end(), r) - v[j].begin();
//			int cnt = (int)v[j].size() - t;
//			int now = (cnt & 1) ^ ((x >> j) & 1);
//			if (now)
//			{
//				int s = lower_bound(v[j].begin(), v[j].end(), l) - v[j].begin();
//				if (s == t) break;
//				if (s + 1 == t) r = v[j][s] + 1;
//				else
//				{
//					l = v[j][t - 2] + 1;
//					r = v[j][t - 1] + 1;
//				}
//			}
//			else
//			{
//				if (t != 0 && v[j][t - 1] >= l)
//					l = v[j][t - 1] + 1;
//			}
//		}
//		cout << n - l + 1 << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}
