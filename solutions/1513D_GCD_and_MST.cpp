// Problem: GCD and MST
// URL: https://codeforces.com/problemset/problem/1513/D
// Rating: 2000
// Tags: constructive algorithms, dsu, graphs, greedy, number theory, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
ll p, a[210000], yes[210000];
set<pair<ll, int>> b;

void solve(){
    scanf("%d%lld", &n, &p);
    b.clear();
    for(int i=1; i<=n; i++) yes[i]=0;
    for(int i=1; i<=n; i++){ scanf("%lld", &a[i]); b.insert(make_pair(a[i], i));}
    ll ans=0;
    for(auto x:b){
        if(x.first>=p) break;
        if(yes[x.second]==1 && yes[max(0, x.second-1)]==1) continue;
        ll val=x.first;
        int l=x.second, r=x.second;
        while(l-1>=1 && a[l-1]%val==0 && yes[l-1]!=1) l--;
        while(r+1<=n && a[r+1]%val==0 && yes[r]!=1) r++;
        for(int i=l; i<r; i++) yes[i]=1;
        ans+=val*(r-l);
    }
    for(int i=1; i<n; i++){
        if(yes[i]!=1) ans+=p;
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
