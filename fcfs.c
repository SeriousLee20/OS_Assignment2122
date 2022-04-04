#include<stdio.h>

//1-  Input the processes along with their burst time (bt).
int main(){
    
    int processes[] = {'a', 'b', 'c'};

    int numOfProcess = sizeof processes / sizeof processes[0];
    float bt[] = {4, 9, 5};

    findWtAndTat(processes, numOfProcess, bt);

    return 0;
}

void findWtAndTat(int process[], int numOfProcess, float bt[]){
    
    float wt[numOfProcess], tat[numOfProcess]; 

    // set wt for first process as 0
    wt[0] = 0.0;


    // index start from 1, since wt[0] is initialized
    // index end at numOfProcess to get wt of last process (i.e. numOfProcess - 1)
    for(int i = 1; i <= numOfProcess; i++){

        //calculate wt
        wt[i] += bt[i - 1] + wt[i - 1];

        //calculate tat (index start from 0, so i - 1)
        tat[i-1] += wt[i - 1] + bt[i - 1];
    }

    // a function to print the result
    printResult(process, numOfProcess, bt, wt, tat);
}

void printResult(int process[], int numOfProcess, float bt[], float wt[], float tat[]){
    
    printf("|Process ID | Burst Time | Waiting Time | Turnaround Time|\n");

    for(int i = 0; i < numOfProcess; i++){

       for(int j = 0; j < 60; j++){
            printf("-");
        }

        printf("\n");

        printf("|     %d    | %8.2f   | %8.2f     |   %8.2f     |\n", process[i], bt[i], wt[i], tat[i]);
    }
}
