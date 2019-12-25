#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define deb(x) cout<<#x<<" "<<x<<endl;
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool  sumBC(ll x,ll n,ll N){
    ll trm=1,ans=0;
    for(ll i=1;i<=n;i++){
        trm*=x-i+1;
        trm/=i;
        ans+=trm;
        if(ans>N)
        return false;
    }
    if(ans<N)
    return true;
    else return false;
}
ll eggdropping(int n,int k){
    // n=egg,k=floor
    ll expl=1,expr=k;
    while (expl<expr)
    {
        ll mid=(expl+expr)/2;
        if(sumBC(mid,n,k)){
            expl=mid+1;
        }
        else expr=mid;
    }
    return expl;
    
}

void solve(){
ll n,k ;
cin>>n>>k;
// n=eggs ,k=floor;
cout<<eggdropping(n,k);
}


int main(){
    ll t=1;
cin>>t;
    while(t--){
     solve();
   cout<<endl;
    }
    return 0;
}

