// Problem: BinCoin
// URL: https://codeforces.com/problemset/problem/1773/B
// Rating: 2200
// Tags: binary search, divide and conquer, hashing, implementation, probabilities, trees
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

const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, k;
int a[N][N], p[N], pp[N], b[N];

int main() {
	IO;
	memset(p, -1, sizeof(p));
	cin >> n >> k;
	repn(i, 1, k) repn(j, 1, n) cin >> a[i][j];
	if (n == 1) {
		cout << "-1\n";
		return 0;
	}
	repn(i, 1, n / 2) {
		int len = n - (i - 1) * 2;
		map<int, int> S[N];
		repn(j, 1, k) {
			rep(l, 1, len) {
				S[a[j][l]][a[j][l + 1]]++;
			}
		}
		int pos, mn = inf, x, y;
		repn(j, 1, n) if (!pp[j] && S[j].size() == 2) {
			auto it = S[j].begin();
			auto it2 = it;
			it2++;
			int delta = abs((it -> second) - (it2 -> second));
			if ((it -> second) + (it2 -> second) != k) continue;
			if (delta < mn) {
				pos = j, x = it -> first, y = it2 -> first;
				mn = delta;
			}
		}
		p[x] = p[y] = pos;
		pp[x] = pp[y] = pp[pos] = 1;
		repn(j, 1, k) {
			int nu = 0;
			repn(l, 1, len) {
				if (a[j][l] != x && a[j][l] != y) b[++nu] = a[j][l];
			}
			repn(l, 1, nu) a[j][l] = b[l];
		}
	}
	repn(i, 1, n) {
		cout << p[i];
		if (i != n) cout << " ";
		else cout << "\n";
	}
	return 0;
}