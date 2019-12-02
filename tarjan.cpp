
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
bool vis[100005];
ll   dis[100005];
ll   low[100005];
ll   par[100005];
ll  stck[100005];
stack<ll>s;
ll t=1;
void addedge(ll u,ll v){
    adj[u].pb(v);
    //adj[v].pb(u);
}
void tjan(int u){
vis[u]=true;
dis[u]=low[u]=t++;
stck[u]=1;
s.push(u);
for(ll v:adj[u]){
    if(dis[v]==-1){
      //  par[v]=u;  //  in case of undirected graph
        tjan(v);
    
        low[u]=min(low[v],low[u]);
    }
    else if(stck[v]==1){ //&& par[u]!=v){   //for undirected graph add && par[u]!=v
        low[u]=min(low[u],dis[v]);
    }
}

if(low[u]==dis[u]){
    static int cnt=0;
    cnt++;
    cout<<cnt<<" "<<"scc\n";
     while(u!=s.top())
         {   stck[s.top()]=0;
             cout<<s.top()<<" ";
             s.pop();
         }
         cout<<s.top()<<" ";stck[s.top()]=0;
         s.pop();
         cout<<endl;
}

}



void solve(){
ll v,e;
fr(i,0,100005)
adj[i].clear();
mems(vis,false);
mems(dis,-1);
mems(stck,-1);
cin>>v>>e;
  ll u,vv;
fr(i,0,e)cin>>u>>vv,addedge(u,vv);
fr(i,1,v){
    if(!vis[i])
    tjan(i);
}


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

/*

5
5
2 1 
3 2
1 3
1 4
4 5


8
14
1 2
2 4 2 3 2 5
3 7 
4 1 4 3
5 6 5 7
6 5 6 8
7 3
8 6 8 7

*/