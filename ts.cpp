#include<bits/stdc++.h>
using namespace std;
int v=9;
void addege(vector<int>adj[],int u,int v)
{adj[u].push_back(v);
}
stack<int>s;

void dfsutil(vector<int>adj[],bool vis[],int k)
{vis[k]=true;

	vector<int> :: iterator it;
	for(it=adj[k].begin();it!=adj[k].end();it++)
	{if(!vis[*it])
		dfsutil(adj,vis,*it);

	}
	s.push(k);

}
int  bfs(vector<int >adj[],int s,int d)
{queue<int>q;
	int cnt=0;
	q.push(s);
	while(!q.empty())
	{int size=q.size();
		while(size--)
	    {int curr=q.front();
		q.pop();
		vector<int> :: iterator it;
		for(it=adj[curr].begin();it!=adj[curr].end();it++)
		{if(*it==d)
         return cnt;
		else q.push(*it);

		}
     	}
     	//cout<<cnt<<"cnt"<<endl;
     	cnt++;
     }

}

void dfs(vector<int>adj[],int s)
{bool vis[v];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<v;i++)
	{if(!vis[i])
		dfsutil(adj,vis,i);

	}

}


int main()
{
	vector<int>adj[v];
	int level[v];
addege(adj,0,1);
addege(adj,0,7);
addege(adj,1,7);
addege(adj,1,2);
addege(adj,2,3);
addege(adj,2,5);
addege(adj,2,8);addege(adj,3,4);addege(adj,3,5);addege(adj,4,5);addege(adj,5,6);addege(adj,6,7);addege(adj,7,8);
dfs(adj,0);

for(int i=1;i<v;i++)
cout<<bfs(adj,0,i)+1<<endl;
/*while(!s.empty())
{
	cout<<s.top()<<" ";
s.pop();
}
*/
return 0;


}
