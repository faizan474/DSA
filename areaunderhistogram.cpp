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
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    fr(i,0,n)
    cin>>a[i];
    stack<ll>s;
    ll i=0;
    ll area=0;
    while(i<n){
        if(s.empty()|| a[s.top()]<=a[i]){
            s.push(i);i++;
        }
        else{
            ll tp =s.top();
            s.pop();
            ll tmparea=a[tp]*(s.empty()?i:i-s.top()-1);
            area=max(area,tmparea);
            
        }
    }
    while(!s.empty()){
        ll tp=s.top();
        s.pop();
       ll tmparea=a[tp]*(s.empty()?i:i-s.top()-1);
       area=max(area,tmparea);
    }
    cout<<area<<endl;
    
}
int main(){
    ll t=1;
  cin>>t;
    while(t--){
solve();

	}
    return 0;
}