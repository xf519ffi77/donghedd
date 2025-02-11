#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool CHICKEN(string s)
{
    string target = "CHICKEN";
    int j = 0; 
    for (char c : s)
	{
        if (c == target[j])
		{
            j ++ ;
            if (j == 7) return true;
        }
    }
    return false;
}
void solve()
{
	int n;
	string s;
	cin >> n >> s;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i ++ )
		mp[s[i]] ++ ; 
	if (n % 2 == 0 || mp['C'] < 2 || mp['I'] < 1 || mp['H'] < 1 || mp['K'] < 1 || mp['E'] < 1 || mp['N'] < 1 || !CHICKEN(s))
	{
//		cout << (n & 1) << ' ' << mp['C'] << ' ' << mp['H'] << ' ' << mp['I'] << ' ' << mp['K'] << ' ' << mp['E'] << ' ' << mp['N'];
		cout << "NO\n";
		return;
	}
	int Max = 0;
	mp['C'] -= 2;
	mp['I'] -- ;
	mp['H'] -- ;
	mp['K'] -- ;
	mp['E'] -- ;
	mp['N'] -- ;
	n -= 7;
	for (int i = 'A'; i <= 'Z'; i ++ )
		Max = max(Max, mp[i]);
	if (Max > n / 2) cout << "NO\n";
	else cout << "YES\n";
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
