#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	s =  " " + s;
	for (int i = 1; i < n; i ++ )
		if (s[i] == s[i + 1])
		{
			cout << 1 << endl;
			return;
		}
	cout << n << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
