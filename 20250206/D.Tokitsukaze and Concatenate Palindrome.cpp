#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 26;
int cnt1[N], cnt2[N];
void solve()
{
	memset(cnt1, 0, sizeof(cnt1)), memset(cnt2, 0, sizeof(cnt2));
	int n, m, ans = 0;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	if (n < m)
	{
		swap(n, m);
		swap(a, b);
	}
	unordered_map<int, int> mp1, mp2;
	for (int i = 0; i < n; i ++ ) cnt1[a[i] - 'a'] ++ ;
	for (int i = 0; i < m; i ++ ) cnt2[b[i] - 'a'] ++ ;
	for (int i = 0; i < 26; i ++ )
	{
        int t = min(cnt1[i], cnt2[i]);
		cnt1[i] -= t;
		cnt2[i] -= t;
	}
	int len = (n + m) / 2 - m;
	for (int i = 0; i < 26; i ++ )
	{
		int t = min(cnt1[i] / 2 * 2, len * 2);
		cnt1[i] -= t;
		len -= t / 2;
		ans += cnt1[i] + cnt2[i];
	}
	cout << ans / 2 << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}
