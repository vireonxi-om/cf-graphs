// Problem: Trees of Tranquillity
// URL: https://codeforces.com/problemset/problem/1529/E
// Rating: 2300
// Tags: data structures, dfs and similar, greedy, trees
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p, st[310000], ft[310000];
vector<int> a[310000], b[310000];
set<pair<int, int>> s;
int t, ans;


void dfs2(int u, int v){
    st[u]=++t;
    for(auto x:b[u]){
        if(x==v) continue;
        dfs2(x, u);
    }
    ft[u]=++t;
}


int check(int u){
    bool can=true;
    int r=0;
    auto it=s.lower_bound(make_pair(st[u], u));
    if(it!=s.end() && ft[(*it).second]<ft[u]) can=false;
    if(can && it!=s.begin()){
        it--;
        if(ft[(*it).second]>ft[u]){
            r=(*it).second;
            s.erase(it);
        }
    }
    if(can) s.insert(make_pair(st[u], u));
    return r;
}

void dfs(int u, int v){
    int r=check(u);
    if(a[u].size()==1) ans=max(ans, (int)s.size());
    else{
        for(auto x:a[u]){
            if(x==v) continue;
            dfs(x, u);
        }
    }
    if(r) s.insert(make_pair(st[r], r));
    s.erase(make_pair(st[u], u));
}

void solve(){
    s.clear();
    scanf("%d", &n);
    for(int i=1; i<=n; i++){ a[i].clear(); b[i].clear();}
    t=0; ans=0;
    for(int i=2; i<=n; i++){
        scanf("%d", &p);
        a[i].push_back(p);
        a[p].push_back(i);
    }
    for(int i=2; i<=n; i++){
        scanf("%d", &p);
        b[i].push_back(p);
        b[p].push_back(i);
    }
    a[1].push_back(0);
    b[1].push_back(0);
    dfs2(1, 0); dfs(1, 0);
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
