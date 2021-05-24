#include<stdio.h>

int min(int a,int b){
  if(b<a) return b;
  return a;
}

void swap(int *a,int *b){
      int temp = *a;
      *a = *b;
      *b = temp;
}

int main()
{
 int a[1000],b[1000],x[1000],index[1000];
 int w[1000],t[1000],c[1000];
 int i,j,smallest,count=0,time,n;
 double avg=0,tt=0,end;

 printf("\nEnter the number of Processes: ");
 scanf("%d",&n);

 for(i=0;i<n;i++)
 {
   printf("\nEnter arrival time  ----  burst time %d : ",i+1);
   scanf("%d%d",&a[i],&b[i]);
   x[i]=b[i];
   index[i]=i+1;
 }

 int tq = 10;//Time Quant,
  for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
          if(a[j]<a[j-1]){
               swap(&a[j],&a[j-1]);
               swap(&b[j],&b[j-1]);
               swap(&index[j],&index[j-1]);
            }
        } 
  }

   i = 0;
 for(time=0;count!=n;)
 {

   int j = 0;
   int k = i;
   while((a[i]>time || b[i]==0) && j<n) {
    i = (i+1)%n;
    j++;
  }

  
  if(j==n){
      time++;
      i=k;
      continue;
  }
  

  time += min(tq,b[i]);
  b[i] -= min(tq,b[i]);

  if(b[i]==0)
  {
   count++;
   end=time;
   c[i] = end;
   w[i] = end - a[i] - x[i];
   t[i] = end - a[i];
  
  }
  i = (i+1)%n;

 }
 printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
 for(i=0;i<n;i++)
 {
   printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",index[i],x[i],a[i],w[i],t[i],c[i]);
   avg = avg + w[i];
   tt = tt + t[i];
 }
 printf("\n  %If   %If",avg,tt);
 printf("\n\nAverage waiting time = %lf\n",avg/n);
 printf("Average Turnaround time = %lf",tt/n);
}