#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand(time(NULL));
    cout<<"The no is:"<<rand()%100;
    return 0;
}
