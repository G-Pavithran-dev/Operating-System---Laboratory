#include <iostream>
using namespace std;

int main()
{

    cout << "-----------BANKER'S ALGORITHM-----------\n\n";
    int process, resources, index = 0;
    cout << "Enter the number of process(es): ";
    cin >> process;

    cout << "Enter the number of resource(s): ";
    cin >> resources;

    int allocation[process][resources];
    int maximum[process][resources];
    int available_resource[resources];

    for (int i = 0; i < process; i++)
    {
        cout << "\nEnter the allocations for process P" << i << ": ";
        for (int j = 0; j < resources; j++)
        {
            cin >> allocation[i][j];
        }

        cout << "Enter the maximum resource for process P" << i << ": ";
        for (int j = 0; j < resources; j++)
        {
            cin >> maximum[i][j];
        }
    }
    cout << "\n\nEnter the initial available resources: ";
    for (int i = 0; i < resources; i++)
    {
        cin >> available_resource[i];
    }

    cout << "\nProcess Table: ";
    cout << "\n---------------------------------";
    cout << "\nProcess | Allocations | Maximum |";
    cout << "\n---------------------------------";
    for (int i = 0; i < process; i++)
    {
        cout << "\nP" << i << "      | ";
        for (int j = 0; j < resources; j++)
        {
            cout << allocation[i][j] << " ";
        }
        cout << "      | ";
        for (int j = 0; j < resources; j++)
        {
            cout << maximum[i][j] << " ";
        }
        cout << "  | ";
    }
    cout << "\n---------------------------------";
    cout << "\n\nAvailable Resources: ";
    for (int i = 0; i < resources; i++)
    {
        cout << available_resource[i] << " ";
    }
    cout << "\n\nNeed Matrx: ";
    cout << "\n-------------------";
    cout << "\nProcess | Need    |";
    cout << "\n-------------------";

    int need[process][resources];
    for (int i = 0; i < process; i++)
    {
        cout << "\nP" << i << "      | ";
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
            cout << need[i][j] << " ";
        }
        cout << "  |";
    }
    cout << "\n-------------------\n";
    int safe_sequence[process];
    int finished[process];

    for (int i = 0; i < process; i++)
    {
        safe_sequence[i] = 0;
        finished[i] = 0;
    }

    for (int k = 0; k < process; k++)
    {
        for (int i = 0; i < process; i++)
        {
            if (finished[i] == 0)
            {
                bool flag = true;
                for (int j = 0; j < resources; j++)
                {
                    if (need[i][j] > available_resource[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    safe_sequence[index++] = i;
                    cout << "\nUpdated Available Resources after allocated to process P" << i << ": ";
                    for (int j = 0; j < resources; j++)
                    {
                        available_resource[j] += allocation[i][j];
                        cout << available_resource[j] << " ";
                    }
                    finished[i] = 1;
                }
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < process; i++)
    {
        if (finished[i] == 0)
        {
            flag = false;
            cout << "\nThe System is'nt in safe state\n";
            break;
        }
    }
    if (flag)
    {
        cout << "\n\nThe System is in safe state.";
        cout << "\nSafe Sequence: ";
        for (int i = 0; i < process; i++)
        {
            cout << "P" << safe_sequence[i] << " -> ";
            if(i == process-1)
            cout << "P" << safe_sequence[i];
        }
    }

    cout << "\n\n";
}
