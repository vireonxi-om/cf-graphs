// Problem: Amazing Trick
// URL: https://codeforces.com/problemset/problem/1773/A
// Rating: 1900
// Tags: constructive algorithms, graph matchings, math, probabilities
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

const int rnd = 300;
int T, n, a[N], b[N], p[N], q[N], pp[N], pos[N];
int main() {
	IO;
	srand(time(NULL));
	cin >> T;
	while (T--) {
		cin >> n;
		repn(i, 1, n) cin >> a[i], p[i] = i;
		int flag = 0;
		repn(i, 1, rnd) {
			random_shuffle(p + 1, p + n + 1);
			int ff = 0;
			repn(j, 1, n) if (p[j] == j || a[p[j]] == j) {
				ff = 1;
				break;
			}
			if (ff) continue;
			repn(j, 1, n) b[j] = a[p[j]], pp[j] = 0, pos[b[j]] = j;
			repn(j, 1, n) if (!pp[j]) {
				int cur = j;
				while (!pp[cur]) {
					q[cur] = pos[cur];
					pp[cur] = 1;
					cur = pos[cur];
				}
			}
			flag = 1;
			cout << "Possible\n";
			repn(j, 1, n) {
				cout << p[j];
				if (j != n) cout << " ";
				else cout << "\n";
			}
			repn(j, 1, n) {
				cout << q[j];
				if (j != n) cout << " ";
				else cout << "\n";
			}
			break;
		}
		if (!flag) cout << "Impossible\n";
	}
				
	return 0;
}