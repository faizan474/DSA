#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

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


// modified above things
int main()
{ long long int n,m,k;
  cin>>m>>n;
  k=n;
  int size[1000],a[1000];
  intialize(a,size,m);
  while(k--)
  {int c,b,temp[1000];
    cin>>c>>b;
    unyn(a,size,c,b);
    for(int i=1,k=0;i<=m;i++,k++)
    {
      temp[k]=size[i];
    }
    int i=0,idx=0;
    stack<int>s;
    sort(temp,temp+n,greater<int>());
    //for(int i=0;i<m;i++)
    //{cout<<temp[i]<<endl;
    //}
    while(i<=n)
    {//cout<<"idx"<<temp[idx]<<" ";
     s.push(temp[idx]);
    i+=temp[idx++];

    }
    while(!s.empty())
    {  cout<<s.top()<<" ";
       s.pop();}

cout<<endl;
  }


	return 0;


}
