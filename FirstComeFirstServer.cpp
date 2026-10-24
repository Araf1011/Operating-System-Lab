// FCFS - First Come First Serve
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int burst[100], process[100];
    int waiting[100], turnaround[100];

    for (int i = 0; i < n; i++) {

        process[i] = i + 1;

        cout << "Enter Burst Time for P" << i + 1 << ": ";
        cin >> burst[i];
    }

    // No sorting: processes run in the order they came

    waiting[0] = 0;

    for (int i = 1; i < n; i++) {

        waiting[i] = waiting[i - 1] + burst[i - 1];
    }

    for (int i = 0; i < n; i++) {

        turnaround[i] = waiting[i] + burst[i];
    }

    cout << "\nExecution Order: ";

    for (int i = 0; i < n; i++) {

        cout << "P" << process[i] << " ";
    }

    int totalWaiting = 0;
    int totalTurnaround = 0;

    cout << "\n\nProcess\tBurst\tWaiting\tTurnaround\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << process[i] << "\t"
             << burst[i] << "\t"
             << waiting[i] << "\t"
             << turnaround[i] << endl;

        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }

    cout << "\nAverage Waiting Time: "
         << (float)totalWaiting / n;

    cout << "\nAverage Turnaround Time: "
         << (float)totalTurnaround / n;

    return 0;
}
