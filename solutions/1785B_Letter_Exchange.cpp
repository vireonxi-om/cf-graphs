// Problem: Letter Exchange
// URL: https://codeforces.com/problemset/problem/1785/B
// Rating: 1900
// Tags: constructive algorithms, graphs, greedy, implementation
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

int n, cnt[11]; 
queue<int> q[11];
map<string, int> m;
vector<pair<pair<int, string>, pair<int, string>>> ans;

void func(int a, int b, int ta, int tb, string cha, string chb) {
	int num = min(cnt[a], cnt[b]);
	cnt[a] -= num; cnt[b] -= num;
	cnt[ta] += num; cnt[tb] += num;
	repn(i, 1, num) {
		int cura = q[a].front(), curb = q[b].front();
		ans.pb(mp(mp(cura, cha), mp(curb, chb)));
		q[a].pop(); q[b].pop();
		q[ta].push(cura); q[tb].push(curb);
	}
}

void solve() {
	cin >> n;
	repn(i, 1, 10) {
		cnt[i] = 0;
		while (!q[i].empty()) q[i].pop();
	}
	ans.clear();
	string s;
	repn(i, 1, n) {
		cin >> s;
		sort(s.begin(), s.end());
		cnt[m[s]] ++;
		q[m[s]].push(i);
	}
	string i = "i", n = "n", w = "w";
	func(1, 7, 2, 4, i, n);
	func(1, 10, 3, 6, i, w);
	func(7, 10, 8, 9, n, w);
	func(1, 8, 2, 5, i, n);
	func(1, 9, 3, 5, i, w);
	func(7, 3, 4, 5, n, i);
	func(7, 6, 8, 5, n, w);
	func(10, 2, 6, 5, w, i);
	func(10, 4, 9, 5, w, n);
	
	func(2, 9, 5, 5, i, w);
	func(3, 8, 5, 5, i, n);
	func(4, 6, 5, 5, n, w);
	
	func(3, 9, 6, 5, i, w);
	func(4, 6, 5, 5, n, w);
	
	func(2, 8, 4, 5, i, n);
	func(4, 6, 5, 5, n, w);
	
	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x.fi.fi << " " << x.fi.se << " " << x.se.fi << " " << x.se.se << "\n"; 
	}
}

int main() {
	IO;
	m["iii"] = 1; m["iin"] = 2; m["iiw"] = 3; m["inn"] = 4;
	m["inw"] = 5; m["iww"] = 6; m["nnn"] = 7; m["nnw"] = 8;
	m["nww"] = 9; m["www"] = 10;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;	
}



