#include<stdio.h>

int main()
{
int a[1000],b[1000],x[1000],p[1000];
int w[1000],t[1000],c[1000];
int i,j,smallest,count=0,time,n;
double avg=0,tt=0,end;

printf("\nEnter the number of Processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("\nEnter priority of process --- burst time %d : ",i+1);
scanf("%d%d",&p[i],&b[i]);

a[i] = 0;//Arrival time is 0
x[i]=b[i];
}

p[999]=99999;
a[999]=99999;

for(time=0;count!=n;)
{
smallest=999;
for(i=0;i<n;i++)
{
if(a[i]<=time && p[i]<p[smallest] && b[i]>0)
smallest=i;
else if(a[i]<=time && p[i]==p[smallest] && b[i]>0)
smallest = i;
}
if(smallest==999){
time++;
continue;
}
time += b[smallest];
b[smallest]==0;

if(b[smallest]==0)
{
count++;
end=time+1;
c[smallest] = end;
w[smallest] = end - a[smallest] - x[smallest];
t[smallest] = end - a[smallest];
  
}
}
printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
for(i=0;i<n;i++)
{
printf("\n %d \t %d \t %d\t\t%d \t\t%d\t\t%d",i+1,x[i],a[i],w[i],t[i],c[i]);
avg = avg + w[i];
tt = tt + t[i];
}
printf("\n %If %If",avg,tt);
printf("\n\nAverage waiting time = %lf\n",avg/n);
printf("Average Turnaround time = %lf",tt/n);
}