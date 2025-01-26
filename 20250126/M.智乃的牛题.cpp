#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 30;
int cnt[N];
int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s != "cdenoorw") cout << "I AK IOI" << endl;
	else cout << "happy new year" << endl;
    return 0;
}