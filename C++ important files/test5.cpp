#include<iostream>
using namespace std;
int main()
{
	int n;
	string s[100];
	cin>>n;
//	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i].size()>10){
			cout<<s[i][0]<<s[i].size()-2<<size[i][s[i].size()-1]<<endl;
		}
		else {
			cout<< s[i]<<endl;
		}
	}
		return 0;
  }
