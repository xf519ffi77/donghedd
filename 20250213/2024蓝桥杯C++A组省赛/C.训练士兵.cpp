#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
struct solider
{
	LL p, c;
};
bool cmp(solider a, solider b)
{
	return a.c < b.c;
}
void solve()
{
	int n;
	LL s;
	cin >> n >> s;
	vector<solider> a(n);
	vector<LL> sp(n + 1, 0); // 后缀成本和 
	for (int i = 0; i < n; i ++ )
	{
		LL p, c;
		cin >> p >> c;
		a[i] = {p, c};
	}
	stable_sort(a.begin(), a.end(), cmp);
	for (int i = n - 1; i >= 0; i -- ) sp[i] = sp[i + 1] + a[i].p;
	int l = 0;
	while (l < n && sp[l] >= s) l ++ ;
	LL cnt = a[l - 1].c, ans = cnt * s;
	while (l < n) ans += (a[l].c - cnt) * a[l ++ ].p; 
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
