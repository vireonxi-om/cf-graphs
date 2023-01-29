// Problem: Train Splitting
// URL: https://codeforces.com/problemset/problem/1776/F
// Rating: 1700
// Tags: constructive algorithms, graphs, greedy
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

const int N = 110000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

vector<PII> g[60];
int n, m, a[2500], b[60];

void solve() {
	cin >> n >> m;
	int u, v;
	repn(i, 1, n) g[i].clear();
	repn(i, 1, m) {
		a[i] = 0;
		cin >> u >> v;
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
	}
	int ans = 0;
	if (m == n * (n - 1) / 2) {
		ans = 3; 
		a[g[1][0].se] = 2;
		rep(i, 1, g[1].size()) {
			a[g[1][i].se] = 1;
		} 
		repn(i, 1, m) if (!a[i]) a[i] = 3;
	}
	else {
		ans = 2;
		repn(i, 1, n) {
			if (g[i].size() == n - 1) continue;
			int j = 0;
			repn(k, 1, n) b[k] = 0;
			b[i] = 1;
			for (auto x : g[i]) {
				b[x.fi] = 1;
			} 
			repn(k, 1, n) if (!b[k]) {
				j = k; break;
			}
			//cout << i << " " << j << "\n";
			for (auto x : g[i]) a[x.se] = 1;
			for (auto x : g[j]) a[x.se] = 2;
			repn(i, 1, m) if (!a[i]) a[i] = 1;
			break;
		}
	}
	cout << ans << "\n";
	repn(i, 1, m) cout << a[i] << " ";
	cout << "\n";
}
 
int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve(); 
	return 0;	
	
}



