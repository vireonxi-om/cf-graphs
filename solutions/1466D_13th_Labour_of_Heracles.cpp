// Problem: 13th Labour of Heracles
// URL: https://codeforces.com/problemset/problem/1466/D
// Rating: 1500
// Tags: data structures, greedy, sortings, trees
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000];
vector<int> ed[110000];
vector<int> val;

void solve(){
    scanf("%d", &n);
    val.clear();
    ll sum=0;
    for(int i=1; i<=n; i++){ scanf("%d", &a[i]); ed[i].clear(); sum+=a[i];}
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        int t=ed[i].size()-1;
        while(t--) val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    ll result=sum; printf("%lld ", result);
    if(!val.empty()) {
        auto it = val.end();
        it--;
        for (int i = 2; i <= n - 1; i++) {
            result += (*it);
            it--;
            printf("%lld ", result);
        }
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}