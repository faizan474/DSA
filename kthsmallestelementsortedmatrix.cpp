#include<bits/stdc++.h>
using namespace std;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        cout<<n<<" "<<m<<endl;
        multiset<pair<int,pair<int,int>>>s;
        
        
        for(int i=0;i<matrix[0].size();i++){
            s.insert({matrix[0][i],{0,i}});
        }
        
        
        int kk=1;
        int ans=0;
        
        
        while(kk<=k && !s.empty()){
            auto it=*s.begin();
            cout<<it.first<<" "<<kk<<endl;
            s.erase(s.begin());
        
            if(it.second.first+1<n && it.second.second<m){
                s.insert({matrix[it.second.first+1][it.second.second],{it.second.first+1,it.second.second}});}
                if(k==kk){
                    return it.first;
                }
            kk++;
             
        }
    }
    int main(){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        int k;
        cin>>k;

        cout<<kthSmallest(v,k);
    return 0;
    }