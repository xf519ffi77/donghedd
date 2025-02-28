#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 510;
int C[N][N];
void __init__()
{
	for (int i = 0; i < N; i ++ )
		for (int j = 0; j <= i; j ++ )
		    if (!j) C[i][j] = 1;
			else C[i][j] = C[i - 1][j] + C[i - 1][j  - 1];
}
void solve()
{
	int k;
	cin >> k;
	if (k == 0) cout << 0 << endl;
	else
	{
		vector<int> v;
		v.push_back(0);
		int n = 0, l, r;
		while (k)
		{
			l = 2, r = 500;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				if (C[mid][2] <= k) l = mid;
				else r = mid - 1;;
			}
			k -= C[l][2];
			v.push_back(l);
			n += l;
		}
		cout << n << endl;
		int cnt = v.size();
		for (int i = 1; i < cnt; i ++ )
		{
			for (int j = v[i - 1]; j < v[i - 1] + v[i]; j ++ )
				cout << i << " " << j << endl;
			v[i] += v[i - 1];
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	__init__();
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
