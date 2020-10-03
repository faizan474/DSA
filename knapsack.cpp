#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
ll doit(ll *v,ll *w,ll mxw,ll idx){
    if(mxw<0 || idx<0)
    return 0;
     if(mxw<w[idx])
     return doit(v,w,mxw,idx-1);
     else return max(doit(v,w,mxw-w[idx],idx-1)+v[idx],doit(v,w,mxw,idx-1));
    
}
int main(){
    ll t=1;
  cin>>t;
    while(t--){
        ll n;
        cin>>n;
                ll maxw;
        cin>>maxw;
        ll v[n+1];
        ll w[n+1];
        fr(i,0,n)
        cin>>v[i];
        fr(i,0,n)
        cin>>w[i];
        
        
     cout<<doit(v,w,maxw,n-1)<<endl;
         }
    return 0;
}