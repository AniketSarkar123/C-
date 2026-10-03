#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define fr              first
#define sc              second
#define ins             insert
#define pi              pair<int, int>
#define pl              pair<ll,ll>
#define vi              vector<int>
#define vl              vector<ll>
#define sz(x)           (int)((x).size())
#define all(v)          v.begin(),v.end()
#define acm(v)          accumulate(all(v),0)
#define srt(v)          sort(all(v))
#define rev(v)          reverse(all(v))
#define rep(i,a,b)      for(int i = a; i < b; ++i)
#define irep(i,a,b)     for(int i = a-1; i >= b; --i)
#define nl              cout << '\n'
template<typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }// cin >> pair<T1, T2>
template<typename T>istream& operator>>(istream &istream, vector<T> &v){ for (auto &it : v)    cin >> it; return istream; }// cin >> vector<T>
template<typename T1, typename T2>ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << ":" << p.second); }// cout << pair<T1, T2>
template<typename T>ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; } // cout << vector<T>
//size of vector must be initialized for taking input
const int mod = 1e9+7;

const int N=1e5+10;
vector<int> g[N];

vi height(N,0);
void dfs(int vertex,int par=0){
 //steps on vertex after entering vertex
 for(int child: g[vertex]){
     //steps on child before entering child
        
     if(child==par) continue;
     //depth[child]=depth[vertex]+1;
     dfs(child,vertex);
     height[vertex]=max(height[vertex],height[child]+1);
     //steps on child after exiting child 
 }
 //steps on vertex before entering vertex
}

void solve(){
    rep(i,0,N) height[i]=0;
    rep(i,0,N) g[i].clear();
    
    int n;cin>>n;
    vector<vector<int>> g(n+1);
    rep(i,0,n-1){
        int x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    dfs(1);
    int mx=*max_element(all(height));
    cout<<(mx+1)<<endl;
}

int32_t main() {
    
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    //turn off for debug,interactive problems
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
