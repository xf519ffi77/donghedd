#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n - 1; i ++ )
		if (s[i] == 'W' && s[i + 1] == 'A')
		{
			s[i] = 'A';
			s[i + 1] = 'C';
			for (int j = i - 1; j >= 0; j -- )
				if (s[j] != 'W') break;
				else
				{
					s[j] = 'A';
					s[j + 1] = 'C';
				}
		}
	cout << s << endl; 
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
