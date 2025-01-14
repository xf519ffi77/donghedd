#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 100010;
typedef long long LL;
int n;
LL m, cnt, ans, cnt1, cnt2;
char c[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> c;
	for (int i = n - 1; i >= 0; i -- )
	{
		if (c[i] == 'b') cnt2 ++ ;
		else if (c[i] == 'a') cnt += cnt2, cnt1 ++ ;
	}
	cout << cnt * m + cnt1 * cnt2 * m *  (m - 1) / 2 << endl;
	return 0;
}
