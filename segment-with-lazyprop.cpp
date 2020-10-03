//In lazy update 
//step 1:find the total overlap
//step 2:update that overlape &&  and put updated value in lazy id 
//step 3:mark is children to lazy as to be update 
//when requied ...
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


//***************************************************************************************************************

void build_tree(vll v,int* tree,ll start,ll end,ll node){
    if(start==end)
    {tree[node]=v[start];
    return;
    }
    ll mid=(start+end)/2;
    build_tree(v,tree,start,mid,2*node);
    build_tree(v,tree,mid+1,end,2*node+1);

    tree[node]=tree[2*node]+tree[2*node+1];
}


//***************************************************************************************************************

void updatenode(int* tree,int* lazy ,int start ,int end ,int l ,int r, int node,int val){
    tree[node]+=(end-start+1)*val;
       //check for leaf node if not then mark lazy to its children
    if(start!=end){
        lazy[2*node]+=val;
        lazy[2*node+1]+=val;
    }
    // updated 
    lazy[node]=0;
}




// this is the function to update the range with val

void updaterange(int* tree,int* lazy ,int start ,int end ,int l ,int r, int node,int val){
    if(lazy[node]!=0){
        // node need to be updated  here lazy[node] value to be passed to children
        updatenode(tree,lazy,start,end,l,r,node,lazy[node]);
    }
    if(r<start || end<l)
    return;
    else if(start>=l && end<=r){
        // here value tree[val] to be updated and val to be passed to children
        //tree[node]=(r-l+1)*val;
        lazy[node]=val;
        // updatenode(tree,lazy,start,end,l,r,node,val);
    }
    else{
        ll mid =(start+end)/2;
        updaterange(tree,lazy,start,mid,l,r,2*node,val);
        updaterange(tree,lazy,mid+1,end,l,r,2*node+1,val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }


}


//******************************************************************************************

int query(int* tree,int* lazy,int start,int end ,int l ,int r,int node){
  // no overlap
    if(r<start || end<l)
    return 0;
    if(lazy[node]!=0){
     updatenode(tree,lazy,start,end,l,r,node,lazy[node]);
     }
     if(start>=l && end<=r)
    return tree[node];
    else{
        ll mid=(start+end)/2;
        return  (query(tree,lazy,start,mid,l,r,2*node)+query(tree,lazy,mid+1,end,l,r,2*node+1));
            }
}


// ye neeche ka kachra h 


int  main(){
    ll n;
    cin>>n;
    vll v;
    fr(i,0,n){
   ll inp;
   cin>>inp;
   v.pb(inp);
    }
    int tree[2*n],lazy[2*n];
    mems(lazy,0);
    build_tree(v,tree,0,n-1,1);
fr(i,1,2*n)
cout<<tree[i]<<" ";
ll q;
cout<<"enter queries ";
cin>>q;
while(q--){

    ll l,r,type,val;
    cin>>type;
    switch(type){
       case 0:  //query
                cin>>l>>r;
               cout<<query(tree,lazy,0,n-1,l,r,1)<<endl;

                fr(i,1,2*n)
                cout<<tree[i]<<" "; 
                cout<<endl;
                fr(i,1,2*n)
                cout<<lazy[i]<<" ";
                cout<<endl;
                break;
       case 1: // update
                cin>>l>>r>>val;
                updaterange(tree,lazy,0,n-1,l,r,1,val);
                fr(i,1,2*n)
                cout<<tree[i]<<" ";
                cout<<endl;
                fr(i,1,2*n)
                cout<<lazy[i]<<" ";
                cout<<endl;
                break;
    }
    /*
    cin>>l>>r;
    cout<<query(tree,lazy,0,n-1,l,r,1);
    */
}
}