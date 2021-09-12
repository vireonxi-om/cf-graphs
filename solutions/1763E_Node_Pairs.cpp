// Problem: Node Pairs
// URL: https://codeforces.com/problemset/problem/1763/E
// Rating: 2200
// Tags: dp, graphs, math, number theory
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
const int M = 11000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int p, num[700], dp[N], lst[N], val[N];
vector<int> ns;

int main() {
    IO;
    cin >> p;
    repn(i, 2, 700) {
    	if (i * (i - 1) / 2 > p) break;
    	num[i] = i * (i - 1) / 2;
	}
	rep(i, 1, N) dp[i] = inf;
	repn(i, 2, 700) {
		if (num[i] == 0) break;
		repn(j, 0, p - num[i]) {
			if (dp[j] + i <= dp[j + num[i]]) {
				dp[j + num[i]] = dp[j] + i;
			    lst[j + num[i]] = j;
			    val[j + num[i]] = i;
			}
			
		}
	}
	//repn(i, 0, 10) cout << dp[i] << " "; cout << "\n";
	int cur = p, ans = dp[p], sum = 0;
	while (val[cur]) {
		sum += val[cur] * (val[cur] - 1) / 2;
		cur = lst[cur];
	}
	sum = ans * (ans - 1) / 2 - sum;
	cout << ans << " " << sum << "\n";
    return 0;
}




