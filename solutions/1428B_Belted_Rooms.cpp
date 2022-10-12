// Problem: Belted Rooms
// URL: https://codeforces.com/problemset/problem/1428/B
// Rating: 1200
// Tags: graphs, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, r[310000];

void solve(){
    scanf("%d", &n);
    memset(r, 0, sizeof(r));
    getchar();
    char ch, now='-';
    bool can=true;
    for(int i=0; i<n; i++){
        scanf("%c", &ch);
        if(ch=='-') {
            r[i]=1; r[(i+1)%n]=1;
        }
        else if(now!='-' && ch!=now) can=false;
        else now=ch;
    }
    int sum=0;
    for(int i=0; i<n; i++) if(r[i]==1) sum++;
    if(can) printf("%d\n", n);
    else printf("%d\n", sum);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
