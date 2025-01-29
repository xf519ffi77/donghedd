#include <bits/stdc++.h>
#define  endl '\n'
using namespace std;
typedef long long LL;
const int N = 500010;
int n;
int c[N], t[N];
LL ans;
struct num
{
	int v, id;
}a[N];
bool cmp(num a, num b)
{
	return a.v < b.v;
}
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int c)
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
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i].v, a[i].id = i;
	// stable_sort()
	stable_sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i ++ ) c[a[i].id] = i;
	for (int i = n; i >= 1; i -- )
	{
		ans += (LL)sum(c[i] - 1);
		add(c[i], 1);
	}
	cout << ans << endl;	
	return 0;
}
