#include<iostream>
#include"hash.h"
using namespace std;
int main()
{
    hashtable<int> h;
    h.insert("Mango",100);
    h.insert("Banana",20);
    h.insert("Apple",150);
    h.insert("Apricot",190);
    h.insert("Pineapple",90);
    h.print();

    string fruit;
    cin>>fruit;
    //h.remove(fruit);
   // h.print();
    if(h.search(fruit)!=NULL)
        cout<<"Fruit costs:"<<*h.search(fruit)<<endl;
    else
        cout<<"Nahi mila";

    hashtable<pair<string,int>> hasi;
    hasi.insert("Mango",make_pair<string,int>("Delhi",120));
    hasi.insert("Apple",make_pair<string,int>("Himachal",140));
    hasi.insert("papaya",make_pair<string,int>("world",120));
    hasi.print();
    cin>>fruit;
    //h.remove(fruit);
   // h.print();
    if(hasi.search(fruit)!=NULL)
        cout<<(*hasi.search(fruit)).first<<" fruit costs:"<<hasi.search(fruit)->second<<endl;
    else
        cout<<"Nahi mila";
    return 0;
}
