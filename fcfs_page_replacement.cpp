#include<iostream>
using namespace std;

void print(int frame[],int fc,int page_num)
{
    cout << endl;
    cout << page_num << " -> ";
    for (int i = 0; i < fc; i++)
    {
        cout<<frame[i]<<" ";
    }
}

int main()
{
    cout<<"FCFS PAGE REPLACEMENT ALGO\nEnter the number of pages: ";
    int n,hit = 0;
    cin>>n;

    cout<<"Enter the page numbers: ";
    int page_num[n];
    for(int i = 0;i < n;i++)
    {
        cin>>page_num[i];
    }

    cout<<"Enter the frame capacity: ";
    int fc;
    cin>>fc;

    int frame[fc];
    for(int i = 0;i < fc;i++)
    {
        frame[i] = -1;
    }

    int flag = 0;

    for(int i = 0;i < n;i++)
    {
        bool c = false;
        for(int j = 0;j < fc;j++)
        {
            if(page_num[i] == frame[j])
            {
                hit++;
                c = true;
                break;
            }
        }
        
        if(!c) {
            frame[flag] = page_num[i];
            flag = (flag + 1) % fc;
        }
        print(frame, fc, page_num[i]);
    }

    cout<<"\nNumber of Page Fault: "<<n-hit;
    cout<<"\nNumber of Page Hit: "<<hit;
}