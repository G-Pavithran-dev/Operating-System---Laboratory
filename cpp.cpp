// 1) fcfs
#include <stdio.h>
int main()
{
    int bt[10] = {0}, wt[10] = {0}, ct[10] = {0};
    float at[10] = {0}, tat[10] = {0};
    int n, sum = 0;
    float totalTAT = 0, totalWT = 0;

    printf("FCFS CPU SCHEDULING");
    printf("\n\nEnter number of process");
    scanf("%d", &n);
    printf("Enter arrival time and burst  time for each process\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Arrival time of process[%d]", i + 1);
        scanf("%f", &at[i]);
        printf("Burst time of process[%d] ", i + 1);
        scanf("%d", &bt[i]);
        printf("\n");
    }
    for (int j = 0; j < n; j++)
    {
        sum += bt[j];
        ct[j] += sum;
    }
    for (int k = 0; k < n; k++)
    {
        tat[k] = ct[k] - at[k];
        totalTAT += tat[k];
    }
    for (int k = 0; k < n; k++)
    {
        wt[k] = tat[k] - bt[k];
        totalWT += wt[k];
    }
    printf("Solution: \n\n");
    printf("P\t AT\t BT\t CT\t TAT\t WT\t\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t %.2f\t %d\t %d\t %.2f\t %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\nAverage Turnaround time = %f\n", totalTAT / n);
    printf("Average WT = %f\n\n", totalWT / n);
    return 0;
}

// input
// 5
// 0.0 10
// 1.1 5
// 3.1 2
// 5.1 7
// 7.1 5

// 2)SJF
#include <stdio.h>
int main()
{
    int A[100][4];
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;
    printf("Enter number of process: ");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        index = i;
        for (j = i + 1; j < n; j++)
            if (A[j][1] < A[index][1])
                ;
        index = j;
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
    A[0][2] = 0;
    for (i = 1; i < n; i++)
    {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];
        total += A[i][2];
    }
    avg_wt = (float)total / n;
    total = 0;
    printf("P  BT  WT  TAT\n");
    for (i = 0; i < n; i++)
    {
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];
        printf("P%d  %d  %d  %d\n", A[i][0], A[i][1], A[i][2], A[i][3]);
    }
    avg_tat = (float)total / n;
    printf("Average Waiting Time=%f", avg_wt);
    printf("\nAverage Turnaround Time=%f", avg_tat);
}

// input
// 4
// 8
// 5
// 10
// 11

// 3)RR
// Online C compiler to run C program online
#include <stdio.h>
 
int main()
{

    int cnt, j, n, t, remain, flag = 0, tq;
    int wt = 0, tat = 0, at[10], bt[10], rt[10];
    printf("Enter Total Process:\t ");
    scanf("%d", &n);
    remain = n;
    for (cnt = 0; cnt < n; cnt++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :", cnt + 1);
        scanf("%d", &at[cnt]);
        scanf("%d", &bt[cnt]);
        rt[cnt] = bt[cnt];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d", &tq);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for (t = 0, cnt = 0; remain != 0;)
    {
        if (rt[cnt] <= tq && rt[cnt] > 0)
        {
            t += rt[cnt];
            rt[cnt] = 0;
            flag = 1;
        }
        else if (rt[cnt] > 0)
        {
            rt[cnt] -= tq;
            t += tq;
        }
        if (rt[cnt] == 0 && flag == 1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", cnt + 1, t - at[cnt], t - at[cnt] - bt[cnt]);
            wt += t - at[cnt] - bt[cnt];
            tat += t - at[cnt];
            flag = 0;
        }
        if (cnt == n - 1)
            cnt = 0;
        else if (at[cnt + 1] <= t)
            cnt++;
        else
            cnt = 0;
    }
    printf("\nAverage Waiting Time= %f\n", wt * 1.0 / n);
    printf("Avg Turnaround Time = %f", tat * 1.0 / n);

    return 0;
}

// input
// 4
// 0 5
// 1 4
// 2 2
// 4 1
// 2

// 4)Dining Philosopher
#include <stdio.h>
#define n 4
int compltedPhilo = 0,i;
struct fork
{
    int taken;
} ForkAvil[n];

struct philosp
{
    int left;
    int right;
} Philostatus[n];

void goForDinner(int philID)
{
    if (Philostatus[philID].left == 10 && Philostatus[philID].right == 10)
    {
        printf("Philosopher %d completed his dinner\n", philID + 1);
    }
    else if (Philostatus[philID].left == 1 && Philostatus[philID].right == 1)
    {
        printf("Philosopher %d completed his dinner\n", philID + 1);
        Philostatus[philID].left = Philostatus[philID].right = 10;
        int otherFork = philID - 1;
        if (otherFork == -1)
            otherFork = (n - 1);
        ForkAvil[philID].taken = ForkAvil[otherFork].taken = 0;
        printf("Philosopher %d released fork %d and fork %d\n", philID + 1, philID + 1, otherFork + 1);
        compltedPhilo++;
    }
    else if (Philostatus[philID].left == 1 && Philostatus[philID].right == 0)
    {
        if (philID == (n - 1))
        {
            if (ForkAvil[philID].taken == 0)
            {
                ForkAvil[philID].taken = Philostatus[philID].right = 1;
                printf("Fork %d taken by philosopher %d\n", philID + 1, philID + 1);
            }
            else
            {
                printf("Philosopher %d is waiting for fork %d\n", philID + 1, philID + 1);
            }
        }
        else
        {
            int dupphilID = philID;
            philID -= 1;

            if (philID == -1)
                philID = (n - 1);

            if (ForkAvil[philID].taken == 0)
            {
                ForkAvil[philID].taken = Philostatus[dupphilID].right = 1;
                printf("Fork %d taken by Philosopher %d\n", philID + 1, dupphilID + 1);
            }
            else
            {
                printf("Philosopher %d is waiting for Fork %d\n", dupphilID + 1, philID + 1);
            }
        }
    }
    else if (Philostatus[philID].left == 0)
    {
        if (philID == (n - 1))
        {
            if (ForkAvil[philID - 1].taken == 0)
            {
                ForkAvil[philID - 1].taken = Philostatus[philID].left = 1;
                printf("Fork %d taken by philosopher %d\n", philID, philID + 1);
            }
            else
            {
                printf("Philosopher %d is waiting for fork %d\n", philID + 1, philID);
            }
        }
        else
        {
            if (ForkAvil[philID].taken == 0)
            {
                ForkAvil[philID].taken = Philostatus[philID].left = 1;
                printf("Fork %d taken by Philosopher %d\n", philID + 1, philID + 1);
            }
            else
            {
                printf("Philosopher %d is waiting for Fork %d\n", philID + 1, philID + 1);
            }
        }
    }
}

int main()
{
    for (i = 0; i < n; i++)
        ForkAvil[i].taken = Philostatus[i].left = Philostatus[i].right = 0;

    while (compltedPhilo < n)
    {
        for (i = 0; i < n; i++)
            goForDinner(i);

        printf("\nTill now num of philosophers completed dinner are %d\n\n", compltedPhilo);
    }

    return 0;
}

// 5)Banker's algorithm
#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    n = 5;
    m = 3;
    int alloc[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 2}, {0, 0, 2}};
    int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail[3] = {3, 3, 2};
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i + 1;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The folowing system is not safe");
            break;
        }
    }
    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[i]);
    }
    return 0;
}

// 6)FIRST-FIT
#include <stdio.h>
#define max 25
int main()
{
    int b[max], f[max], i, j, nb, nf;
    static int ff[max];
    int flag, flagn[max];
    printf("\n__First Fit\n");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of Process:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
        ff[i] = i;
    }
    printf("Enter the size of the Processes :-\n");
    for (i = 1; i <= nf; i++)
    {
        printf("Process %d:", i);
        scanf("%d", &f[i]);
    }
    int x = 1;
    printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment\n");
    for (i = 1; i <= nf; i++)
    {
        flag = 1;
        for (j = x; j <= nb; j++)
        {
            if (f[i] <= b[j])
            {
                printf("%-15d\t%-15d\t%-15d\t%-15d\t", i, f[i], ff[j], b[j]);
                b[j] = b[j] - f[i];
                printf("%-15d\n", b[j]);
                break;
            }
            else
            {
                x = 1;
                flag++;
            }
        }
        if (flag > nb)
            printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n", i, f[i], "Has to wait...", "...", "...");
    }
    return 0;
}

// input
// 5
// 4
// 100
// 500
// 200
// 300
// 600
// 212
// 417
// 112
// 426

// 7)BEST-FIT
#include <stdio.h>
#define max 25
int main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest = 10000;
    static int bf[max], ff[max], fragi = 0;
    printf("\n__Best Fit\n");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("\nEnter the number of files:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
        ff[i] = i;
    }
    printf("\nEnter the size of the processors :-\n");
    for (i = 1; i <= nf; i++)
    {
        printf("Process %d:", i);
        scanf("%d", &f[i]);
    }
    int y, m, z, temp1, flag;
    for (y = 1; y <= nb; y++)
    {
        for (z = y; z <= nb; z++)
        {
            if (b[y] > b[z])
            {
                temp = b[y];
                b[y] = b[z];
                b[z] = temp;
                temp1 = ff[y];
                ff[y] = ff[z];
                ff[z] = temp1;
            }
        }
    }
    int flagn[max];
    int fragx = 0;
    printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment\n");
    for (i = 1; i <= nf; i++)
    {
        flag = 1;
        for (j = 1; j <= nb; j++)
        {
            if (f[i] <= b[j])
            {
                flagn[j] = 1;
                printf("%-15d\t%-15d\t%-15d\t%-15d\t", i, f[i], ff[j], b[j]);
                b[j] = b[j] - f[i];
                fragi = fragi + b[j];
                printf("%-15d\n", b[j]);
                break;
            }
            else
            {
                flagn[j] = 0;
                flag++;
            }
        }
        if (flag > nb)
            printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n", i, f[i], "Has to wait..", "..", "..");
    }
    return 0;
}

// input
// 5
// 4
// 100
// 500
// 200
// 300
// 600
// 212
// 417
// 112
// 426

// 8)WORST-FIT
#include <stdio.h>
#define max 25
int main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0;
    static int bf[max], ff[max];
    int flag, fragi = 0;
    printf("\n_Worst Fit_\n");
    printf("\nEnter the number of memory blocks:");
    scanf("%d", &nb);
    printf("Enter the number of Process:");
    scanf("%d", &nf);
    printf("\nEnter the size of the memory blocks:\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
        ff[i] = i;
    }
    printf("Enter the size of the processes :\n");
    for (i = 1; i <= nf; i++)
    {
        printf("Process %d: ", i);
        scanf("%d", &f[i]);
    }
    int y, z, temp1;
    for (y = 1; y <= nb; y++)
    {
        for (z = y; z <= nb; z++)
        {
            if (b[y] < b[z])
            {
                temp = b[y];
                b[y] = b[z];
                b[z] = temp;
                temp1 = ff[y];
                ff[y] = ff[z];
                ff[z] = temp1;
            }
        }
    }
    int flagn[max];
    int fragx = 0;
    printf("\n\nProcess No\tProcess Size\tMemory No\tMemory Size\tRemaining\n");
    for (i = 1; i <= nf; i++)
    {
        flag = 1;
        for (int j = 1; j <= nb; j++)
        {
            if (f[i] <= b[j])
            {
                flagn[j] = 1;
                printf("%-15d\t%-15d\t%-15d\t%-15d\t", i, f[i], ff[j], b[j]);
                b[j] = b[j] - f[i];
                fragi = fragi + b[j];
                printf("%-15d\n", b[j]);
                break;
            }
            else
            {
                flagn[j] = 0;
                flag++;
            }
        }
        if (flag > nb)
            printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n", i, f[i], "Has to wait..", "..", "..");
    }
    return 0;
}

// input
// 4
// 100
// 500
// 200
// 300
// 600
// 212
// 417
// 112
// 426

// 9)FIFO
#include <stdio.h>
int main()
{
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");
    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for (m = 0; m < pages; m++)
    {
        s = 0;

        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;

        if ((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("\n");
        printf("%d\t\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}

// 10)LRU
#include <stdio.h>
int main()
{
    int q[20], p[50], c = 0, c1, d, f, i, j, k = 0, n, r, t, b[20], c2[20];
    printf("Enter no of pages:");
    scanf("%d", &n);
    printf("Enter the reference string:");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter no of frames:");
    scanf("%d", &f);
    q[k] = p[k];
    printf("\n\t%d\n", q[k]);
    c++;
    k++;
    for (i = 1; i < n; i++)
    {
        c1 = 0;
        for (j = 0; j < f; j++)
        {
            if (p[i] != q[j])
                c1++;
        }
        if (c1 == f)
        {
            c++;
            if (k < f)
            {
                q[k] = p[i];
                k++;
                for (j = 0; j < k; j++)
                    printf("\t%d", q[j]);
                printf("\n");
            }
            else
            {
                for (r = 0; r < f; r++)
                {
                    c2[r] = 0;
                    for (j = i - 1; j < n; j--)
                    {
                        if (q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for (r = 0; r < f; r++)
                    b[r] = c2[r];
                for (r = 0; r < f; r++)
                {
                    for (j = r; j < f; j++)
                    {
                        if (b[r] < b[j])
                        {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }
                for (r = 0; r < f; r++)
                {
                    if (c2[r] == b[0])
                        q[r] = p[i];
                    printf("\t%d", q[r]);
                }
                printf("\n");
            }
        }
    }
    printf("\nThe no of page faults is %d", c);
}

// input 10 7 5 9 4 3 7 9 6 2 1 4

// optimal
//  You are using GCC
#include <stdio.h>
    int
    main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");

    for (i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for (j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);
    return 0;
}

// input 3 10 1 2 3 4 3 2 1 1 4 3

// FCFS DISK
#include <stdio.h>
#include <stdlib.h>
    int
    main()
{
    int queue[100], q_size, head, seek = 0, diff;
    float avg;
    printf("_DISK SCHEDULING_(FCFS)\n\n");
    printf("%s\n", "Enter the size of the queue");
    scanf("%d", &q_size);
    printf("%s\n", "Enter queue elements");
    for (int i = 1; i <= q_size; i++)
    {
        scanf("%d", &queue[i]);
    }
    printf("%s\n", "Enter initial head position");
    scanf("%d", &head);
    queue[0] = head;
    for (int j = 0; j <= q_size - 1; j++)
    {
        diff = abs(queue[j] - queue[j + 1]);
        seek += diff;
    }
    printf("\nNumber of cylinders are %d\t", seek);
    return 0;
}

// input 9 246 1105 4053 324 40 1739 32 2467 500 356

// C-LOOK
//  You are using GCC
#include <stdio.h>
#include <stdlib.h>
    int
    main()
{
    int n, i, j, head, item[20], dst[20];
    int cylinders = 0;
    printf("_DISK SCHEDULING_(C-LOOK)\n\n");
    printf("Enter no. of locations:\n");
    scanf("%d", &n);
    printf("Enter position of head:\n");
    scanf("%d", &head);
    printf("Enter elements of disk queue:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &item[i]);
        dst[i] = (head - item[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (dst[j] < dst[i])
            {
                int temp = dst[j];
                dst[j] = dst[i];
                dst[i] = temp;
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (item[i] <= head)
        {
            j = i;
            break;
        }
    }
    for (i = j - 1; i >= 0; i--)
    {
        cylinders += abs(head - item[i]);
        head = item[i];
    }
    for (i = n - 1; i >= j; i--)
    {
        cylinders += abs(head - item[i]);
        head = item[i];
    }
    /*for(i=j;i<n;i++){
        cylinders+= abs(head-item[i]);
        head=item[i];
    }
    for(i=0;i<j;i++){
        cylinders+= abs(head-item[i]);
        head=item[i];
    }*/
    printf("\n\nNumber of cylinders are %d\n\n", cylinders);
}

// INPUT
// 9 96 86 147 91 177 94 150 102 175 130

// LOOK
#include <math.h>
#include <stdio.h>
    int
    main()
{
    int i, n, j = 0, k = 0, x = 0, l, req[50], mov = 0, cp, ub, end, lower[50], upper[50], temp, a[50];
    printf("_DISK SCHEDULING_(LOOK)\n\n");
    printf("Enter the current head position: ");
    scanf("%d", &cp);
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the request order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }
    printf("Enter the upper bound: ");
    scanf("%d", &ub);
    for (i = 0; i < n; i++)
    {
        if (req[i] < cp)
        {
            lower[j] = req[i];
            j++;
        }
        if (req[i] > cp)
        {
            upper[k] = req[i];
            k++;
        }
    }
    for (i = 0; i < j; i++)
    {
        for (l = 0; l < j - 1; l++)
        {
            if (lower[l] < lower[l + 1])
            {
                temp = lower[l];
                lower[l] = lower[l + 1];
                lower[l + 1] = temp;
            }
        }
    }
    for (i = 0; i <= k; i++)
    {
        for (l = 0; l < k - 1; l++)
        {
            if (upper[l] > upper[l + 1])
            {
                temp = upper[l];
                upper[l] = upper[l + 1];
                upper[l + 1] = temp;
            }
        }
    }
    printf("Enter the end to which the head is moving 0 - for lower end and 1 - for upperend\n");
    scanf("%d", &end);
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("Solution:");
    printf("\n\n Movement:\n");
    switch (end)
    {
    case 0:
        for (i = 0; i < j; i++)
        {
            a[x] = lower[i];
            x++;
        }
        for (i = 0; i < k; i++)
        {
            a[x] = upper[i];
            x++;
        }
        break;
    case 1:
        for (i = 0; i < k; i++)
        {
            a[x] = upper[i];
            x++;
        }
        for (i = 0; i < j; i++)
        {
            a[x] = lower[i];
            x++;
        }
        break;
    }
    mov = mov + abs(cp - a[0]);
    printf("%d -> %d", cp, a[0]);
    for (i = 1; i < x; i++)
    {
        mov = mov + abs(a[i] - a[i - 1]);
        printf(" -> %d", a[i]);
    }
    printf("\n");
    printf("Total distance in cylinders = %d cylinders\n", mov);
}

// INPUT
// 96 9 86 147 91 177 94 150 102 175 130 199 1 

// C-SCAN
#include <stdlib.h>
#include <stdio.h>
#define HIGH 199
#define LOW 0
    int
    main()
{
    int queue[20], q_size, head, i, j, seek = 0, diff, max, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float avg;
    printf("_DISK SCHEDULING_(C SCAN)\n\n");
    printf("%s\t", "Input no of disk locations");
    scanf("%d", &q_size);
    printf("%s\t", "Enter initial head position");
    scanf("%d", &head);
    printf("%s\n", "Enter disk positions to be read");
    for (i = 0; i < q_size; i++)
    {
        scanf("%d", &temp);
        if (temp >= head)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }
    if (abs(head - LOW) >= abs(head - HIGH))
    {
        for (i = 1, j = 0; j < temp1; i++, j++)
        {
            queue[i] = queue1[j];
        }
        queue[i] = HIGH;
        queue[i + 1] = 0;
        for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
        {
            queue[i] = queue2[j];
        }
    }
    else
    {
        for (i = 1, j = temp2 - 1; j >= 0; i++, j--)
        {
            queue[i] = queue2[j];
        }
        queue[i] = LOW;
        queue[i + 1] = HIGH;
        for (i = temp2 + 3, j = temp1 - 1; j >= 0; i++, j--)
        {
            queue[i] = queue1[j];
        }
    }
    for (j = q_size + 1; j >= 0; j--)
    {
        diff = abs(queue[j + 1] - head);
        head = queue[j + 1];
        seek += diff;
    }
    printf("The number of cylinders are %d\n", seek);
    return 0;
}

// INPUT
// 9 96 86 147 91 177 94 150 102 175 130

// SCAN
#include <stdio.h>
#include <stdlib.h>
#define LOW 0
#define HIGH 4299
    int
    main()
{
    int queue[20];
    int head, max, q_size, temp, sum;
    int dloc;
    printf("\n_DISK SCHEDULING_(SCAN)\n\n");
    printf("Enter head position:");
    scanf("%d", &head);
    printf("Enter no.of Disk Requests:");
    scanf("%d", &q_size);
    printf("Enter the elements into disk queue:\n");
    for (int i = 0; i < q_size; i++)
    {
        scanf("%d", &queue[i]);
    }
    queue[q_size] = head;
    q_size++;
    for (int i = 0; i < q_size; i++)
    {
        for (int j = i; j < q_size; j++)
        {
            if (queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    max = queue[q_size - 1];
    for (int i = 0; i < q_size; i++)
    {
        if (head == queue[i])
        {
            dloc = i;
            break;
        }
    }
    if (abs(head - LOW) <= abs(head - HIGH))
    {
        for (int j = dloc; j >= 0; j--)
        {
        }
        for (int j = dloc + 1; j < q_size; j++)
        {
        }
    }
    else
    {
        for (int j = dloc + 1; j < q_size; j++)
        {
        }
        for (int j = dloc; j >= 0; j--)
        {
        }
    }
    sum = head + max;
    printf("\nTotal Seek Time: %d cylinders", sum);
    return 0;
}

// INPUT
// 96 9 86 147 91 177 94 150 102 175 130

// SSTF
#include <stdio.h>
    struct head
{
    int num;
    int flag;
};
int main()
{
    struct head h[33];
    int array_1[33], array_2[33];
    int count = 0, j, x, limit, minimum, location, disk_head, sum = 0;
    printf("_DISK SCHEDULING_(SSTF)\n\n");
    printf("\nEnter total number of locations:\t");
    scanf("%d", &limit);
    printf("\nEnter position of disk head:\t");
    scanf("%d", &disk_head);
    printf("\nEnter elements of disk head queue\n");
    while (count < limit)
    {
        scanf("%d", &h[count].num);
        h[count].flag = 0;
        count++;
    }
    for (count = 0; count < limit; count++)
    {
        x = 0;
        minimum = 0;
        location = 0;
        for (j = 0; j < limit; j++)
        {
            if (h[j].flag == 0)
            {
                if (x == 0)
                {
                    array_1[j] = disk_head - h[j].num;
                    if (array_1[j] < 0)
                    {
                        array_1[j] = h[j].num - disk_head;
                    }
                    minimum = array_1[j];
                    location = j;
                    x++;
                }
                else
                {
                    array_1[j] = disk_head - h[j].num;
                    if (array_1[j] < 0)
                    {
                        array_1[j] = h[j].num - disk_head;
                    }
                }
                if (minimum > array_1[j])
                {
                    minimum = array_1[j];
                    location = j;
                }
            }
        }
        h[location].flag = 1;
        array_2[count] = h[location].num - disk_head;
        if (array_2[count] < 0)
        {
            array_2[count] = disk_head - h[location].num;
        }
        disk_head = h[location].num;
    }
    count = 0;
    while (count < limit)
    {
        sum = sum + array_2[count];
        count++;
    }
    printf("\nTotal movements of the cylinders:\t%d", sum);
    return 0;
}

// INPUT
// 9 96 86 147 91 177 94 150 102 175 130