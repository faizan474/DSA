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
vll  adj[100005];
ll in[100005],out[100005];
bool  vis[100005];
const int N = 1e5+5;
const int LG = 20;
int P[N][LG];
ll lvl[N];
void dfs(ll u){
    vis[u]=true;
    for(ll v:adj[u]){
    if(vis[v])continue;
    P[v][0]=u;
    lvl[v]=lvl[u]+1;
    dfs(v);
    }

}
ll LCA(ll u,ll v){
if(lvl[u]<lvl[v])swap(u,v);
ll lg;
for( lg=0;1<<lg<=lvl[u];lg++);
lg--;
for(int i=lg;i>=0;i--){
    if(lvl[u]-(1<<i)>=lvl[v])
      u=P[u][i];
}
if(u==v)
return u;
for(int i=lg;i>=0;i--){
    if(P[u][i]!=-1 && P[u][i]!=P[v][i])
    u=P[u][i],v=P[v][i];
}
return P[u][0];

}
ll dis(ll u,ll v){
    ll lca=LCA(u,v);
 return lvl[u]+lvl[v]-2*lvl[lca];   
}
 
void  solve(){
ll n,m,u,v;cin>>n>>m;
fr(i,1,n){cin>>u>>v,adj[u].pb(v),adj[v].pb(u);}
mems(P,-1);
lvl[0]=-1,lvl[1]=0;
dfs(1);
fr(i,1,n+1){
    fr(j,1,LG){
        if(P[i][j-1]!=-1){
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}
 
}
 
int main(){
    ll t=1;
//cin>>t;
    while(t--){
    solve();

   
    }
    return 0;
}
 