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
typedef vector<vector<ll>> matrix;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// step 1 : define K     note: no of previous terms it depends on 
const ll K=2;
matrix mul(matrix &a,matrix &b){
    matrix c(K+1,vector<ll>(K+1));
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++){
                c[i][j]=c[i][j]+(a[i][k]*b[k][j])%mod;
                c[i][j]%=mod;
            }
        }
    }
    return c;
}git 
matrix powr(matrix &a,ll n){
    matrix ans(K+1,vector<ll>(K+1));
    for(int i=0;i<K;i++){
        ans[i][i]=1;
    }
    while(n){
        if(n&1)
        ans=mul(ans,a);
        a=mul(a,a);
        n=n>>1;
    }
    return ans;
}
void solve(){
    /* initial vector  f(n)=a*f(n-1)+b*f(n-2);
    F1=[1,1] ==> F1=[f(1),f(2)]

    */
    vector<ll>F1(K+1);
    F1[0]=2;F1[1]=1;       // f(2)=2 ,f(1)=1;  F1={f(n-1),f(n-2)};
    // transformation matrix KxK  
    matrix a(K+1,vector<ll>(K+1));              //a={{1,1},{1,0}}
    a[0][0]=1 ,a[0][1]=1;
    a[1][0]=1, a[1][1]=0;
    ll n,m;
    cin>>n;
    ll ans=0;
   if(n==1){
        cout<<1<<endl;
       return ;
    }
    n-=2;
    a=powr(a,n);
    for(int i=0;i<K;i++){
        ans+=(a[0][i]*F1[i])%mod;
    }
    cout<<ans;
    

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

