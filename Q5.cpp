#include <bits/stdc++.h>
using namespace std;
int a[10][6];
//[][0]-PID,[][1]- queue no., [][2]- burst time, [][3]- waiting time, [][4]-turn_around_time
int main()
{
    cout << fixed << setprecision(2);
    int n;
    cout << "enter no of processes : ";
    cin >> n;
    int total_time = 0;
    int m = 0;
    cout << "enter queue no. - 0/1 (sjf preemptive/ fcfs) and burst time for the processes\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][1] >> a[i][2]; // queue, burst time
        a[i][0] = i + 1;           // PID
        cout << endl;
        if (a[i][1] == 0)
            m++; // number of processes in queue 1
        total_time += a[i][2];
    }
    int remaining_t[n];
    for (int i = 0; i < n; i++)
    {
        remaining_t[i] = a[i][2];
    }
    int complete = 0, min_time = INT_MAX, shortest = 0, completion_time = 0;
    // bool check = false;
    // queue 1 will be given priority over and processes in queue 1 will undergo sf=jf
    // non preemptive scheduling
    while (complete != m)
    {
        for (int j = 0; j < n; j++)
        {
            if ((remaining_t[j] < min_time) && remaining_t[j] > 0 && !a[j][1])
            {
                min_time = remaining_t[j];
                shortest = j;
            }
        }
        remaining_t[shortest] = 0;
        min_time = 0;
        // when the process gets completely executed
        if (min_time == 0)
        {
            min_time = INT_MAX;
            complete++;
            completion_time += a[shortest][2];
            a[shortest][4] = completion_time; // completion time
            a[shortest][3] = completion_time - a[shortest][2];
            // waiting time = completion time - burst time - arrival time( arrival timeis 0 for all processes)
            if (a[shortest][3] < 0)
                a[shortest][3] = 0;
        }
    }
    // Now remaining processes of queue 2 will be done according to fcfs
    for (int i = 0; i < n; i++)
    {
        if (a[i][1])
        {
            a[i][3] = completion_time;
            a[i][4] = a[i][3] + a[i][2];
            completion_time += a[i][2];
        }
    }
    int total_turnaround = 0, total_waiting = 0;
    for (int i = 0; i < n; i++)
    {
        total_waiting += a[i][3];
        total_turnaround += a[i][4];
    }
    cout << "Process Id\tBurst time\tTurnaround time\tWaiting time\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i][0] << "\t\t" << a[i][2] << "\t\t" << a[i][4] << "\t\t" << a[i][3] << "\n";
    }
    cout << "\t\t\t\t"
         << "Avg TAT " << float(total_turnaround) / float(n) << "\t\t"
         << "Avg WT "<<float(total_waiting)/float(n)<<"\n ";
        cout
         << "Throughput = " << float(n * 100) / total_time;
}