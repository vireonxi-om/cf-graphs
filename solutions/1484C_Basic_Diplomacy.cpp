// Problem: Basic Diplomacy
// URL: https://codeforces.com/problemset/problem/1484/C
// Rating: 1600
// Tags: combinatorics, flows, greedy, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, d[110000], ans[110000];
vector<int> f[110000], day[110000];

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<110000; i++){ f[i].clear(); day[i].clear(); ans[i]=-1;}
    int num;
    for(int i=1; i<=m; i++){
        scanf("%d", &d[i]);
        for(int j=1; j<=d[i]; j++){
            scanf("%d", &num);
            day[i].push_back(num);
            f[num].push_back(i);
        }
    }
    int t=(m+1)/2;
    bool l=true, can=false;
    for(int i=1; i<=n; i++){
        int tot=f[i].size(), cnt=0;
        if(tot>t){
            l=false;
            for(auto x: f[i]){
                if(d[x]>1) cnt++;
            }
            if(tot-cnt<=t){
                can=true;
                cnt=tot-t;
                for(auto x: f[i]){
                    if(cnt && d[x]>1){
                        int now=0;
                        while(day[x][now]==i) now++;
                        ans[x]=day[x][now];
                        cnt--;
                    }
                    else ans[x]=i;
                }
            }
        }
    }
    if(can){
        printf("YES\n");
        for(int i=1; i<=m; i++){
            if(ans[i]==-1) ans[i]=day[i][0];
            printf("%d ", ans[i]);
        }printf("\n");
    }
    else if(l){
        printf("YES\n");
        for(int i=1; i<=m; i++){
            ans[i]=day[i][0];
            printf("%d ", ans[i]);
        }printf("\n");
    }
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
