// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

int digroot(int x){
    if(x==0)
        return 0;
    return 1+(x-1)%9;
}

int f(vector<int> &v){
    int n=v.size();
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int num=v[i];
        int sum=digroot(num);
        mp[sum]++;

    }

    int maxi=0;
    for(auto p:mp){
        maxi=max(maxi,p.second);
    }

    vector<int> res;

    for(auto p:mp){
        if(p.second==maxi){
            res.push_back(p.first);
        }
    }

    sort(res.begin(),res.end());
    return res[0];

    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<f(v)<<endl;
    }
}
