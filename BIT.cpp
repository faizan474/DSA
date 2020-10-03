#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb2l(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;

#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll bit[100005];
ll size=100000;
ll query(ll x){
    ll ans=0;
    for(;x>0;x-=(x&(-x))) ans+=bit[x];
    return ans;
}
void update(ll x,ll val){
    for(;x<=100000;x+=x&(-x))
    bit[x]+=val;
}
/* range update
void range_update(ll l,ll r,ll val){
    update(l,val);
    update(r+1,-val);
}

// range update and range queries 
// both range update and range queries uses 2 BIT;
void range_update(ll l,ll r,ll val){
    update(bit1,l,val);
    update(bit1,r+1,val);
    update(bit2,l,val*(l-1));
    update(bit2,r+1,(-val)*(r));
}

// prefix sum 
ll prefixsum(ll idx){
    return querie(bit1,idx)*idx-querie(bit2,idx);
}
ll range_sum(ll l,ll r){
    return querie(r)-querie(l-1);
}
*/
void solve(){
}

int main(){
    ll t=1;
//cin>>t;
    while(t--){
     solve();
     cout<<endl;
    }
    return 0;
}
