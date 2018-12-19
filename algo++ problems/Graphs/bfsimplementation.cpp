#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<limits>
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
    void printAdjList()
    {
        for(auto data=l.begin();data!=l.end();data++)
        {
            T current=data->first;
            cout<<current<<"-> ";
            for(auto vertex=l[current].begin();vertex!=l[current].end();vertex++)
            {
                cout<<*vertex<<", ";
            }
            cout<<endl;
        }
    }
    void bfs(T src)
    {
        queue<T> q;
        unordered_map<T,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T cur=q.front();
            cout<<cur<<" ";
            q.pop();
            for(auto vertex=l[cur].begin();vertex!=l[cur].end();vertex++)
            {
                if(!visited[*vertex])
                {
                    q.push(*vertex);
                    visited[*vertex]=true;
                }
            }
        }
        cout<<endl;
    }
    void bfsTopologicalsort()
    {
        queue<T> q;
        unordered_map<T,int> indegree;
        for(auto i:l)
        {
            T node=i.first;
            indegree[node]=0;
        }
        for(auto data=l.begin();data!=l.end();data++)
        {
            T current=data->first;
            for(auto vertex=l[current].begin();vertex!=l[current].end();vertex++)
            {
                indegree[*vertex]++;
            }
        }
        //Find out all the nodes with 0 indegree
        for(auto i:l)
        {
            T node=i.first;
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }
        while(!q.empty())
        {
            T cur=q.front();
            cout<<cur<<"->";
            q.pop();
            for(auto vertex=l[cur].begin();vertex!=l[cur].end();vertex++)
            {
                indegree[*vertex]--;
                if(indegree[*vertex]==0)
                {
                    q.push(*vertex);
                }
            }
        }
        cout<<endl;
    }
    void shortest_path(T src)
    {
        queue<T> q;
        unordered_map<T,int> visited;
        unordered_map<T,T> parent;
        q.push(src);
        for(auto it=l.begin();it!=l.end();it++)
        {
            T cur =it->first;
            visited[cur]=INT_MAX;
        }
        visited[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T cur=q.front();
            q.pop();
            for(auto vertex=l[cur].begin();vertex!=l[cur].end();vertex++)
            {
                if(visited[*vertex]==INT_MAX)
                {
                    q.push(*vertex);
                    visited[*vertex]=visited[cur]+1;
                    parent[*vertex]=cur;
                }
            }
        }
        for(auto it=l.begin();it!=l.end();it++)
        {
            T cur =it->first;
            cout<<"Distance of "<<cur<<" from "<<src<<" is:"<<visited[cur]<<" and it is child of:"<<parent[cur]<<endl;
        }
    }
    void dfsHelper(T node,unordered_map<T,bool> &visited,list<T> &ordering)
    {
        visited[node]=true;
        //cout<<node<<" ";//cur node visit hogya
        for(T neighbour:l[node])//baki ke connected components visit krne ke liye
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void dfs(T src)
    {
        unordered_map<T,bool> visited;
        list<T> ordering;
        int comp=1;
        dfsHelper(src,visited,ordering);
        cout<<endl;
        for(auto data:l)
        {
            T i=data.first;
            if(!visited[i])
            {
                dfsHelper(i,visited,ordering);
                cout<<endl;
                comp++;
            }
        }
        cout<<"No. of components="<<comp;
    }
    void dfsTopologicalsort()
    {
        unordered_map<T,bool> visited;
        list<T> ordering;
        for(auto data:l)
        {
            T i=data.first;
            if(!visited[i])
            {
                dfsHelper(i,visited,ordering);
            }
        }
//        for(auto it=ordering.begin();it!=ordering.end();it++)
//            cout<<*it<<" ";
        for(T element:ordering)
        {
            cout<<element<<"->";
        }
    }
    void cycledetection(T src)
    {
        unordered_map<T,bool> visited;
        unordered_map<T,T> parent;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        parent[src]=src;
        while(!q.empty())
        {
            T cur=q.front();
            //cout<<cur;
            q.pop();
            for(auto neighbour:l[cur])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour]=cur;
                }
                else if(parent[cur]!=neighbour&&visited[neighbour])
                {
                    cout<<"Cycle exists"<<endl;
                    return ;
                }
            }
        }
        cout<<"Cycle doesnt exists"<<endl;
        cout<<endl;
    }
};
int main()
{
    Graph<int> a;
    a.addEdge(0,1);
    a.addEdge(0,3);
    a.addEdge(1,2);
    a.addEdge(3,2);
    a.addEdge(3,4);
    //a.bfsTopologicalsort();
    a.cycledetection(1);
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
    g.bfs("English");
    g.cycledetection("English");
    return 0;

}

