#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define fr(i,l,r) for(int i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define maxN 10e5+1

void build_tree(vll v,int* tree,ll start,ll end,ll node){
    if(start==end)
    {  if(v[start]&1)
    tree[node]=maxN;
    else 
    tree[node]=start;
    return;
    }
    ll mid=(start+end)/2;
    build_tree(v,tree,start,mid,2*node);
    build_tree(v,tree,mid+1,end,2*node+1);
     tree[node]=min(tree[2*node],tree[2*node+1]);
 
//Fast Reader : 
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
 
//_____________________________
 
}

int query(int* tree,int start,int end ,int l ,int r,int node){
  // no overlap
    if(r<start || end<l)
    return 1000001;
    else if(start>=l && end<=r)
    return tree[node];
    else{
        ll mid=(start+end)/2;
        ll lft=query(tree,start,mid,l,r,2*node);
        ll rgt=query(tree,mid+1,end,l,r,2*node+1);
        ll mx=min(lft,rgt);
        return mx;

            }
}

int  main(){
   ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    ll n;
    cin>>n;
    vll v;
    fr(i,0,n){
   ll inp;
   cin>>inp;
   v.pb(inp);
    }
    int tree[n<<1];
    build_tree(v,tree,0,n-1,1);
ll q;
//cout<<"enter queries ";
cin>>q;
while(q--){
    ll l,r;
    cin>>l>>r;
    cout<<query(tree,0,n-1,l-1,r-1,1)<<'\n';
}
return 0;
}






/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define fr(i,l,r) for(int i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define maxN 10e5+1
vll v;
void seive(){
    bool prime[1000000];
    mems(prime,false);
    for(ll i=2;i*i<1000000;i++){
        if(!prime[i]){
            for(ll j=2*i;j<1000000;j+=i){
                prime[j]=true;
            }
        }
    }
    for(ll i=2;i<1000000;i++){
        if(prime[i]==false)
            v.pb(i);
    }
}
void build(vll v,int* tree,int l ,int r,int node){
    if(l==r){
        tree[node]=v[l];
        return;
}
    ll mid = (r+l)/2;
    build(v,tree,l,mid,2*node);
    build(v,tree,mid+1,r,2*node+1);
    tree[node]=max(tree[2*node+1],max(tree[2*node],tree[2*node]^tree[2*node+1]));
}
int query(int* tree,int start,int end ,int l ,int r,int node){
  // no overlap
    if(r<start || end<l)
    return 0;
    else if(start>=l && end<=r)
    return tree[node];
    else{
        ll mid=(start+end)/2;
        ll lft=query(tree,start,mid,l,r,2*node);
        ll rgt=query(tree,mid+1,end,l,r,2*node+1);
        ll mx=max(lft,max(rgt,lft^rgt));
        return mx;

            }
}

int main() {
     ll n;
    cin>>n;
    seive();
    int tree[n<<1];
    build(v,tree,0,n-1,1);
ll q;
//cout<<"enter queries ";
cin>>q;
while(q--){
    ll l,r;
    cin>>l>>r;
    cout<<query(tree,0,n-1,l-1,r-1,1)<<'\n';
}
return 0;
}
*/