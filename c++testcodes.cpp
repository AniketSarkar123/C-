#include <bits/stdc++.h>
 
#define pb push_back
#define fr first
#define sc second
#define sz(x) (ll)x.size()
#define rep(n) for(ll i=0;i<n;++i)
#define all(v) v.begin(),v.end()
#define acm(v) accumulate(all(v),0LL)
#define op(v) cout<<v<<'\n'
#define op2(v) cout<<v<<" "
#define INF 1e18
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
const int mod = 1e9+7;
 
void fastIO(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

ll digsum(string s){
    ll r=0; 
    for(char c:s) r+=(c-'0');
    return r;
}
 
void f(ll n, map<ll,ll> &mp){
    for(ll i=2; i*i<=n; i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n>1) mp[n]++;
}
 
void f2(int n, map<int,int> &mp){
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            mp[i]--;
            n/=i;
        }
    }
    if(n>1) mp[n]--;
}
 
bool ispime(int n){
    if(n<2) return false;
    if(n==2) return true;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}


void updategraph(vector<vector<int>> &g,vector<int> &indeg){
    int n=g.size();
    int m=g[0].size();
    int maxi=1;
    for(int i=1;i<=n;i++){
        maxi=max(maxi,indeg[i]);
    }

    int maxver;

    for(int i=1;i<=n;i++){
        if(indeg[i]==maxi){
            maxver=i;
            break;
        }
    }

    for(auto v:g[maxver]){
        indeg[v]--;
    }

    indeg[maxver]=0;
    for(int i=1;i<=n;i++){
        auto v=g[i];
        for(auto x:v){
            if(indeg[x]==0){
                auto it=find(g[x].begin(),g[x].end(),maxver);
                if(it!=g[x].end()){
                    g[x].erase(it);
                }
            }
        }
    }



}

void dfs(int v,int c,vector<int> &vis,vector<vector<int>> &g,vector<vector<int>> &comp){
    if(vis[v]==1)
        return;
    vis[v]=1;
    comp[c].push_back(v);
    for(auto child:g[v]){
        dfs(child,c,vis,g,comp);
    }
}
 
struct compare {
    bool operator()(const string &a, const string &b) const {
        if (a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    }
};

set<string,compare> st;

void generate(int l,string s){
    if(s.size()!=0)
        st.insert(s);
    if(s.size()==l)
        return;
    for(char ch='a';ch<='z';ch++){
        s+=ch;
        generate(l,s);
        s.pop_back();
    }
}

int issub(string s,string t){
    int n=s.size();
    int m=t.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(s[i]==t[j]){
            j++;
        }
        if(j==m)
            return 1;
    }
    return 0;
}


int findp(vector<int>& p,int x){
    if(p[x]==x) 
        return x;
    return findp(p,p[x]);
    
}

int countinversions(vector<int> &v){
    int n=v.size();
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]){
                c++;
            }
        }
    }

    return c;
}

ll funcfac(int res){

   if(res%2==0)
       return 2;
    for(int i=2;i*i<=res;i++){
        if(res%i==0)
            return i;
    }

    return res;
}

int MEX(vector<int> &v){
    set<int> s;
    for(auto x:v){
        s.insert(x);
    }

    int mex=0;
    while(true){
        if(s.find(mex)==s.end()){
            return mex;
        }
        mex++;
    }
}

void solve(){
  int n;
  cin>>n;
  vi v(n);
  rep(n)
    cin>>v[i];
  vi v1=v;
  sort(all(v1));
  vi psum(n+1,0);
  psum[0]=0;
  psum[1]=v1[0];
  for(int i=2;i<=n;i++){
      psum[i]=psum[i-1]+v1[i-1];
  }

  vi ans;
  for(int k=0;k<n;k++){
       
  }


}
 
int main(){
    fastIO();
    int t;
    cin>>t;
   
    while(t--){
        solve();
    }
    return 0;
}
