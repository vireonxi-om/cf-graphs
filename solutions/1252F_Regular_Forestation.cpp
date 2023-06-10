// Problem: Regular Forestation
// URL: https://codeforces.com/problemset/problem/1252/F
// Rating: 2400
// Tags: hashing, trees
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;

const int N = 4100;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, ans = 1, pp[N], sz[N], cnt, mn, f[N];
vector<int> g[N];
int way[N], cway;
void dfs(int x, int fa) {
	cnt++;
	sz[x] = 1;
	for (auto y: g[x]) {
		if (!pp[y] && y != fa) {
			dfs(y, x);
			sz[x] += sz[y];
		}
	}
}
void find(int x, int fa) {
	sz[x] = 1;
	f[x] = 0;
	for (auto y: g[x]) {
		if (!pp[y] && y != fa) {
			find(y, x);
			sz[x] += sz[y];
			f[x] = max(f[x], sz[y]);
		}
	}
	f[x] = max(f[x], cnt - sz[x]);
	if (f[x] < mn) mn = f[x], way[cway = 1] = x;
	else if (f[x] == mn) way[++cway] = x;
}
ull res[N], tmp[N];
ull cal(int x, int fa) {
	for (auto y: g[x]) {
		if (!pp[y] && y != fa) {
			res[y] = cal(y, x);
		}
	}
	int cnt = 0;
	for (auto y: g[x]) {
		if (!pp[y] && y != fa) {
			tmp[++cnt] = res[y];
		}
	}
	sort(tmp + 1, tmp + cnt + 1);
	ull ans = 0;
	repn(i, 1, cnt) {
		ull y = tmp[i];
		ans = ans * 131ull + y + 1;
	}
	return ans;
}
int main() {
	IO;
	cin >> n;
	// n = 4000;
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		// x = i + 1, y = i;
		g[x].pb(y), g[y].pb(x);
	}
	repn(i, 1, n) {
		if (g[i].size() <= ans) continue;
		pp[i] = 1;
		PUU res, cur;
		int first = 0;
		int num = 0, flag = 0;
		dfs(i, 0);
		vector<int> all;
		for (auto j: g[i]) {
			all.pb(sz[j]);
		}
		rep(j, 1, g[i].size()) {
			if (all[j] != all[0]) {
				flag = 1;
				break;
			}
		}
		
		if (flag) {
			pp[i] = 0;
			continue;
		}
		for (auto j: g[i]) {
			cnt = 0;
			num++;
			mn = 1e9;
			dfs(j, 0);
			cway = 0;
			find(j, 0);
			if (cway == 1) {
				ull a = cal(way[1], 0);
				cur = mp(a, a);
			}
			else if (cway == 2) {
				ull a = cal(way[1], 0);
				ull b = cal(way[2], 0);
				cur = mp(min(a, b), max(a, b));
			}
			else {
				cout << "????\n";
				return 0;
			}
			if (first == 0) first = 1, res = cur;
			else if (cur != res) {
				flag = 1;
				break;
			}
		}
		pp[i] = 0;
		if (flag) continue;
		ans = max(ans, num);
	}
	if (ans == 1) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}