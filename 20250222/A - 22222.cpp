#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i ++ )
		if (s[i] == '2') cout << 2;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
