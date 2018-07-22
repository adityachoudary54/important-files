#include<iostream>
#include<list>
using namespace std;
//adj list implementation for integer nodes
class graph
{
	int V;
	list<int> *adjList;//array of linked lists which will have address of vertices of size V
public:
	graph(int v)
	{
		V=v;
		adjList=new list<int>[V];
	}
	void addEdge(int u,int v,bool bidir=true)
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}
	void printAdjList()
	{
		/*for(int i=0;i<V;i++)
		{
			cout<<i<<"->";
			//the below loop prints all the nodes of ith linked list
			for(int node:adjList[i])//for each loop ,a new addition in c++
			{
				cout<<node<<",";
			}
			cout<<endl;
		}*/
		for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(auto it=adjList[i].begin();it!=adjList[i].end();it++)
            {
                cout<<*it<<",";
            }
            cout<<endl;
        }

	}

};
int main()
{
	graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(3,2);
	g.addEdge(0,3);
	g.printAdjList();
	return 0;
}
