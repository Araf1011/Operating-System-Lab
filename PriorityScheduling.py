def main():
    n = int(input("Enter number of processes: "))

    processes = []
    burst = []
    priority = []

    for i in range(n):
        processes.append(i + 1)
        b = int(input(f"Enter Burst Time for P{i + 1}: "))
        p = int(input(f"Enter Priority for P{i + 1}: "))
        burst.append(b)
        priority.append(p)

    for i in range(n - 1):
        for j in range(i + 1, n):
            if priority[i] > priority[j]:
                priority[i], priority[j] = priority[j], priority[i]
                burst[i], burst[j] = burst[j], burst[i]
                processes[i], processes[j] = processes[j], processes[i]

    waiting = [0] * n
    for i in range(1, n):
        waiting[i] = waiting[i - 1] + burst[i - 1]

    turnaround = [0] * n
    for i in range(n):
        turnaround[i] = waiting[i] + burst[i]

    print("\nExecution Order:", end=" ")
    for p in processes:
        print(f"P{p}", end=" ")
    print()

    total_waiting = 0
    total_turnaround = 0

    print("\nProcess\tPriority\tBurst\tWaiting\tTurnaround")
    for i in range(n):
        print(f"P{processes[i]}\t{priority[i]}\t\t{burst[i]}\t{waiting[i]}\t{turnaround[i]}")
        total_waiting += waiting[i]
        total_turnaround += turnaround[i]

    avg_waiting = total_waiting / n
    avg_turnaround = total_turnaround / n

    print(f"\nAverage Waiting Time: {avg_waiting:.2f}")
    print(f"Average Turnaround Time: {avg_turnaround:.2f}")

    print("\nGantt Chart:")
    print("-" * (n * 10))
    for p in processes:
        print(f"|   P{p}   ", end="")
    print("|")
    print("-" * (n * 10))
    
    current_time = 0
    print(f"{current_time:<10}", end="")
    for i in range(n):
        current_time += burst[i]
        print(f"{current_time:<10}", end="")
    print("\n")


if __name__ == "__main__":
    main()
