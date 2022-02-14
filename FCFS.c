#include<stdio.h>
void main()
{
int i, j,temp,btemp, at[6],bt[6],wt[6],tt[6],sum=0,num,proc[6];
float avrg,avg;
printf("Enter the Number of Processes");
scanf("%d",&num);
for(i=0;i<num;i++)
{
printf("\nEnter the Process Number");
scanf("%d",&proc[i]);
printf("\nEnter the Process Arrival Time");
scanf("%d",&at[i]);
printf("\nEnter the Process Burt time");
scanf("%d",&bt[i]);
}
for(i=0;i<num;i++)
{
	for(j=i+1;j<num;j++)
	{
		if(at[i]>at[j])
		{
			temp=at[i];
			at[i]=at[j];
			at[j]=temp;
			btemp=bt[i];
			bt[i]=bt[j];
			bt[j]=btemp;
			temp=proc[i];
			proc[i]=proc[j];
			proc[j]=temp;
		}
	}
}
printf("\nAfter Sorting on Arriival Time\n");
printf("Process\t Arrival Time\tBurst Time\n");
for(i=0;i<num;i++)
{
printf("\nP%d\t",proc[i]);
printf("%d\t",at[i]);
printf("%d\t",bt[i]);
}
wt[0]=0;
for(i=0;i<num;i++)
{
wt[i+1]=wt[i]+bt[i];
sum+=(wt[i]-at[i]);
}
wt[num]=wt[num-1]+bt[num-1];
printf("\nthe waiting time is \t%d",sum);
avrg=(float)sum/(float)num;
printf("\nthe Average waiting time is \t%f",avrg);
sum=0;
for(i=0;i<num;i++)
{
tt[i]=wt[i+1]-at[i];
sum+=tt[i];
}
printf("\nthe sum of Turnaround time is \t%d",sum);
avg=(float)sum/(float)num;
printf("\nthe Average Turnaround time is \t%f",avg);
printf("\n GANTT CHART \n");
printf("\n------------------------------------------------------\n");
for(i=0;i<num;i++)
{
printf("\t|p%d\t",proc[i]);
}
printf("\n------------------------------------------------------\n");
for(i=0;i<=num;i++)
{
printf("%d\t\t",wt[i]);
}
}
