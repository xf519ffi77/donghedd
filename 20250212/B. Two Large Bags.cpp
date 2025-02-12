#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i ++ )
	{
		cin >> a[i];
		mp[a[i]] ++ ;
	}
	for (int i = 1; i < n; i ++ )
		if (mp[i] > 2)
		{
			mp[i + 1] += mp[i] - 2;
			mp[i] = 2;
		}
	for (int i = 1; i <= n; i ++ )
		if (mp[i] & 1)
		{
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
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
//const int N = 1010;
//int a[N];
//bool vis[N];
//bool flag;
//unordered_map<int, int> mp;
//void dfs(int x)
//{
//	if (mp[x + 1])
//	{
//		mp[x + 1] += mp[x];
//		return;
//	}
//	else
//	{
//		if (!mp[x]) return;
//		if (mp[x] == 1)
//		{
//			flag = false;
//			return;
//		}
//		else
//		{
//			if (!mp[x + 1]) mp[x + 1] -= 2;
//			mp[x + 1] += mp[x];
//			dfs(x + 1);
//		}
//	}
//}
//void solve()
//{
//	mp.clear();
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i ++ )
//	{
//		cin >> a[i];
//		vis[a[i]] = false;
//		mp[a[i]] ++ ;
//	}
//
//	sort(a + 1, a + n + 1);
//	flag = true;
//	for (int i = 1; i <= n; i ++ )
//	{
//		if (!flag) break;
//		if (vis[a[i]]) continue;
//		vis[a[i]] = true;
//		if (mp[a[i]] < 2)
//		{
//			flag = false;
//			break;
//		}
//		mp[a[i]] -= 2;
//		dfs(a[i]);
//	}
//	if (flag) cout << "YES\n";
//	else cout << "NO\n";
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}
