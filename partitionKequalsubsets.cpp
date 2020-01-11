#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
     ll dp[1<<17][17];
        bool find(vector<int>&v,ll bits,int k,ll sum,ll total){
        if(k==1)
            return true;
            if(dp[bits][k]!=-1)
                return (bool)dp[bits][k];
                
            bool res=false;
            
        for(int i=0;i<v.size();i++){
            if(!(bits&(1<<i)) &&  sum>=v[i]){
               res=res|find(v,bits|(1<<i),sum==v[i]?k-1:k,sum==v[i]?total:sum-v[i],total);
                }
            
           }
            dp[bits][k]=(ll)res;
               return res;
        }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        ll n=nums.size();
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%k!=0 )
            return false ;
        //cout<<sum/k;
   //    ll dp[1<<17][k];
        memset(dp,-1,sizeof(dp));
        return find(nums,(ll)0,k,sum/k,sum/k);    
        
    }

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    if(canPartitionKSubsets(v,k))
    cout<<true;
    else cout<<false;
    return 0;
    

}