#include<iostream>
using namespace std;

int main()
{
    cout << "---------FCFS---------\n";
    cout << "Enter the number of requests: ";
    int n,head;
    cin>>n;

    cout<<"Enter the requests: ";
    int request[n];
    for(int i = 0;i < n;i++)
    {
        cin>>request[i];
    }

    cout<<"Enter the head position: ";
    cin>>head;

    cout<<"\nDisk scheduled as per the FCFS: ";
    for(int i = 0;i < n;i++)
    {
        cout<<request[i]<<" ";
        if(i != n-1)
            cout<<"-> ";
    }

    cout<<"\nTotal seek time : ";
    int seek_time = 0;
    for(int i = 0;i < n;i++)
    { 
        if(i == 0)
        {
            seek_time += abs(head - request[i]);
        }
        else{
            seek_time += abs(request[i] - request[i-1]);
        }
    }
    cout<<seek_time<<" milliseconds";

}