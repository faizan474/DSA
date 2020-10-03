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

int solve(string &str){
    string str1;
    fr(i,0,str.size()){
        str1.push_back('#');
        str1.push_back(str[i]);
    }
    str1.push_back('#');

    ll n=str1.size();
    fr(i,0,n)
    cout<<str1[i]<<" ";
    cout<<endl;
                                  //abababa
                                 //# a # b # a # b # a # b # a # 
                                 //0 1 0 3 0 5 0 7 0 5 0 3 0 1 0 

    ll len[str1.size()+1];
    mems(len,0);
    // c is the center of curr palindrome with the  boundary as r
    ll c=0,r=0;
    // here i is rightpointer who is trying to find new center whose length is greater than curr palindrome
    for(ll i=0;i<n;i++){           
        // mirr is leftpointer mirrored to i about current center 
        ll mirr=2*c-i;              // i-c=c-mirr=> mirr=2*c-i
        if(i<r)
            len[i]=min(r-i,len[mirr]);
        // this is tying to expand on both direction from previously calculated palindrome length len[i] and checking possibility beyond that  
        while((i-(1+len[i]))>=0 && (i+1+len[i])<n && str1[i+(1+len[i])]==str1[i-(1+len[i])])
            len[i]++;
        // if (palindrome centered at i expands beyond the boundaries of curr palindrome c then c is updated to i)  
        if(i+len[i]>r){
           r=i+len[i];
           c=i;
       }

    }

    fr(i,0,n)
    cout<<len[i]<<" ";
    cout<<endl;


}



int main(){
    int t;
    cin>>t;
    while(t--){
    string str;
    cin>>str;
    cout<<solve(str);
    ll c=0,r=0;

    }
    return 0;
}