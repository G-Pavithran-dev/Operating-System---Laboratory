#include <bits/stdc++.h>
using namespace std;

void first_fit(int nr, int nb, int request[], int block[])
{
    int allocation[nr];
    memset(allocation, -1, sizeof(allocation));

    cout << "\nFIRST FIT: \n";
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (request[i] <= block[j])
            {
                allocation[i] = j;
                block[j] -= request[i];
                break;
            }
        }
    }

    cout<<"Process Request Allocated_to";
    for(int i = 0;i < nr;i++)
    {
        cout<<"\nP"<<i<<"\t"<<request[i]<<"\t"<<allocation[i];
    }
}

void best_fit(int nr, int nb, int request[], int block[])
{
    cout << "\nBEST FIT: \n";
    sort(block, block + nb);
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (request[i] <= block[j])
            {
                block[j] -= request[i];
                break;
            }
        }
    }
}

void worst_fit(int nr, int nb, int request[], int block[])
{
    cout << "\nWORST FIT: \n";
    sort(block, block + nb, greater<int>());
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (request[i] <= block[j])
            {
                block[j] -= request[i];
                cout << "Request " << i + 1 << " --> Block " << j + 1 << endl;
                break;
            }
        }
    }
}

int main()
{
    cout << "Enter the number of requests: ";
    int nr;
    cin >> nr;

    cout << "Enter the request(s): ";
    int request[nr];
    for (int i = 0; i < nr; i++)
    {
        cin >> request[i];
    }

    cout << "Enter the number of blocks: ";
    int nb;
    cin >> nb;

    cout << "Enter the block size(in KB): ";
    int block[nb];
    for (int i = 0; i < nb; i++)
    {
        cin >> block[i];
    }

    first_fit(nr, nb, request, block);
    best_fit(nr, nb, request, block);
    worst_fit(nr, nb, request, block);
}