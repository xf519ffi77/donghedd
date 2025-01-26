#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if (a + b + c >= n && a + b + c <= 2 * n) cout << "Yes" << endl;
	else cout << "No" << endl; 
}
int main()
{
    int t;
    cin >> t;
    while (t -- ) solve();
    return 0;
}
