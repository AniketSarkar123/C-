// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// // Global adjacency list for the graph
// unordered_map<int, vector<int>> adjList;

// // Global DFS function
// bool dfs(int start, int end, unordered_set<int>& visited, vector<int>& path) {
//     // Mark the current node as visited and add it to the path
//     visited.insert(start);
//     path.push_back(start);

//     // If the destination node is reached, return true
//     if (start == end) {
//         return true;
//     }

//     // Explore all neighbors of the current node
//     for (int neighbor : adjList[start]) {
//         if (visited.find(neighbor) == visited.end()) {
//             if (dfs(neighbor, end, visited, path)) {
//                 return true;
//             }
//         }
//     }

//     // If no path is found, backtrack
//     path.pop_back();
//     return false;
// }

// // Function to get the path from 'a' to 'b'
// vector<int> getPath(int a, int b) {
//     vector<int> path;
//     unordered_set<int> visited;
//     if (dfs(a, b, visited, path)) {
//         return path;
//     }
//     return {}; // Return an empty vector if no path is found
// }

// int main() {
//     // Create the graph
//     adjList[1] = {2, 3};
//     adjList[2] = {4};
//     adjList[3] = {4};
//     adjList[4] = {5};

//     int start = 1;
//     int end = 5;
//     vector<int> path = getPath(start, end);

//     if (!path.empty()) {
//         cout << "Path from " << start << " to " << end << ": ";
//         for (int node : path) {
//             cout << node << " ";
//         }
//         cout << endl;
//     } else {
//         cout << "No path found from " << start << " to " << end << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
 
#define pb push_back
#define fr first
#define sc second
 
#define sz(x) x.size()
#define rep(n) for(ll i=0;i<n;++i)
#define all(v) v.begin(),v.end()
#define acm(v) accumulate(all(v),0)
#define op(v) cout<<v<<'\n'
#define op2(v) cout<<v<<" "
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
 
const int mod = 1e9+7;
 
ll gcd(ll m,ll n){
    if(m%n==0) return n;
    else return gcd(n,m%n);
}
 
void fastIO(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}
 
ll digsum(string s){
    ll ans=0;
    for(int i=0;i<s.size();i++){
        ans+=(s[i]-'0');
    }
    return ans;
}
 
void f(ll n, map<ll,ll> &m){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            m[i]++;
            n/=i;
        }
    }
    if(n>1)
        m[n]++;
}
 
void f2(int n, map<int,int> &m){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            m[i]--;
            n/=i;
        }
    }
    if(n>1)
        m[n]--;
}
 
bool isprime(int n){
    if(n==2)
        return true;
    for(int i=2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
 
 
void solve() {
    
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 