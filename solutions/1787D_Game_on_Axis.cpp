// Problem: Game on Axis
// URL: https://codeforces.com/problemset/problem/1787/D
// Rating: 1900
// Tags: combinatorics, dfs and similar, dsu, graphs, implementation
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 210000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[N], g[N], tp[N], rt[N], flag[N], ch[N]; 
vector<int> ed[N];

int findfa(int i) {
	return g[i] == i ? i : g[i] = g[g[i]];
}

void dfs(int u, int fa) {
	for (auto v: ed[u]) {
		dfs(v, u);
		ch[u] += ch[v];
	}
	ch[u] ++;
}


void solve() {
	cin >> n;
	repn(i, 1, n) {
		cin >> a[i]; 
		g[i] = 0;
		tp[i] = 0; 
		rt[i] = 0; flag[i] = 0;
		ch[i] = 0; ed[i].clear();
	}
	repn(i, 1, n) {
		if (g[i]) continue;
		g[i] = i;
		int cur = i, nxt = i + a[i];
		while (1) {
			//cout << cur << " " << nxt << "\n";
			if (nxt < 1 || nxt > n) {
				rt[g[cur]] = cur;
				break;
			}
			else if (g[nxt] && g[nxt] != g[cur]) {
				g[findfa(cur)] = findfa(nxt);
				break;
			}
			else if (g[nxt]) {
				tp[findfa(cur)] = 1;
				break;
			}
			g[nxt] = g[cur];
			cur = nxt;
			nxt = cur + a[cur];
		}
	}
	int cnt1 = 0, cnt0 = 0;
	repn(i, 1, n) {
		g[i] = findfa(g[i]);
		if (tp[g[i]] == 0) cnt0 ++;
		else cnt1 ++;
	}
	//repn(i, 1, n) cout << g[i] << " ";
	//cout << "\n"; 
	int cur = 1, nxt = cur + a[cur];
	flag[1] = 1;
	while (1) {
		if (nxt < 1 || nxt > n) break;
		if (flag[nxt]) break;
		cur = nxt;
		nxt = cur + a[cur];
		flag[cur] = 1;
	}
	LL ans;
	if (tp[g[1]]) {
		ans = 0;
		repn(i, 1, n) {
			if (flag[i]) {
				ans += n + 1 + cnt0;
			}
		}
	}	
	else {
		repn(i, 1, n) {
			if (rt[g[1]] == i) continue;
			if (g[i] == g[1]) ed[i + a[i]].pb(i);
		}
		ans = (LL) n * (2 * n + 1);
		dfs(rt[g[1]], 0);
		repn(i, 1, n) {
			if (flag[i]) {
				ans -= ch[i]; ans -= cnt1;
			}
		}
		
	}
	cout << ans << "\n";
}

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;	
}



