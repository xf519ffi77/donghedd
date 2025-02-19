#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1000010;
int n, m;
int s[N * 2];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	while (n -- )
	{
		int l, r;
		cin >> l >> r;
		s[l + r] ++ ;
	}
	for (int i = 1; i <= N * 2; i ++ ) s[i] += s[i - 1];
	while (m -- )
	{
		int l, r;
		cin >> l >> r;
		l *= 2, r *= 2;
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
