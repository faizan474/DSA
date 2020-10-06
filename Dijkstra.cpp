#include<bits/stdc++.h>
using namespace std;
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long int ll;
const ll N=1e5;
vector<pair<ll,ll>>g[N];
bool vis[N];
ll dis[N];
ll n;
void dijkstra(ll src){
    fill(dis,dis+n+1,1e9);
	memset(vis,false,sizeof(vis));
	
    dis[src]=0;
    multiset<pair<ll,ll>>q;
    q.insert({0,src});

    while(!q.empty()){
    pair<ll,ll>tp=*q.begin();
    q.erase(q.begin());
    ll u=tp.second,w=tp.first;
    if(vis[u])
    continue;
    vis[u]=true;
    for(auto it:g[u]){
        ll v=it.second,wei=it.first;
        
        if(dis[v]>dis[u]+wei){
            dis[v]=dis[u]+wei;
        q.insert({dis[u]+wei,v});
        }
    }
        
    }

    
}

int main(){
	boost;
	ll m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		//g[v].push_back({w,u});
	}

	dijkstra(1);
	for(int i=2;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
    
}