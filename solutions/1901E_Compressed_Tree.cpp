// Problem: Compressed Tree
// URL: https://codeforces.com/problemset/problem/1901/E
// Rating: 2200
// Tags: dfs and similar, dp, graphs, greedy, sortings, trees
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 510000;
const int M = 1;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n;
LL a[N], dp[N];
vector<int> g[N];
LL ans = 0;

void dfs(int u, int v) {
	LL s[3];
	rep(i, 0, 3) s[i] = -INF;
	LL sum = 0;
	dp[u] = a[u];
	for (auto x : g[u]) {
		if (x == v) continue;
		dfs(x, u);
		if (dp[x] > 0) sum += dp[x];
		rep(i, 0, 3) {
			if (dp[x] <= s[i]) continue;
			per(j, i, 2) {
				s[j + 1] = s[j];
			}
			s[i] = dp[x];
			break;
		}
		dp[u] = max(dp[u], dp[x]);
	}
	if (s[1] != -INF) {
		LL cur = sum;
		rep(i, 0, 2) {
			if (s[i] < 0) cur += s[i];
		}
		cur += a[u];
		dp[u] = max(dp[u], cur);
	}
	if (s[2] != -INF) {
		LL cur = sum;
		rep(i, 0, 3) {
			if (s[i] < 0) cur += s[i];
		}
		cur += a[u];
		ans = max(ans, cur);
	}
	if (s[1] != -INF) {
		ans = max(ans, s[0] + s[1]);
	}
	if (s[0] != -INF) {
		ans = max(ans, s[0] + a[u]);
	}
	ans = max(ans, a[u]);
}

void solve() {
	cin >> n;
	repn(i, 1, n) {
		cin >> a[i];
		g[i].clear();
	}
	int u, v;
	rep(i, 1, n) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ans = 0;
	dfs(1, 0);
	cout << ans << "\n";
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
}