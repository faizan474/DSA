#include<bits.stdc++.h>
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


void intialize(int *a,int *size,int n)   //intially all the nodes are pointing to itself
{
	for(int i=1;i<=n;i++)
	{	a[i]=i;
		size[i]=1;
	}
}

int representative(int *a,int n)   //find till the node is nit found who is pointing to itself
{
   while(a[n]!=n)
   {a[n]=a[a[n]];
   	n=a[n];
   }
   return n;
}

void unyn(int *a,int *size,int A,int B)
{
int rp_A=representative(a,A);
int rp_B=representative(a,B);
if(rp_A==rp_B)
return;
else if(size[rp_A]>=size[rp_B])
       {a[rp_B]=a[rp_A];
       size[rp_A]+=size[rp_B];
       }
else                      //B is the parent to A.So A should get assign to parent of B or B itself
	{a[rp_A]=a[rp_B];
       size[rp_B]+=size[rp_A];
    }


}

void kruskal(i)


int main(){

}