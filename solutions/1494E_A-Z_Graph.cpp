// Problem: A-Z Graph
// URL: https://codeforces.com/problemset/problem/1494/E
// Rating: 2400
// Tags: constructive algorithms, data structures, graphs, hashing
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m;
set<pair<int, int>> p[30], d, e;

int main(){
    scanf("%d%d", &n, &m);
    char s[5];
    int a, b;
    while(m--){
        scanf("%s", &s);
        if(s[0]=='+'){
            scanf("%d%d", &a, &b);
            scanf("%s", &s);
            p[s[0]-'a'].insert(make_pair(a, b));
            for(int i=0; i<26; i++){
                auto it=p[i].find(make_pair(b, a));
                if(it==p[i].end()) continue;
                if(i==s[0]-'a') e.insert(make_pair(min(a, b), max(a, b)));
                else d.insert(make_pair(min(a, b), max(a, b)));
            }
        }
        else if(s[0]=='?'){
            scanf("%d", &a);
            if(a%2==0){
                if(e.empty()) printf("NO\n");
                else printf("YES\n");
            }
            else{
                if(e.empty() && d.empty()) printf("NO\n");
                else printf("YES\n");
            }
        }
        else{
            scanf("%d%d", &a, &b);
            for(int i=0; i<26; i++){
                auto it=p[i].find(make_pair(a, b));
                if(it==p[i].end()) continue;
                p[i].erase(it);
            }
            auto it=d.find(make_pair(min(a, b), max(a, b)));
            if(it!=d.end()) d.erase(it);
            it=e.find(make_pair(min(a, b), max(a, b)));
            if(it!=e.end()) e.erase(it);
        }
    }
}
