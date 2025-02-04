// 排序不等式
若a1 <= a2 <= ...... <= an, b1 <= b2 <= ...... <= bn
则a1 * bn + a2 * bn-1 + ...... + an * b1 <= ak1 * bk2 + ...... + ak2n-1 + bk2n <= a1 * b1 + a2 * b2  + ...... + an * bn
	
// 归并排序求逆序对
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010, mod = 1e8 - 3;
int n;
int a[N], temp[N];
struct L
{
	int h, id;
}l1[N], l2[N];
bool cmp(L a, L b)
{
	return a.h < b.h;
}
LL merge_sort(int l, int r)
{
	if (l >= r) return 0;
	int mid = l + r >> 1;
	LL cnt = (merge_sort(l, mid) % mod + merge_sort(mid + 1, r) % mod) % mod;
	int k = 1, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j]) temp[k ++ ] = a[i ++ ];
		else
		{
			temp[k ++ ] = a[j ++ ];
			cnt = (cnt + mid - i + 1) % mod;
		}
	}
	while (i <= mid) temp[k ++ ] = a[i ++ ];
	while (j <= r) temp[k ++ ] = a[j ++ ];
	for (int i = l, j = 1; i <= r; i ++ , j ++ ) a[i] = temp[j];
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> l1[i].h, l1[i].id = i;
	for (int i = 1; i <= n; i ++ ) cin >> l2[i].h, l2[i].id = i;
	sort(l1 + 1, l1 + n + 1, cmp);
	sort(l2 + 1, l2 + n + 1, cmp);
	for (int i = 1; i <= n; i ++ )
		a[l2[i].id] = l1[i].id;
	cout << merge_sort(1, n) << endl;
	return 0;
}

// 树状数组求逆序对
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010, mod = 1e8 - 3;
int n, ans;
int a[N], t[N];
struct L
{
	int h, id;
}l1[N], l2[N];
bool cmp(L a, L b)
{
	return a.h < b.h;
}
int lowbit(int x)
{
	return x & -x;
}
void add(int x , int c)
{
	for (int i = x; i <= n;  i += lowbit(i)) t[i] += c;
}
int sum(int x)
{
	int res = 0;
	for (int i = x; i >= 1;  i -= lowbit(i)) res += t[i];
	return res;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> l1[i].h, l1[i].id = i;
	for (int i = 1; i <= n; i ++ ) cin >> l2[i].h, l2[i].id = i;
	sort(l1 + 1, l1 + n + 1, cmp);
	sort(l2 + 1, l2 + n + 1, cmp);
	for (int i = 1; i <= n; i ++ )
		a[l2[i].id] = l1[i].id;
	for (int i = n; i >= 1; i -- )
	{
		ans = (ans + sum(a[i] - 1)) % mod;
		add(a[i], 1);
	}
	cout << ans << endl;
	return 0;
}
