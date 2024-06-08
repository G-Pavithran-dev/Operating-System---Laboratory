#include<iostream>
using namespace std;

int main()
{
    /**
     * 1-  Input the processes along with their burst time (bt).
     * 
     * 2-  Find waiting time (wt) for all processes.
     * 
     * 3-  As first process that comes need not to wait so waiting time for process 1 will be 0 i.e. wt[0] = 0.
     * 
     * 4-  Find waiting time for all other processes i.e. for process i ->
     *              wt[i] = bt[i-1] + wt[i-1] .
     * 
     * 5-  Find turnaround time = WT + burst_time for all processes.
     * 
     * 6-  Find average waiting time =
                 TOTAL_WT / no_of_processes

     * 7-  Similarly, find average turnaround time =
                total_TAT / no_of_processes
     */

    cout<<"FCFS CPU Sheduling\nEnter the number of process: ";
    int n;
    cin>>n;

    cout<<"Enter the "<<n<<"'s burst time: ";
    int BT[n];
    for(int i = 0;i < n;i++)
    {
        cin>>BT[i];
    }

    int WT[n];
    int TAT[n];

    int TOTAL_WT = 0;
    int TOTAL_TAT = 0;

    WT[0] = 0;
    for(int i = 1;i < n;i++)
    {
        WT[i] = BT[i-1] + WT[i-1];
        TOTAL_WT += WT[i];
    }

    for(int i = 0;i < n;i++)
    {
        TAT[i] = BT[i] + WT[i];
        TOTAL_TAT += TAT[i];
    }

    cout<<"\nProcess Burst_Time Waiting_Time Turnaround_Time";
    for(int i = 0;i < n;i++)
    {
        cout<<"\nP"<<i<<"\t"<<BT[i]<<"\t"<<WT[i]<<"\t"<<TAT[i];
    }

    cout<<"\n\nAverage waiting time = "<<double(TOTAL_TAT/n)<<"ms";
    cout<<"\nAverage turnaround time = "<<double(TOTAL_WT/n)<<"ms";
}