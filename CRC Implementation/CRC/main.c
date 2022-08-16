#include <stdio.h>
#include <stdlib.h>
int main()
{
    int D[20],P[20],i,n,zeros,ap[20],j,k,crc[20],rem[20],tr[20],flag=0,count1=0,count2=0,count3=0,t,m,tr1[20],flag1=0;
    float BER=0.001,n1,p1,p2,p3;
    printf("Give me the number of bits: ");
    scanf("%d",&n);
    printf("Give me the number of bits of P: ");
    scanf("%d",&m);
    printf("The binary number P is:");
    for(i=0;i<m;i++)
     {
        scanf("%d",&P[i]);
     }
    printf("\n");

    for(t=1;t<10000001;t++)
    {
      printf("The given binary number is: ");

      for(i=0;i<n;i++)
      {
        D[i]=rand()%2;
      }
     /* for(i=0;i<n;i++)
        scanf("%d",&D[i]);
        */


    //print the message
      for(i=0;i<10;i++)
      {
       printf("%d",D[i]);

      }
      printf("\n");



    //append P-1 zeros
     zeros=m-1;
     for(i=n;i<n+zeros;i++)
     {
        D[i]=0;
     }
     for(i=0;i<n+zeros;i++)
     {
        ap[i]=D[i];
     }

    //print append message with P-1 zeros
     printf("The appended message is: ");
     for(i=0;i<n+zeros;i++)
     {
        printf("%d",ap[i]);
     }
     printf("\n");

    //Division
     for(i=0;i<n;i++)
     {
         j=0;
         k=i;
         if(ap[k]>=P[j])
         {
             for(j=0,k=i;j<m;j++,k++)
             {
                 if((ap[k]==0 && P[j]==0) || (ap[k]==1 && P[j]==1))
                    ap[k]=0;
                 else
                    ap[k]=1;

             }
         }
     }

     //Create the Crc array which have the reminder from the division
     for(i=0,j=n;i<zeros;i++,j++)
        crc[i]=ap[j];

    //print the CRC reminder
     printf("CRC:");
     for(i=0;i<zeros;i++)
        printf("%d",crc[i]);
    printf("\n");

    //The transmitted message
    for(i=0;i<n;i++)
    {
        tr[i]=D[i];
    }
    for(i=n,j=0;i<n+zeros;i++,j++)
    {
        tr[i]=crc[j];
    }
    printf("The transmitted message:");
    for(i=0;i<n+zeros;i++)
        printf("%d",tr[i]);
    printf("\n");

    //copy the array of transmitted message
    for(i=0;i<n+zeros;i++)
        tr1[i]=tr[i];


    //Possible error with BER
    for(i=0;i<n+zeros;i++)
    {
         n1=rand()/((double) RAND_MAX);

         printf("%f\n",n1);
         //printf("\n");
         if((n1<0.001) && (tr[i]==0))
         {
             tr[i]=1;
         }
         else if((n1<0.001) && (tr[i]==1))
         {
             tr[i]=0;
         }
    }

    //print the new transmitted message
    printf("The transmitted message after the BER:");
    for(i=0;i<n+zeros;i++)
        printf("%d",tr[i]);
    printf("\n");
    flag1=0;

    //count the messages which have error from BER
    for(i=0;i<n+zeros;i++)
    {
        if(tr[i]!=tr1[i])
        {
            flag1=1;
        }

    }
    //printf("%d\n",count1);*/

    //Check with CRC if the transmitted message has error
    //I use again the division method
    //Division
     for(i=0;i<n;i++)
     {
         j=0;
         k=i;
         if(tr[k]>=P[j])
         {
             for(j=0,k=i;j<m;j++,k++)
             {
                 if((tr[k]==0 && P[j]==0) || (tr[k]==1 && P[j]==1))
                    tr[k]=0;
                 else
                    tr[k]=1;

             }
         }
     }

     //Create the array reminder to store the reminder
     for(i=n,j=0;i<n+zeros;i++,j++)
     {
         rem[j]=tr[i];
     }
     printf("The reminder:");
     for(i=0;i<zeros;i++)
        printf("%d",rem[i]);
    flag=0;


     //Check if the message has error with CRC method

     for(i=0;i<zeros;i++)
     {
         if(rem[i]!=0)
            flag=1;
     }
     printf("\n");

     //count the messages has got error according to BER
     if(flag1==0)
        printf("The receiver message has not error according to BER\n");
     else
     {
         printf("The message has error according to BER\n");
         count1++;
     }

     //Count messages which have error according to CRC
     if(flag==0)
            printf("The receiver message has not error according to CRC\n");
     else
     {
         printf("The receiver message has bit error according to CRC\n");
         count2++;
     }

     //count the messages which have error according to BER but they do not recognize according to CRC
     if((flag1==1) && (flag==0))
     {
         count3++;
     }

     printf("\n");

    }
     printf("%d\n",count1);
     printf("%d\n",count2);
     printf("%d\n",count3);
     printf("\n");
     p1=(float)count1/10000000*100.0;
     printf("The percent of messages received with error is %0.2f%%\n",p1);
     p2=(float)count2/10000000*100.0;
     printf("The percent of messages which has error according to crc is %0.2f%%\n",p2);

     //Calculate the messages which received with error but they do not recognized from CRC
     p3=(float)count3/10000000*100.0;
     printf("The percent of messages which received with error but they do not recognized from crc is:%0.2f%%\n",p3);





    return 0;
}
