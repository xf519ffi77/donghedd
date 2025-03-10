#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int N = 200010;
int n, m;
LL ans;
int b[N], t[N];
int cntl[N], cntr[N]; // cntl[x]表示当前位置左侧有多少个x，cntr[x]表示当前位置右侧有多少个x 
int resl[N], resr[N]; // resl[x]记录当x变为0时左侧会增加的逆序对个数， resr[x]记录当x变为0时右侧会减少的逆序对个数
PII a[N];
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int c)
{
	for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
}
int sum(int x)
{
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) res += t[i];
	return res;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		int x;
		cin >> x;
		a[i] = {x, i};
		resl[x] += i - 1 - cntl[x];
		cntl[x] ++ ;
	}
	for (int i = n; i >= 1; i -- )
	{
		int x = a[i].first;
		resr[x] += n - i - cntr[x];
		cntr[x] ++ ;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++ ) b[a[i].second] = i;
	for (int i = n; i >= 1; i -- )
	{
		ans += (LL)sum(b[i] - 1);
		update(b[i], 1);
	}
	for (int i = 0; i < m; i ++ )
	{
		ans += resl[m - i] - resr[m - i];
		cout << ans << endl;
	}
	return 0;
}
