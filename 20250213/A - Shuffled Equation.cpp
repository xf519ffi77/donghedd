#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int a, b, c;
	cin >> a >> b  >> c;
	if (a * b == c || a * c == b || b * c == a) cout << "Yes";
	else cout << "No";
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
