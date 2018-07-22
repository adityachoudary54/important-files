#include<iostream>
using namespace std;
int main()
{
    char c;
    cin.get(c);// first element is taken and the rest elements remain in the input stream.it stops taking input after the enter key
    while(c!='\n')
    {
        cout.put(c);
        cin.get(c);
    }
    return 0;
}
