#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 100010;
typedef long long LL; 
int n, m;
LL ans;
int v[N];
multiset<int> st;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> v[i];
	st.insert(v[1]);
	for (int i = 1, j = 1; i < n; i ++ )
	{
		while  (j + 1 <= n)
		{
			st.insert(v[j + 1]);
			if (*st.rbegin() - *st.begin() > m)
			{
				st.erase(st.find(v[j + 1]));
				break;
			}
			j ++ ;
		}
		if (j - i + 1 >= 2) ans += j - i;
	}
	cout << ans << endl;
	return 0;
}
