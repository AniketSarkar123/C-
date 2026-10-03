#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int> nums={1,3,4,1,2,3,1};
   int n=nums.size();
    vector<vector<int>> v(n);
        for(auto v1:v){
            for(int i=0;i<n;i++){
                if(find(v1.begin(),v1.end(),nums[i])==v1.end()){
                    v1.push_back(nums[i]);
                }

                else
                    continue;
            }
        }

        for(auto v1:v){
            for(int i=0;i<v1.size();i++){
                cout<<v1[i]<<" ";
            }

            cout<<endl;
        }
}