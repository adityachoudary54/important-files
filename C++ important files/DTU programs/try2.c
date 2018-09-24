#include<stdio.h>
int main()
{
    int x=0,i=0;
    while(i<20)
    {
        if(i%5==0)
        {
            x+=i;
            printf("%d",x);
        }
        ++i;
    }
    printf(" = %d",x);
    return 0;
}
