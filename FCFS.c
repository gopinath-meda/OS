//FCFS
#include<stdio.h>
int main()
{
    int n,bt[20],wt[20],tat[20],p[20],i,j,t=0;
    float avwt=0,avtat=0;
    printf("Enter total number of processes:");
    scanf("%d",&n);
    printf("Enter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    wt[0]=0;    //waiting time for first process is 0
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    printf("Order of process Execution is\n");
    for(i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",p[i],t,t+bt[i]);
        t+=bt[i];
    }
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time");
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("\nAverage Waiting Time:%.2f",avwt);
    printf("\nAverage Turnaround Time:%.2f",avtat);
    return 0;
}
