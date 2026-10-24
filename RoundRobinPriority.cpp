// Round Robin + Priority
// Highest priority runs first; processes with the SAME priority
// share the CPU in round robin. Smaller number = higher priority.
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    int burst[100], process[100], priority[100], remaining[100];
    int completion[100], waiting[100], turnaround[100];

    for (int i = 0; i < n; i++) {

        process[i] = i + 1;

        cout << "Enter Burst Time for P" << i + 1 << ": ";
        cin >> burst[i];

        cout << "Enter Priority for P" << i + 1 << ": ";
        cin >> priority[i];

        remaining[i] = burst[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    int time = 0, completed = 0;

    cout << "\nExecution Order: ";

    while (completed < n) {

        // Find the highest priority among unfinished processes

        int best = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (remaining[i] > 0 && priority[i] < best) {

                best = priority[i];
            }
        }

        // One round robin turn for every process with that priority

        for (int i = 0; i < n; i++) {

            if (remaining[i] > 0 && priority[i] == best) {

                cout << "P" << process[i] << " ";

                if (remaining[i] > quantum) {

                    time += quantum;
                    remaining[i] -= quantum;
                }
                else {

                    time += remaining[i];
                    remaining[i] = 0;
                    completion[i] = time;
                    completed++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {

        turnaround[i] = completion[i];          // all arrive at time 0
        waiting[i] = turnaround[i] - burst[i];
    }

    int totalWaiting = 0;
    int totalTurnaround = 0;

    cout << "\n\nProcess\tPriority\tBurst\tWaiting\tTurnaround\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << process[i] << "\t"
             << priority[i] << "\t\t"
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
