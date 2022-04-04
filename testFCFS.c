#include<stdio.h>
#include<stdlib.h>

//1-  Input the processes along with their burst time (bt) & arrival time (at).
int main(){
    
    int processes[] = {'a', 'b', 'c'};

    int numOfProcess = sizeof processes / sizeof processes[0];
    float bt[] = {5, 9, 6};
    float at[] = {0, 3, 6};

    findWtAndTat(processes, numOfProcess, bt, at);

    return 0;
}

//2 Find waiting time (wt) for all processes.
//3 As first process that comes need not to wait so waiting time for process 1 will be 0 
//4 Find waiting time for all other processes
//5 Find turnaround time (tat)
void findWtAndTat(int process[], int numOfProcess, float bt[], float at[]){
    
    float serviceTime[numOfProcess], wt[numOfProcess], tat[numOfProcess], wasted, burst; 

    // set wt for first process as 0
    wt[0] = 0.0;
    serviceTime[0] = at[0];


    // index start from 1, since wt[0] is initialized
    for(int i = 1; i <= numOfProcess; i++){

        wasted = 0.0;
        
        //calculate total burst time for all process
        burst += bt[i - 1];

        //service time = total burst time + arrival time of process i
        serviceTime[i] = at[i - 1] + burst;

        //calculate wt = total burst time - arrival time of process[i]
        wt[i] = burst - at[i];

         /* if(wt[i] < 0){
            //to get positive wt[i]
            wasted = abs(wt[i]);
            printf("%5.2f", wasted);
            wt[i] = 0;
        } 

        serviceTime[i] = serviceTime[i] + wasted; */

        printf("QT[%d]: %8.2f\n", process[i - 1], serviceTime[i-1]);

        //calculate tat (index start from 0, so i - 1)
        tat[i - 1] = wt[i - 1] + bt[i - 1];

        /*Print the result*/
        //printf("BT[%d]: %8.2f\t", process[i - 1], bt[i-1]);
        //printf("WT[%d]: %8.2f\t", process[i - 1], wt[i-1]);
        //printf("TAT[%d]: %8.2f\n", process[i - 1], tat[i-1]);
    }

    // a function to print the result
    printResult(process, numOfProcess, at, bt, wt, tat);
}

void printResult(int process[], int numOfProcess, float at[], float bt[], float wt[], float tat[]){
    
    printf("|Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time|\n");

    for(int i = 0; i < numOfProcess; i++){

       for(int j = 0; j < 60; j++){
            printf("-");
        }

        printf("\n");

        printf("|     %d    | %8.2f   | %8.2f   | %8.2f     |   %8.2f     |\n", process[i], at[i], bt[i], wt[i], tat[i]);
    }
}

