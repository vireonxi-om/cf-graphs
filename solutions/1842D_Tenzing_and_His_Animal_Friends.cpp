// Problem: Tenzing and His Animal Friends 
// URL: https://codeforces.com/problemset/problem/1842/D
// Rating: 1900
// Tags: constructive algorithms, graphs, greedy
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC ch[k][0] 
#define RC ch[k][1]
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

const int N = 110;
const int M = 610000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, k, t[N][N], y[N];
LL len[N], ans[N];
vector<pair<int, LL>> g[N];


void update(int i) {
	for (auto pr : g[i]) {
		int id = pr.fi; LL val = pr.se;
		len[id] = min(len[id], len[i] + val);
	}
}

LL findm() {
	LL val = INF;
	repn(i, 1, n) if (!y[i]) val = min(val, len[i]);
	return val;
}

int main()
{
	IO;
	cin >> n >> k; 
	repn(i, 1, n) {
		len[i] = INF; y[i] = 0;
	}
	int u, v; LL val;
	repn(i, 1, k) {
		cin >> u >> v >> val;
		if (v == n) {
			len[u] = min(len[u], val); continue;
		}
		g[u].pb(mp(v, val)); g[v].pb(mp(u, val));
	}
	repn(i, 1, n) t[0][i] = 1;
	len[n] = 0;
	int r = 1;
	LL tot = 0;
	while (1) {
		repn(i, 1, n) t[r][i] = t[r - 1][i];
	    LL cur = findm();
	    while (1) {
	    	bool can = false;
	    	repn(i, 1, n) {
		    	if (len[i] == cur && !y[i]) {
		    		can = true; update(i); y[i] = 1; t[r][i] = 0;
				}
			}
			if (!can) break;
		}
	    
		int cnt = 0;
		repn(i, 1, n) {
			len[i] -= cur;
			if (!y[i]) cnt ++;
		}
		if (y[1] || cnt == 0) {
			r --; break;
		}
	    ans[r] = findm();
	    tot += ans[r];
	    r ++;
	}
	if (tot > 1e12) cout << "inf\n";
	else {
		cout << tot << " " << r << "\n";
		repn(i, 1, r) {
			repn(j, 1, n) cout << t[i][j];
			cout << " " << ans[i] << "\n";
		}
	}	
	return 0;
}
