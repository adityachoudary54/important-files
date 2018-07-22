#include<iostream>
#include"hash.h"
using namespace std;
int main()
{
    hashtable<int> h;
    h.insert("mango",100);
    h["papaya"]=50;//humein node ke value vala dubba mil gya jismein value change krdi
    cout<<h["papaya"]<<endl;
    h.print();
    return 0;
}
