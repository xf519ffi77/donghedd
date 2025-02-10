#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	string s;
	cin >> s;
	cout << s.substr(0, s.size() - 2) + "i" << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
