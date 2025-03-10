#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, char> PIC;
const int mod = 1e9 + 7;
void solve()
{
	int n;
	char ch;
	vector<string> v, ans;
	vector<int> num(300, 0);
	cin >> n >> ch;
	for (int i = 1; i <= n * 2; i ++ )
	{
		string s;
		cin >> s;
		string t = s;
		if (s[1] == ch)
		{
			v.push_back(s);
			continue;
		}
		if (!num[s[1]]) num[s[1]] = s[0];
		else
		{
			t[0] = num[s[1]];
			s += " ";
			s += t;
			if (s[0] > s[3]) swap(s[0], s[3]);
			ans.push_back(s);
			num[s[1]] = 0;
		}
	}
	for (int i = 'A'; i <= 'Z'; i ++ )
		if (num[i])
		{
			if (!v.size())
			{
				cout << "IMPOSSIBLE\n";
				return;
			}
			string s;
			s += num[i];
			s += i;
			s += " ";
			s += v.back();
			v.pop_back();
			ans.push_back(s);
		}
	while (v.size())
	{
		string s = v.back();
		v.pop_back();
		s += " ";
		s += v.back();
		if (s[0] > s[3]) swap(s[0], s[3]);
		v.pop_back();
		ans.push_back(s);
	}
	for (auto s : ans) cout << s << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
