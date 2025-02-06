#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n;
	int ans = 0, f = 0; // f记录当前字符的前面有多少个'u' 
	string s;
	cin >> n >> s;
	s = " " + s;
	for (int i = 1; i <= n; i ++ )
	{
		string t = s.substr(i + 1, 8);
		if (t == "uwawauwa") ans += f;
		f += (s[i] == 'u');
	}
	cout << ans << endl;
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
//void solve()
//{
//	int n;
//	int ans = 0;
//	string s;
//	cin >> n >> s;
//	s = " " + s;
//	vector<int> v;
//	for (int i = 1; i <= n - 7; i ++ )
//		if (s.substr(i, 8) == "uwawauwa")
//		{
//			v.push_back(i);
//			i += 4;
//		}
//	if (v.empty())
//	{
//		cout << 0 << endl;
//		return;
//	}
//	int num = v.size();
//	for (int i = 1; i <= n - 7; i ++ )
//		if (s[i] == 'u')
//		{
//			int t = num - (lower_bound(v.begin(), v.end(), i + 2) - v.begin());
//			ans += t;
//		}
//	cout << ans << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}
