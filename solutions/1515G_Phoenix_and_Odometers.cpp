// Problem: Phoenix and Odometers
// URL: https://codeforces.com/problemset/problem/1515/G
// Rating: 2700
// Tags: dfs and similar, graphs, math, number theory
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
const int N=210000;
vector<pair<int, int>> g[N];
vector<ll> len[N];
int id[N], low[N], instack[N], cnt, scc[N], scnt;
stack<int> st;
ll clen[N], dis[N];

ll gcd(ll a, ll b){
    return b==0? a: gcd(b, a%b);
}

void dfs(int x, ll w){
    st.push(x);
    instack[x]=1;
    id[x]=++cnt; low[x]=id[x];
    dis[x]=w;
    for(auto p: g[x]){
        int nxt=p.first;
        ll cost=p.second;
        if(id[nxt]==0){
            dfs(nxt, w+cost);
            low[x]=min(low[x], low[nxt]);
        }
        else if(instack[nxt]){
            len[x].push_back(dis[x]-dis[nxt]+cost);
            low[x]=min(low[x], low[nxt]);
        }
    }
    if(low[x]==id[x]){
        scnt++;
        ll d=0;
        while(!st.empty() && st.top()!=x){
            scc[st.top()]=scnt;
            for(auto y:len[st.top()]) d=gcd(d, y);
            instack[st.top()]=0;
            st.pop();
        }
        st.pop();
        scc[x]=scnt;
        for(auto y: len[x]) d=gcd(d, y);
        instack[x]=0;
        clen[scnt]=d;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int x, y, w, q;
    for(int i=1; i<=m; i++){
        scanf("%d%d%d", &x, &y, &w);
        g[x].push_back(make_pair(y, w));
    }
    for(int i=1; i<=n; i++){
        if(id[i]==0) dfs(i, 0);
    }
    scanf("%d", &q);
    int v, s, t;
    while(q--){
        scanf("%d%d%d", &v, &s, &t);
        ll d=gcd(t, clen[scc[v]]);
        if((t-s)%d==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}



