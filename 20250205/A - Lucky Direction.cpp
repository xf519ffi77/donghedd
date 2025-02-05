#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	string s;
	cin >> s;
	if (s == "N") cout << "S" << endl;
	else if (s == "S") cout << "N" << endl;
	else if (s == "W") cout << "E" << endl;
	else if (s == "E") cout << "W" << endl;
	else if (s == "SE") cout << "NW" << endl;
	else if (s == "NW") cout << "SE" << endl;
	else if (s == "NE") cout << "SW" << endl;
	else if (s == "SW") cout << "NE" << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
