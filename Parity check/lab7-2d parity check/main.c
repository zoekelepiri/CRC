#include <stdio.h>
#include <stdlib.h>
int Error(int a1[100][100],int r,int res)
{
    int count=0,i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<res;j++)
        {
            if(a1[i][j]==1 && j!=res-1)
                count++;
        }
        if(((a1[i][res-1]==1) &&(count%2==0)) || ((a1[i][res-1]==0) && (count%2==1)))
              printf("Bit error in %d row \n",i);
        count=0;
    }

    int count1=0;
    for(j=0;j<res;j++)
    {

        for(i=0;i<r;i++)
        {
            if(a1[i][j]==1 && i!=r-1)
                count1++;
        }
         if(((a1[r-1][j]==1) &&(count1%2==0)) || ((a1[r-1][j]==0) && (count1%2==1)))
              printf("Bit error in %d column \n",j);
        count1=0;
    }

    printf("\n\n");
}
int main()
{
    int a[100][100],i,k=0,n,r,res,j,count=0,count1=0,a1[100][100];
    printf("Give me the number of bits:");
    scanf("%d",&n);
    printf("Enter the numbers of rows:");
    scanf("%d",&r);
    res=n/r;                 //to find how many bits each row will have
    for(i=0;i<r;i++)
    {
        for(j=0;j<res;j++)
            scanf("%d",&a[i][j]);

    }
    r++; //rise the rows
    res++;//rise the columns
    //add in extra column 0 or 1
    for(i=0;i<r;i++)
    {
        for(j=0;j<res;j++)
        {
            if(a[i][j]==1)
                count++;
        }
        if(count%2==0)
            a[i][res-1]=0;
        else
            a[i][res-1]=1;
        count=0;

    }
    //add in extra row 0 or 1
    for(j=0;j<res;j++)
    {
        for(i=0;i<r;i++)
        {
            if(a[i][j]==1)
               count1++;
        }
        if(count1%2==0)
            a[r-1][j]=0;
        else
            a[r-1][j]=1;
        count1=0;
    }
    printf("\n");
    //print the message with even 2-dimensional parity
    printf("The message of two dimensional parity is:");
     for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<res;j++)
            printf("%d\t",a[i][j]);

    }
    printf("\n\n");

    //second part find(if there are) bit erros
   //create a copy from our message because this message has not got bit error
   for(i=0;i<r;i++)
    {
     for(j=0;j<res;j++)
     {
         a1[i][j]=a[i][j];
     }
   }
   for(i=0;i<r;i++)
    {

        for(j=0;j<res;j++)
        {
            if(a1[i][j]==a[i][j]);
                  k++;
        }
    }
    printf("\n");
    //i)
    if(k==r*res)
        printf("The message has not got bit error\n");
    //ii)
    a1[1][2]=0;
    Error(a1,r,res);

    //iii)
    a1[1][4]=0;
    Error(a1,r,res);

    //last part of exercise
    a1[3][2]=1;
    a1[3][4]=1;
    Error(a1,r,res);
    return 0;

}
