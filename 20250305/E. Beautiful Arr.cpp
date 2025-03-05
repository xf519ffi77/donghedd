#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<PII> a(n + 1);
	map<int, int> mp;
	for (int i = 1; i <= n; i ++ )
	{
		int t;
		cin >> t;
		a[i] = {t % k, t / k};
		mp[t % k] ++ ;
	}
	sort(a.begin() + 1, a.end());
	int cnt = 0, ind;
	for (auto t : mp)
		if (t.second & 1) cnt ++ ;
	if (cnt >= 2 || (n % 2 == 0 && cnt >= 1))
	{
		cout << "-1\n";
		return;
	}
	for (int i = n; i >= 1; i -- )
		if (mp[a[i].first] & 1)
		{
			ind = i;
			if (mp[a[i].first] > 1)
			{
				
				int l = i - mp[a[i].first] + 1, r = i;
				int j = i - 1, min = 1e9;
				vector<int> sl(n + 1, 0), sr(n + 2, 0);
				for (int k = l; k <= r; k ++ )
				{
					sl[k] = sl[k - 1];
					if ((k - l + 1) & 1) sl[k] -= a[k].second;
					else sl[k] += a[k].second;
				}
				for (int k = r; k >= l; k -- )
				{
					sr[k] = sr[k + 1];
					if ((r - k) & 1) sr[k] -= a[k].second;
					else sr[k] += a[k].second;
				}
				for (int k = l; k <= r; k += 2)
				{
					if (sl[k - 1] + sr[k + 1] < min)
					{
						min = sl[k - 1] + sr[k + 1];
						ind = k;
					}
				}
			}
			break;
		}
	if (n & 1) a.erase(a.begin() + ind, a.begin() + ind + 1), n -- ;
	int sum = 0;
	for (int i = 1; i <= n; i ++ )
		if (i & 1) sum -= a[i].second;
		else sum += a[i].second;
	cout << sum << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
