#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // size=N
 const ll N=1e5;
 ll sz[N];
 ll par[N];
 void ini(){
     for(int i=0;i<N;i++)
     sz[i]=1,par[i]=i;
 }
 ll root(ll x){
     if(x==par[x])
     return x;
     return par[x]=root(par[x]);
 }
 void uni(ll x,ll y){
     x=root(x);
     y=root(y);
     if(x==y)
     return;
     if(sz[x]<sz[y])
     swap(x,y);
     sz[x]+=sz[y];
     sz[y]=0;
     par[y]=x;
 }

int main(){

  return 0;
}