#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	string s;
	LL a = 0, b = 0, c = 0, d = 0;
	for (int i = 1; i <= 2023; i ++ )
		s += to_string(i);
	int n = (int)s.size();
	for (int i = 0; i < n; i ++ )
	{
		if (s[i] == '2')
		{
			a ++ ;
			c += b;
		}
		if (s[i] == '0') b += a;
		if (s[i] == '3') d += c;
	}
	cout << d << endl; // 5484660609
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}

