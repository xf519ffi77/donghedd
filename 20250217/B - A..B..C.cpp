#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 31;
void solve()
{
	string s;
	cin >> s;
	int n = (int)s.size(), ans = 0;
	for (int i = 0; i < n; i ++ )
		if (s[i] == 'A')
			for (int j = i + 1; j < n; j ++ )
				if (s[j] == 'B')
					for (int k = j + 1; k < n; k ++ )
						if (s[k] == 'C' && i + k == 2 * j) ans ++ ;
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
