
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

struct Node{
    bool EOW;
    Node *child[26];
};

Node* getnode(){
    Node *newnode=new Node;
    newnode->EOW=false;
    for(int i=0;i<26;i++)
    newnode->child[i]=NULL;

    return newnode;

}
void insert(Node *root,string &str){
    Node *ptr=root;
    for(int i=0;i<str.size();i++){
        int idx=str[i]-'a';
        if(ptr->child[idx]==NULL){
            ptr->child[idx]=getnode();
        }
        ptr=ptr->child[idx];
    }
    ptr->EOW=true;
   
}
bool search(Node *root,string &str){
    Node *ptr=root;
    for(int i=0;i<str.size();i++){
        int idx=str[i]-'a';
        if(ptr->child[idx]==NULL)
        return false ;
        ptr=ptr->child[idx];
    }
    if(ptr->EOW)
    return true;
    else return false;
}

int main(){
    int tt;cin>>tt;
    while(tt--){
        Node *root=getnode();
        ll n;
        cin>>n;
        string str;
        for(int i=0;i<n;i++){
            cin>>str;
            insert(root,str);
        }
        cin>>str;
        cout<<search(root,str)<<endl;
    }
    return 0;
}