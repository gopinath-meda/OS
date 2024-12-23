//SJF
#include<stdio.h>
void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,t=0,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;            //waiting time for first process will be zero
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    avg_wt=(float)total/n;      //average waiting time
    total=0;
    printf("Order of process Execution is\n");
    for(i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",p[i],t,t+bt[i]);
        t+=bt[i];
    }
    printf("Process\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avg_tat=(float)total/n;     //average turnaround time
    printf("\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
}
