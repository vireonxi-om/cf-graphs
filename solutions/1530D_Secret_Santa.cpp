// Problem: Secret Santa
// URL: https://codeforces.com/problemset/problem/1530/D
// Rating: 1600
// Tags: constructive algorithms, flows, graphs, greedy, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=210000;
int n, ans[N], yes[N], id[N];
vector<int> g[N], l, wt, a;

void solve(){
    scanf("%d", &n);
    l.clear(); wt.clear(); a.clear();
    for(int i=1; i<=n; i++){ g[i].clear(); ans[i]=0; yes[i]=0;}
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &id[i]);
        g[id[i]].push_back(i);
    }
    int t, tot=0;
    for(int i=1; i<=n; i++){
        if(g[i].size()==0){ l.push_back(i); continue;}
        ans[g[i][0]]=i;
        yes[i]=1;
        tot++;
        if(g[i].size()>1){
            t=g[i].size()-1;
            for(int now=1; now<=t; now++) wt.push_back(g[i][now]);
        }
    }
    for(auto x:l){
        if(ans[x]) a.push_back(x);
    }
    t=wt.size()-1; int now=0;
    for(int i=0; i<t; i++){
        if(yes[wt[i+1]]){
            ans[wt[i]]=a[now];
            now++;
        }
        else{
            ans[wt[i]]=wt[i+1]; yes[wt[i+1]]=1;
        }
    }
    if(t>0){
        if(yes[wt[0]]) ans[wt[t]]=a[now];
        else ans[wt[t]]=wt[0];
    }
    else if(t==0){
        if(!a.empty()) ans[wt[0]]=a[now];
        else{
            int v=g[id[wt[0]]][0];
            ans[wt[0]]=ans[v];
            ans[v]=wt[0];
        }
    }
    printf("%d\n", tot);
    for(int i=1; i<=n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
