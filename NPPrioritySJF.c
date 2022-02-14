#include<stdio.h>
void main()
{
int i, j,temp,btemp,ptemp, at[6],bt[6],pt[6],wt[6],tt[6],sum=0,num,proc[6];
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
printf("\nEnter the Process Priority");
scanf("%d",&pt[i]);
}
for(i=0;i<num;i++) 
	{
		if(at[i]==0)
		{
			temp=at[0];
			at[0]=at[i];
			at[i]=temp;
			btemp=bt[0];
			bt[0]=bt[i];
			bt[i]=btemp;
			temp=proc[0];
			proc[0]=proc[i];
			proc[i]=temp;
			temp=pt[0];
			pt[0]=pt[i];
			pt[i]=temp;
              	
		}
}

for(i=1;i<num;i++)
{
	for(j=i+1;j<num;j++)
	{
		if(pt[i]>pt[j])
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
			temp=pt[i];
			pt[i]=pt[j];
			pt[j]=temp;
			
		}
}
	}
for(i=1;i<num;i++)
{
	for(j=i+1;j<num;j++)
	{
		if(pt[i]==pt[j])
		{
		if(bt[i]>bt[j])
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
			temp=pt[i];
			pt[i]=pt[j];
			pt[j]=temp;
			}
		}
}
	
}
printf("\nAfter Sorting on Arriival Time\n");
printf("Process\t Arrival Time\tBurst Time\t Priority\n");
for(i=0;i<num;i++)
{
printf("\nP%d\t",proc[i]);
printf("%d\t",at[i]);
printf("%d\t",bt[i]);
printf("%d\t",pt[i]);
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


