#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve()
{
	string s;
	cin >> s;
	int n = (int)s.size();
	if (s[0] >= '5')
	{
		fill(s.begin(), s.end(), '0');
		s = "1" + s;
	}
	else
	{
		for (int i = 1; i < n; i ++ )
		{
			if (s[i] >= '5')
			{
				fill(s.begin() + i, s.end(), '0');
				for (int j = i - 1; j >= 0; j -- )
				{
					s[j] ++ ;
					if (s[j] < '5') break;
					s[j] = '0';
					if (j == 0) s = "1" + s;
				}
				break;
			}
		}
	}
	cout << s << endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
