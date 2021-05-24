#include<stdio.h>
int main()
{
   int n,i,j;
   printf("\nEnter no. of processes: ");
   scanf("%d",&n);
   int at[n],bt[n];
   for(i=0;i<n;i++)
   {
       printf("\nEnter arrival and burst time of process T%d :",i+1);
       scanf("%d%d",&at[i],&bt[i]);
   }
   int ct[n];
   ct[0]=at[0]+bt[0];
   for(j=1;j<n;j++)
   {
       if(ct[j-1]<at[j])
       {
           ct[j]=at[j]+bt[j];
       }
       else
       {
           ct[j]=ct[j-1]+bt[j];
       }
   }
   printf("\nTotal time: %d",ct[n-1]);
   for(i=0;i<n;i++)
   {
       printf("\nTAT for process %d is %d: ",i+1,ct[i]-at[i]);
   }
   printf("\nWT for process 1: 0");
   int wt;
   for(i=1;i<n;i++)
   {
       wt=at[i]-ct[i-1];
       if(wt<=0)
       {
           printf("\nWT for process %d: %d",i+1,wt);
           printf("\nCPU is idle between process %d and %d",i,i+1);
       }
       else
       {
           printf("\nWT for process %d: 0",i+1);
       }
   }
   printf("\nNo. of context switch: %d\n",n-1);
}