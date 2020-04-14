#include<bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);

#define ull unsigned long long
#define d1(x) cout<<#x<<" "<<x<<endl;
#define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define d2i(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;

#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define all(v) v.begin(),v.end()
#define  mat vector<vector<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N=1e5;
vll adj[N];
ll in[N],out[N];
void euler(int from,stack<int >&eu){
    while(out[from]>0){
    int to=adj[from][out[from]-1];
    out[from]--;
    euler(to,eu);
    }
    eu.push(from);
}
int source(int v){
    int ans=1;
    for(int i=1;i<=v;i++){
        d1(ans)
        if(out[i]-in[i]==1){
            cout<<"ret\n";
        return i;
        }
        if(out[i]>0)
         ans=i;
    }
    
    return ans;
}

bool exist(int v){
    int s=0,e=0;
    for(int i=1;i<=v;i++){
        //d2(in[i],out[i])
        if(in[i]-out[i]==1)
        e++;
        if(out[i]-in[i]==1)
        s++;
        if(abs(in[i]-out[i])>1)
        return false;
    }
    return (s==1 && e==1) || (s==0 && e==0);
}

int main(){
    ll V, e;
    cin>>V>>e;
    ll u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    bool ok=exist(V);
    if(!ok){
        cout<<"Euler path or cicuit does not exist\n";
        return 0;
    }
    stack<int>eu;
    euler(source(V),eu);

    while(!eu.empty()){
        cout<<eu.top()<<" ";
        eu.pop();
    }

    return 0;    

}