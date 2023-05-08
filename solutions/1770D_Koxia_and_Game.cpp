// Problem: Koxia and Game
// URL: https://codeforces.com/problemset/problem/1770/D
// Rating: 2000
// Tags: constructive algorithms, data structures, dfs and similar, dsu, flows, games, graph matchings, graphs, implementation
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
const int M = 11000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[N], b[N], numd[N], nume[N], f[N], flag[N], f2[N];

int findf(int i) {
	if (i != f[i]) {
		f[i] = findf(f[i]);
	}
	return f[i];
}

void solve() {
	cin >> n;
	repn(i, 1, n){
		f[i] = i;
		nume[i] = 0;
		numd[i] = 1;
		flag[i] = 0;
		f2[i] = 0;
	}
	repn(i, 1, n) cin >> a[i];
	repn(i, 1, n) cin >> b[i];
	repn(i, 1, n) {
		if (a[i] == b[i]) {
			int f = findf(a[i]);
			nume[f] ++;
			f2[a[i]] = 1;
		}
		else {
			int fa = findf(a[i]), fb = findf(b[i]);
			if (fa != fb) {
				nume[fb] += nume[fa]; numd[fb] += numd[fa];
				f[fa] = fb;
			}
			nume[fb] ++;
		}
	}
	repn(i, 1, n){
		int f = findf(i);
		if (f2[i]) flag[f] = 1;
	} 
	long long ans = 1; 
	bool yes = true;
	repn(i, 1, n) {
		if (f[i] == i) {
			if (numd[i] != nume[i]){
				//cout <<"i = " << i << "\n";
				yes = false;
			} 
			else {
				if (flag[i]) ans *= n;
				else ans *= 2;
				ans %= mod;
			}
		}
	}
	if (!yes) ans = 0;
	cout << ans << "\n";
}

int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}




