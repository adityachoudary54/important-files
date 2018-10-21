#include <iostream>
#include <conio.h>
//#define MAX 10
using namespace std;
class stack
{
    int arr[10];
    int top;
public:
    stack()
    {
        top = -1;
    }
    void push(int);
    int pop();
};

int stack :: pop()
{
    if(top == -1){
        cout << "stack is empty nothing to pop\n";
        return -1;
    }
    int temp = arr[top];
    top--;
    return temp;
}
void stack :: push(int k)
{
    if(top == 9){
        cout << "stack is full...cant push\n";
        return;
    }
    top = top + 1;
    arr[top] = k;
    cout <<"is pushed at" << top <<" and element pushed is:"<<k<< "\n";
}

int main()
{

    return 0;
}
