#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 2010;
int n;
LL ans;
LL x[N], y[N];
vector<map<LL, vector<int>>> q(N);
bool check(int i, int j, int k)
{
	if ((y[i] - y[j]) * (x[j] - x[k]) == (y[j] - y[k]) * (x[i] - x[j])) return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i ++ )
	{
		auto t = q[i];
		for (int j = 1; j <= n; j ++ )
		{
			if (i == j) continue;
			LL d = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
			t[d].push_back(j);
		}
		for(auto kv : t)
		{
			auto v = kv.second;
			for (int j = 0; j < v.size(); j ++ )
				for (int l = 0; l < v.size(); l ++ )
					if (check(i, v[j], v[l]))  ans ++ ;// cout << i << " " << v[j] << " " << v[l] << endl;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
