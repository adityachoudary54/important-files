#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
class Fruit
{
public:
    string name;
    string city;
    int price;
    string country;
    Fruit()
    {
    }
    Fruit(string n,string c,int p)
    {
        name=n;
        city=c;
        price=p;
        country="INDIA";
    }
    void print()
    {
        cout<<"F R U I T"<<endl;
        cout<<name<<endl;
        cout<<country<<endl;
        cout<<price<<endl;
    }
};
ostream& operator<<(ostream &os,Fruit f)
{
    f.print();
}
int main()
{
    unordered_map <string,Fruit> ump;
    Fruit f1("Guava","Goa",100);
    Fruit f2("Mango","MP",200);
    Fruit f3("Pineapple","Punjab",60);
    Fruit f4("Grapes","Mysore",300);
    ump.insert(make_pair(f1.city,f1));//insert fn accepts a pair
    ump.insert(make_pair(f2.city,f2));
    ump.insert(make_pair(f3.city,f3));
    //.ump.insert(make_pair(f4.city,f4));
    ump[f4.city]=f4;//more effective way to insert in a map
    ump[f4.city]=f3;
    string city;
    cin>>city;
    auto fs=ump.find(city);
    if(fs!=ump.end())
    {
        cout<<fs->first<<endl;
        cout<<fs->second;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    for(auto it=ump.begin();it!=ump.end();it++)
    {
        cout<<it->first<<endl;
        cout<<it->second<<endl;
    }
    return 0;
}
