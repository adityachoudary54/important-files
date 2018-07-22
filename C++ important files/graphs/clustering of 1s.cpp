#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;
//adj list implementation for integer nodes

void dfsHelper(int a[][5],pair<int,int> p,vector<pair<int,int> > &v,unordered_map<int,bool> &visited)
{
	visited[5*p.first+p.second]=true;
	//cout<<p.first<<" "<<p.second<<endl;
	v.push_back(p);
	if(p.second>0&&a[p.first][p.second-1]==1&&!visited[5*p.first+p.second-1])
		dfsHelper(a,make_pair(p.first,p.second-1),v,visited);
	if(p.first>0&&a[p.first-1][p.second]==1&&!visited[5*(p.first-1)+p.second])
		dfsHelper(a,make_pair(p.first-1,p.second),v,visited);
	if(p.second<4&&a[p.first][p.second+1]==1&&!visited[5*p.first+p.second+1])
		dfsHelper(a,make_pair(p.first,p.second+1),v,visited);
	if(p.first<3&&a[p.first+1][p.second]==1&&!visited[5*(p.first+1)+p.second])
		dfsHelper(a,make_pair(p.first+1,p.second),v,visited);
}

void dfs(int a[][5])
{
	unordered_map<int,bool> visited;
	vector<pair<int,int>> v;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(a[i][j]==1&&!visited[5*i+j])
			{
				dfsHelper(a,make_pair(i,j),v,visited);
				v.push_back(make_pair(3,3));
			}
		}
	}
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==make_pair(3,3))
			cout<<endl;
		else
			cout<<v[i].first<<","<<v[i].second<<"  ";
	}
}
int main()
{
	//graph g(4);
	int a[][5]={{0,1,0,0,1},
				{1,0,0,1,1},
				{0,1,1,1,1},									
				{0,0,0,0,1}};
	dfs(a);
	//g.printAdjList();
	return 0;
}
