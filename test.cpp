#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }

        int potsum=0;
        int tot=n+m;
        while(potsum%tot!=0){
            potsum++;
        }

        vector<pair<ll,ll>> emp;
        int i=0;
        int j=0;
        int ind=0;
        int sz=s.size();
        emp.push_back({0,0});
        while(i<n && j<m && ind<sz){
            if(s[ind]=='D')
                i++;
            else
                j++;
            emp.push_back({i,j});
            ind++;
            
        }

        vector<ll> sumr;
        for(auto v1:v){
            ll sum=accumulate(v1.begin(),v1.end(),0ll);
            sumr.push_back(sum);
        }


        vector<ll> sumc;
        for(int i=0;i<m;i++){
            ll sum=0;
            for(int j=0;j<n;j++){
                sum+=v[j][i];
            }
            sumc.push_back(sum);
        }

        for(auto p:emp){
            int r=p.first;
            int c=p.second;
            int old=v[r][c];
            ll sumrow=sumr[r];
            //ll sumcol=sumc[c];
            v[r][c]=-1*sumrow;
            sumc[c]=(sumc[c]-old+v[r][c]);
            sumr[r]=0;


        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

        






    }

}