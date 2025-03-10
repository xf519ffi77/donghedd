#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	for (int i = 0, last = -1, cnt = 0; i < n; i ++ )
	{
		if (last != a[i])
		{
			last = a[i];
			cnt = 1;
		}
		else
		{
			cnt ++ ;
			if (cnt >= 3)
			{
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}
