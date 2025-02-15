#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool check(vector<int> a)
{
	int n = (int)a.size();
	vector<int> suf_mex(n);
	vector<int> used(n + 1, false); // 一共只有n个数，最大mex不会超过n
	int mex = 0;
	for (int i = n - 1; i >= 1; i -- )
	{
		if (a[i] <= n) used[a[i]] = true; // 一共只有n个数，最大mex不会超过n
		while (used[mex]) mex ++ ;
		suf_mex[i] = mex;
	}
	int pre_min = 0x3f3f3f3f;
	for (int i = 0; i < n - 1; i ++ )
	{
		pre_min = min(pre_min, a[i]);
		if (pre_min < suf_mex[i + 1]) return false;
	}
	return true;
}
void solve()
{
	int n, cnt0 = 0;
	cin >> n;
	vector<int> a(n), b;
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	bool flag = false;
	for (int i = 0; i < n; i ++ )
		if (a[i] == 0)
		{
			cnt0 ++ ;
			if (!flag)
			{
				b.push_back(a[i]);
				flag = true;
			}
		}
		else b.push_back(a[i]);
	if (cnt0 > 0 && check(b)) cout << n - cnt0 + 1 <<  endl;
	else cout << n - cnt0 << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
