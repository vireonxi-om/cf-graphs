// Problem: Divisible by Twenty-Five
// URL: https://codeforces.com/problemset/problem/1575/D
// Rating: 1800
// Tags: brute force, dfs and similar, dp
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

const int N = 310000;
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

int n, a[20], cnt1, cnt2;
char s[20];


int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    repn(i, 1, n) {
        if (s[i] == '_'){ a[i] = -1; }
        else if (s[i] == 'X'){ a[i] = -2; }
        else a[i] = s[i] - '0';
    }
    int ans = 0;
    if (n > 1) {
        int t1 = 1, t2 = 1;
        rep(i, 1, n) t1 *= 10;
        repn(i, 1, n) t2 *= 10;
        t2 --;
        if (n == 2) t1 = 25;
        for (int i = t1; i <= t2; i += 25) {
            int now, num = i, x = -1;
            bool yes = true;
            pern(j, 1, n) {
                now = num % 10; num /= 10;
                if (a[j] == -2){
                    if (x != -1 && x != now) {
                        yes = false; break;
                    }
                    else x = now;
                }
                else if (a[j] >= 0 && a[j] != now) {yes = false; break;}
            }
            if (yes ) ans ++;
        }
    }
    else if (a[1] <= 0) ans = 1;
    printf("%d\n", ans);
    return 0;
}



