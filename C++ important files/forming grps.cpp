#include<iostream>
#include<list>
#include<set>
#include<queue>
using namespace std;
class Graph
{
	int V;
	list<pair<int,int>> *l;
public:
	Graph(int v)
	{
		V=v;
		l=new list< pair<int,int> >[V];
	}
	void addEdge(int u,int v,int w,bool bidir=true)
	{
		l[u].push_back(make_pair(v,w));
		if(bidir)
        	l[v].push_back(make_pair(u,w));
	}
	void printAdjList()
	{
		for(int it=0;it<V;it++)
		{
			cout<<it<<"->";
			for(auto neighbour=l[it].begin();neighbour!=l[it].end();neighbour++)
			{
				cout<<neighbour->first<<","<<neighbour->second<<"  ";
			}
			cout<<endl;
		}
	}

	void dijkstra(int src)
	{
		int *dist=new int[V];
		for(int i=0;i<V;i++)
		{
			dist[i]=INT_MAX;//initially infinite distance for each node
		}
		set<pair<int,int>> s;
		dist[src]=0;
		s.insert(make_pair(0,src));//for the source node distance will be 0
		while(!s.empty()) //set ke thorugh dist[] initialise hojayega
		{
			auto it=s.begin();
			int parent=it->second;
			int parentDist=it->first;
			s.erase(it);
			for(auto j=l[parent].begin();j!=l[parent].end();j++)
			{
				if(parentDist+j->second<dist[j->first])
				{
					int oldDist=dist[j->first];
					auto f=s.find(make_pair(oldDist,j->first));//This is done when a given node recurs in the path it is removed and then updated.
					if(f!=s.end())
					{
						s.erase(f);
					}
					dist[j->first]=parentDist+j->second;
					s.insert(make_pair(dist[j->first],j->first));
				}
			}
		}
		for(int i=0;i<V;i++)
		{
			cout<<i<<" "<<dist[i]<<endl;
		}
	}

	void topologicalSort()
	{
		int *indegree=new int[V]{0};
		//iterating over all edges
		for(int i=0;i<V;i++)
		{
			for(auto it=l[i].begin();it!=l[i].end();it++)
			{
				indegree[it->first]++;
			}
		}
		queue<int> q;
		for(int i=0;i<V;i++)
		{
			if(indegree[i]==0)
				q.push(i);
		}

		while(!q.empty())
		{
			int f=q.front();
			cout<<f<<" ";
			q.pop();
			for(auto it=l[f].begin();it!=l[f].end();it++)
			{
				indegree[it->first]--;
				if(indegree[it->first]==0)
					q.push(it->first);
			}
		}
	}

	int find(int i,int *parent)
	{
		if(parent[i]==i)
		{
			return i;
		}
		return find(parent[i],parent);
	}
	void uni(int x,int y,int *parent)
	{
		int xp=find(x,parent);
		int yp=find(y,parent);
		parent[yp]=xp;
	}
	bool isCyclic()
	{
		int *parent = new int [V];
		for(int i=0;i<V;i++)
		{
			parent[i]=i;
		}
		//Cycle ka logic
		for(int i=0;i<V;i++)
		{
			for(auto j=l[i].begin();j!=l[i].end();j++)
			{
				int x=i;
				int y=j->first;
                //cout<<endl;
				int xParent=find(x,parent);
				int yParent=find(y,parent);
				if(xParent==yParent)
				{
					for(int i=0;i<V;i++)
				{
					cout<<parent[i]<<" ";
				}
				cout<<endl;
					return true;
				}
				uni(x,y,parent);
			}
		}
		return false;
	}
};
int main()
{
    int n,a[5000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
	Graph g(n);
	for(int i=0;i<n;i++)
    {
        g.addEdge(i,a[i]-1,1);
    }
	g.printAdjList();
	if(g.isCyclic())
		cout<<"YES";
	else
		cout<<"NO";
}
