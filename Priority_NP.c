//Priority Non-preemptive
#include <stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n,i,j,t=0,wait_time[20],turn_Around[20],total_wait_time = 0,total_Turn_Around = 0;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    int burst[n],priority[n],index[n];
    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
        scanf("%d %d",&burst[i],&priority[i]);
        index[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        int temp=priority[i],m=i;
        for(j=i;j<n;j++)
        {
            if(priority[j] < temp)
            {
                temp=priority[j];
                m=j;
            }
        }
        swap(&priority[i], &priority[m]);
        swap(&burst[i], &burst[m]);
        swap(&index[i],&index[m]);
    }
    printf("Order of process Execution is\n");
    for(i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",index[i],t,t+burst[i]);
        t+=burst[i];
    }
    printf("Process Id\tBurst Time\tWait Time\t Turn Around Time\n");
    wait_time[0]=0;
    for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for (j=0;j<i;j++)
        wait_time[i] += burst[j];
        total_wait_time += wait_time[i];
    }
    for(i=0; i < n; i++){
        turn_Around[i]= burst[i]+wait_time[i];
        total_Turn_Around+=turn_Around[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n",index[i],burst[i],wait_time[i],turn_Around[i]);
    }
    float avg_wait_time =(float)total_wait_time / n;
    printf("Average waiting time is %.2f\n", avg_wait_time);
    float avg_Turn_Around =(float)total_Turn_Around / n;
    printf("Average TurnAround Time is %.2f",avg_Turn_Around);
    return 0;
}
