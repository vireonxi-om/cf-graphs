// Problem: Decreasing Game
// URL: https://codeforces.com/problemset/problem/1839/E
// Rating: 2400
// Tags: constructive algorithms, dfs and similar, dp, greedy, interactive
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

const int N = 91000;
const int M = 1;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, a[310], flag[310];
vector<int> dp[N]; 


int main() {
	cin >> n;
	rep(j, 0, N) dp[j].clear();
	dp[0].pb(0);
	int sum = 0;
	repn(i, 1, n) {
		cin >> a[i];
		sum += a[i];
		per(j, 0, N - a[i]) {
			if (! dp[j].size()) continue;
			if (! dp[j + a[i]].size()) {
				dp[j + a[i]] = dp[j];
				dp[j + a[i]].pb(i);
			} 
		}
	}
	if (sum % 2 || ! dp[sum / 2].size()) {
		cout << "First\n";
		fflush(stdout);
		int p1 = 1, p2 = 1;
		while (1) {
			repn(i, 1, n) {
				if (a[i]) {
					p1 = i; break;
				}
			}
			cout << p1 << "\n";
			fflush(stdout);
			cin >> p2;
			if (! p2) break;
			int num = min(a[p1], a[p2]);
			a[p1] -= num; a[p2] -= num;
		}
	}
	else {
		cout << "Second\n";
		fflush(stdout);
		for (auto x : dp[sum / 2]) flag[x] = 1;
		int p1 = 1, p2 = 1;
		while (1) {
			cin >> p1;
			if (! p1) break; 
			if (flag[p1]) {
				repn(i, 1, n) {
					if (! flag[i] && a[i]) {
						p2 = i; break;
					}
				}
			}
			else {
				repn(i, 1, n) {
					if (flag[i] && a[i]) {
						p2 = i; break;
					}
				}
			}
			cout << p2 << "\n";
			fflush(stdout);
			int num = min(a[p1], a[p2]);
			a[p1] -= num; a[p2] -= num;
		}
	}
	return 0;
}// maintenance note (2): minor readability pass on this file — 2026-08-22
