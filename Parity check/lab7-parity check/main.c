#include <stdio.h>
#include <stdlib.h>
int error(int a[100],int n)
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
            count++;
    }
    if(count%2!=0)
        printf("Bit error\n");
    else
        printf("The message is correct,no bit error\n");
    printf("\n");
}
int main()
{
    int a[100],i,n,count=0,pos,a1[100],k=0;

    printf("Give me the number of bits:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        if(a[i]==1)
            count++;
    }

    //rise the size of array
    n++;
    pos=n;
    for (i = n - 1; i >= pos- 1;i--)
        a[i+1] = a[i];
    if(count%2==0)
    {
         a[pos-1] =0;
    }
    else
        a[pos-1]=1;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    //Second exercise
    //copy the elements of the array with 15bits in a new array
    for(i=0;i<n;i++)
    {
        a1[i]=a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==a1[i])
            k++;
    }
    if(k==n)
        printf("The message do not have bit error\n");
    printf("\n");

    a1[5]=0;
    //call the function which check if the message has bit error
    error(a1,n);

    a1[11]=1;
    error(a1,n);



    return 0;
}
