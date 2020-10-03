
#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} 



struct node{
    int h,l,w;
};



bool comp(const node &lft,const node &rgt){
    return (lft.w*lft.l)-(rgt.w*rgt.l)>0?1:0;
}



bool istrue(node &lft,node &rgt){
    if( lft.l<rgt.l && lft.w<rgt.w)
    return true;
    else return false;
    
}



int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    int idx=1;
    vector<node>v(3*n+1);
    for(int i=0;i<n;i++){
        v[idx].h=height[i];  v[idx].l=max(width[i],length[i]); v[idx].w=min(width[i],length[i]);
        idx++;
        v[idx].h=width[i];  v[idx].l=max(length[i],height[i]); v[idx].w=min(height[i],length[i]);
        idx++;
        v[idx].h=length[i];  v[idx].l=max(height[i],width[i]); v[idx].w=min(width[i],height[i]);
        idx++;
    }
    
    sort(v.begin()+1,v.end(),comp);
 //  for(int i=0;i<3*n+1;i++){
  //      cout<<v[i].h<<" "<<v[i].l<<" "<< v[i].w<<endl;
  /// }cout<<endl;
  int dp[3*n+1];
  memset(dp,0,sizeof(dp));
  dp[0]=0;
  int  ans=0;
  for(int i=1;i<3*n+1;i++){
      for(int j=i-1;j>=0;j--){
          
          if(istrue(v[i],v[j]) || j==0 ){
     //        cout<<i<<" "<<j<<endl;
       //              cout<<v[i].h<<" "<<v[i].l<<" "<< v[i].w<<endl;
        //   cout<<v[j].h<<" "<<v[j].l<<" "<< v[j].w<<endl;
        
              dp[i]=max(dp[i],dp[j]+v[i].h);
              ans=max(dp[i],ans);
          }
      }
  }
 // for(int i=0;i<3*n+1;i++)
  //cout<<dp[i]<<" ";
  //cout<<endl;
  
    return ans;
}


/*
4 6 5   4  
5 6 4   5
6 4 5   6
1 3 4   5  
1 3 2   7
3 1 4   7
2 3 1   8
4 1 3   10
3 1 2   9
0 0 0
*/