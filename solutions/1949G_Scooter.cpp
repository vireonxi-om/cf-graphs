// Problem: Scooter
// URL: https://codeforces.com/problemset/problem/1949/G
// Rating: 2300
// Tags: graphs, greedy
// Language: C++20 (GCC 13-64)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n;
string c, p;
int a[7], pos[7];
vector<int> b[7], ans;
vector<pair<string, int>> ot;

int main() {
	IO;
	cin >> n;
	cin >> c >> p;
	rep(i, 0, n) {
	    if (c[i] == p[i]) continue;
	    int tp;
	    if (c[i] == '-'){
                if (p[i] == 'C') tp = 1;
                else tp = 2;
	    }
	    else if (p[i] == '-') {
                if (c[i] == 'C') tp = 3;
                else tp = 4;
	    }
	    else {
                if (c[i] == 'C') tp = 5;
                else tp = 6;
	    }
	    a[tp] ++;
	    b[tp].pb(i + 1);
	}
	int tmp = 0;
	if (a[5] && a[6]) {
           if (a[1]) tmp = 1;
           else tmp = 2;
           ans.pb(tmp);
           a[tmp] --;
           int num = min(a[5], a[6]);
           a[5] -= num; a[6] -= num;
           repn(i, 1, num) {
               ans.pb(4 + tmp);
               ans.pb(7 - tmp);
           }
	}
	if (!a[5] && tmp == 1 && a[3]) {
        ans.pb(3);
        a[3] --;
    }
    if (!a[6] && tmp == 2 && a[4]) {
        ans.pb(4);
        a[4] --;
    }
	if (a[6]) {
            a[2] -= a[6];
            if (tmp == 2) a[2] ++;
            repn(i, 1, a[6]) {
                if (i > 1 || tmp != 2) ans.pb(2);
                ans.pb(6);
                if (a[3]) {
                        a[3] --;
                        ans.pb(3);
                }
            }

	}
	if (a[5]) {
            a[1] -= a[5];
            if (tmp == 1) a[1] ++;
            repn(i, 1, a[5]) {
                if (i > 1 || tmp != 1) ans.pb(1);
                ans.pb(5);
                if (a[4]) {
                        a[4] --;
                        ans.pb(4);
                }
            }

	}
	if (a[3]) {
            a[1] -= a[3];
            repn(i, 1, a[3]) {
                ans.pb(1);
                ans.pb(3);
            }
	}
	if (a[4]) {
            a[2] -= a[4];
            repn(i, 1, a[4]) {
                ans.pb(2);
                ans.pb(4);
            }
	}
	int st = 0;
	for (auto id : ans) {
	    int bid = b[id][pos[id]++];
	    ot.pb(mp("DRIVE ", bid));
        if (st) ot.pb(mp("DROPOFF", 0));
        if (id != 3 && id != 4) {
            ot.pb(mp("PICKUP", 0));
            if (id == 1 || id == 6) st = 1;
            else st = 2;
        }
        else st = 0;
	}
	cout << ot.size() << "\n";
	for (auto pr : ot) {
        cout << pr.fi;
        if (pr.se) cout << pr.se;
        cout << "\n";
	}
	return 0;
}
/*
11
CCCMMMMC---
MMMCC---CCM
*/
