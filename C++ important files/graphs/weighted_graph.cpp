#include<iostream>
#include<list>
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
};
int main()
{
	Graph g(5);
	//cout<<"hello";
	//g.addEdge(0,1,2);
	g.addEdge(1,2,4);
	g.addEdge(2,3,2);
	g.addEdge(3,4,3);
	//
	g.printAdjList();
}
