#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<class T>
class Graph
{
    unordered_map<T,list<T>> l;
public:
    Graph()
    {
    }
    void addEdge(T u,T v,bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }
    bool isCycleHelper(T vertex,unordered_map<T,bool> &visited,unordered_map<T,bool> &instack)
    {
        visited[vertex]=true;
        instack[vertex]=true;
        for(auto neighbour:l[vertex])
        {
            //The lines commented works in a different way
            //but check for the cycle correctly.
//            if(!visited[neighbour])
//            {
//                isCycleHelper(neighbour,visited,instack);
//            }
//            else if(instack[neighbour])
//            {
//                return true;
//            }
            if(!visited[neighbour]&&isCycleHelper(neighbour,visited,instack)||instack[neighbour])
                return true;
        }
        instack[vertex]=false;
        return false;
    }
    void isCycle()
    {
        unordered_map<T,bool> visited;
        unordered_map<T,bool> instack;
        for(auto data:l)
        {
            T vertex=data.first;
            visited[vertex]=false;
            instack[vertex]=false;
        }
        for(auto data:l)
        {
            T vertex=data.first;
//            cout<<vertex<<" ";
            if(isCycleHelper(vertex,visited,instack))
            {
                cout<<"Cycle is there"<<endl;
                return;
            }
        }
        cout<<"Cycle isn't there"<<endl;
    }
};
int main()
{
    Graph<int> a;
    a.addEdge(0,1,false);
    a.addEdge(0,2,false);
    a.addEdge(2,3,false);
    a.addEdge(2,4,false);
    a.addEdge(4,5,false);
    a.addEdge(1,5,false);
    a.addEdge(3,0,false);
    a.isCycle();
    Graph<string> g;
    g.addEdge("English","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("Web Dev","English",false);
    g.isCycle();
    return 0;

}

