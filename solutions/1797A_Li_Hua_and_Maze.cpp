// Problem: Li Hua and Maze
// URL: https://codeforces.com/problemset/problem/1797/A
// Rating: 800
// Tags: constructive algorithms, flows, graphs, greedy, implementation
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
typedef long double LD;

const int N = 210000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m;
int x1, x2, y1, y2;

void solve() {
	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;
	int ans = 4;
	int num = 4;
	if (y1 == 1 || y1 == m) num --;
	if (x1 == 1 || x1 == n) num --;
	ans = min(ans, num);
	num = 4;
	if (y2 == 1 || y2 == m) num --;
	if (x2 == 1 || x2 == n) num --;
	ans = min(ans, num);
	cout << ans << "\n";
} 

int main() {
	IO; 
	int t;
	cin >> t;
	repn(i, 1, t) solve(); 
	return 0;
}



