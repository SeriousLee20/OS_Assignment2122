#include<stdio.h>
#include<stdlib.h>

//shortest job first
void main() {
    
    //sample input
    int bt[] = {5, 4, 3, 2, 4};
    int numOfProcess = sizeof bt / sizeof bt[0];
    int process[numOfProcess], wt[numOfProcess], tat[numOfProcess];
    
    //process id
    for (int i = 0; i< numOfProcess; i++) {
        printf("P%d burst time\t: %d\n",i+1, bt[i]);
        process[i] = i+1;
    }
    
    //1. selection sort burst time ascending order
    for (int i = 0; i< numOfProcess; i++) {
        int position = i;
        for (int j = i+1; j < numOfProcess-1; j++) {
            if (bt[j] < bt[position]) {
                position = j;
            }
        }
        int temp = bt[i];
        bt[i] = bt[position];
        bt[position] = temp;
        
        temp = process[i];
        process[i] = process[position];
        process[position] = temp;
    }
    
    //2. calculate waiting time
    wt[0] = 0; //first process waiting time = 0
    int wtSum = 0; //total waiting time
    for (int i = 1; i < numOfProcess; i++) {
        wt[i] = 0;
        for (int j = 0; j <i ; j++) {
            wt[i] += bt[j];
        }
        wtSum += wt[i];
    }
    float avg_wt = (float) wtSum / numOfProcess; // average waiting time
    
    //3. calculate turnaround time
    int tatSum = 0;
    printf("\n|Process ID\t|Burst Time\t|Waiting Time\t| Turnaround Time\t|");
    for (int i = 0; i< numOfProcess; i++) {
        tat[i] = bt[i] + wt[i]; //calculate turnaround time
        tatSum += tat[i];
        printf("\n| P%d\t\t|\t%d\t\t|\t%d\t\t\t|\t%d\t\t\t\t|", process[i], bt[i], wt[i], tat[i]);
    }
    float avg_tat = (float) tatSum / numOfProcess; //average turnaround time
    printf("\n\nAverage Waiting Time\t= %f",avg_wt);
    printf("\nAverage Turnaround Time\t= %f\n",avg_tat);
}