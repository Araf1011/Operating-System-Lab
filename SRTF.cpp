// SRTF - Shortest Remaining Time First (preemptive SJF)
// Needs arrival time, otherwise it is the same as SJF
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[100], burst[100], process[100], remaining[100];
    int completion[100], waiting[100], turnaround[100];

    for (int i = 0; i < n; i++) {

        process[i] = i + 1;

        cout << "Enter Arrival Time for P" << i + 1 << ": ";
        cin >> arrival[i];

        cout << "Enter Burst Time for P" << i + 1 << ": ";
        cin >> burst[i];

        remaining[i] = burst[i];
    }

    int time = 0, completed = 0, last = -1;

    cout << "\nExecution Order: ";

    while (completed < n) {

        // Find the arrived process with the shortest remaining time

        int shortest = -1;

        for (int i = 0; i < n; i++) {

            if (arrival[i] <= time && remaining[i] > 0) {

                if (shortest == -1 || remaining[i] < remaining[shortest]) {

                    shortest = i;
                }
            }
        }

        if (shortest == -1) {          // nobody has arrived yet, CPU idle

            time++;
            continue;
        }

        if (shortest != last) {        // print only when CPU switches process

            cout << "P" << process[shortest] << " ";
            last = shortest;
        }

        remaining[shortest]--;         // run it for 1 unit
        time++;

        if (remaining[shortest] == 0) {

            completion[shortest] = time;
            completed++;
        }
    }

    for (int i = 0; i < n; i++) {

        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    int totalWaiting = 0;
    int totalTurnaround = 0;

    cout << "\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << process[i] << "\t"
             << arrival[i] << "\t"
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
