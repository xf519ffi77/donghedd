// 2 <= n <= 1e+12
// 0 <= m <= 2e+4
// 1 <= A <= B <= 20
// 1 < l[i] <= r[i] < n
// 状态压缩+路径规划

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 20010, M = N * 800;
LL n;
int m, A, B, cnt;
LL l[N], r[N];
int f[M], st[M];
vector<PII> v;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> A >> B;
	for (int i = 1; i <= m; i ++ )
	{
		cin >> l[i] >> r[i];
		if (r[i] - l[i] + 1 >= B)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	if (A == B)
	{
		if (A == 1)
		{
			if (m == 0) cout << "Yes" << endl;
			else cout << "No" << endl;
			return 0;
		}
		if (n % A != 1)
		{
			cout << "No" << endl;
			return 0;
		}
		for (int i = 1; i <= m; i ++ )
			for (LL j = l[i]; j <= r[i]; j ++ )
				if (j % A == 1)
				{
					cout << "No" << endl;
					return 0;
				}
		cout << "Yes" << endl;
		return 0;
	}
	l[m + 1] = n + 1;
	LL C = A * B * 2;
	v.push_back({min(l[1] - 1, C), 0});
	for (int i = 1; i <= m; i ++ )
	{
		v.push_back({min(r[i] - l[i] + 1, (LL)B * 2), 1});
		v.push_back({min(l[i + 1] - r[i] - 1, C), 0});
	}
	for (auto x : v) for (int i = 1; i <= x.first; i ++ ) st[ ++ cnt] = x.second;
	f[1] = 1;
	for (int i = 2; i <= cnt; i ++ )
		if (st[i]) f[i] = 0;
		else for (int j = A; j <= B; j ++ ) if (i > j) f[i] |= f[i - j];
	if (f[cnt]) cout  << "Yes" << endl;
	else cout  << "No" << endl;
	return 0;
}