#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<queue>
#define hashmap unordered_map<T,vector<T>>
using namespace std;
template<typename T>
class Graph
{
    int V;
    hashmap l;
public:
    Graph(int v=0)
    {
        V=v;
    }
    void addEdge(T u,T v,bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
        else
        {
            l[v];//this inserts the key of the city where we go
        }
        V=l.size();
    }
    void printAdjList()
    {
        for(auto i=l.begin();i!=l.end();i++)
        {
            T current=i->first;
            cout<<current<<"->";
            for(int j=0;j<l[current].size();j++)
            {
                cout<<l[current][j]<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(T src)
    {
        unordered_map<T,bool> visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T f=q.front();
            cout<<q.front()<<endl;
            q.pop();
            for(int i=0;i<l[f].size();i++)
            {
                if(!visited[l[f][i]])
                {
                    q.push(l[f][i]);
                    visited[l[f][i]]=true;
                }
            }
        }
    }
    void shortest_path(T src,T dest)
    {
        unordered_map<T,bool> visited;
        unordered_map<T,int> dist;
        for(auto it=l.begin();it!=l.end();it++)
            dist[it->first]=INT_MAX;
        unordered_map<T,T> parent;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        dist[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T f=q.front();
            //cout<<q.front()<<"->";
            q.pop();
            for(int i=0;i<l[f].size();i++)
            {
                if(!visited[l[f][i]])
                {
                    dist[l[f][i]]=dist[f]+1;
                    q.push(l[f][i]);
                    visited[l[f][i]]=true;
                    parent[l[f][i]]=f;
                    if(l[f][i]==dest)
                    {
                        T temp;
                        temp=dest;
                        while(temp!=src)
                        {
                            cout<<temp<<" ";
                            temp=parent[temp];
                        }
                        cout<<src<<endl;
                        cout<<"Shortest path between "<<src<<" & "<<dest<<":"<<dist[l[f][i]]<<endl;
                        return;
                    }
                }
            }
        }
    }
};
int main()
{
    Graph<int> q;
    int board[50];
    for(int i=0;i<=36;i++)
        board[i]=0;
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
    for(int u=0;u<36;u++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int v=u+dice+board[u+dice];
            if(v<=36)
            {
                q.addEdge(u,v,false);
            }
        }
    }
    q.printAdjList();
    q.shortest_path(0,36);
    return 0;
}

