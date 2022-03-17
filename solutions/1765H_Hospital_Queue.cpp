// Problem: Hospital Queue
// URL: https://codeforces.com/problemset/problem/1765/H
// Rating: 2200
// Tags: binary search, graphs, greedy, implementation
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
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = (n) - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 2100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, m, a[N], du[N];
vector<int> h[N], g[N];
PII b[N];
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> a[i], h[a[i]].pb(i);
	repn(i, 1, m) cin >> b[i].fi >> b[i].se, g[b[i].se].pb(b[i].fi);
	repn(i, 1, n) {
		repn(i, 1, n) du[i] = 0;
		repn(i, 1, m) du[b[i].fi]++;
		repn(i, 1, n) du[i]++;
		queue<int> que;
		int flag = 0, res;
		pern(j, 1, n) {
			for (auto x: h[j]) {
				du[x]--;
				if (du[x] == 0) {
					if (x == i) flag = 1;
					else que.push(x);
				}
			}
			if (!que.empty()) {
				int now = que.front(); que.pop();
				for (auto y: g[now]) {
					du[y]--;
					if (du[y] == 0) {
						if (y == i) flag = 1;
						else que.push(y);
					}
				}
			}
			else {
				cout << j;
				break;
			}
		}
		
		
		if (i != n) cout << " ";
		else cout << "\n";
	}
	return 0;
}