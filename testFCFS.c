#include<stdio.h>
#include<stdlib.h>

//1-  Input the processes along with their burst time (bt) & arrival time (at).
int main(){
    
    int processes[] = {'a', 'b', 'c', 'd', 'e'};

    int numOfProcess = sizeof processes / sizeof processes[0];
    float bt[] = {5, 4, 3, 2, 4};
    float at[] = {4, 6, 0, 6, 5};

    findWtAndTat(processes, numOfProcess, bt, at);

    return 0;
}

//2 Find waiting time (wt) for all processes.
//3 As first process that comes need not to wait so waiting time for process 1 will be 0 
//4 Find waiting time for all other processes
//5 Find turnaround time (tat)
void findWtAndTat(int process[], int numOfProcess, float bt[], float at[]){
    
    float serviceTime[numOfProcess], wt[numOfProcess], tat[numOfProcess], wasted, burst; 

    sortProcess(process, numOfProcess, bt, at);

    // set wt for first process as 0
    wt[0] = 0.0;
    serviceTime[0] = at[0];


    // index start from 1, since wt[0] is initialized
    for(int i = 1; i <= numOfProcess; i++){

        wasted = 0.0;
        

        //service time = summation of burst time for previous processes
        serviceTime[i] = serviceTime[i - 1] + bt[i - 1];

        //calculate wt = service time[i] - arrival time of process[i]
        wt[i] = serviceTime[i] - at[i];

        // Waiting is -ve if the process enter queue when CPU idles, waiting time = 0
        if(wt[i] < 0){
            //to get positive wt[i]
            wasted = abs(wt[i]);
            wt[i] = 0;
        } 

        // total burst time need to add the idle time to get the correct total time
        serviceTime[i] = serviceTime[i] + wasted;

        //calculate tat (index start from 0, so i - 1)
        tat[i - 1] = wt[i - 1] + bt[i - 1];

        /*Print the result*/
        printf("QT[%d]: %5.2f\t", process[i - 1], serviceTime[i-1]);
        printf("BT[%d]: %5.2f\t", process[i - 1], bt[i-1]);
        printf("WT[%d]: %5.2f\t", process[i - 1], wt[i-1]);
        printf("TAT[%d]: %5.2f\n", process[i - 1], tat[i-1]);
    }

    // a function to print the result
    printResult(process, numOfProcess, at, bt, wt, tat);
}

void sortProcess(int process[], int numOfProcess, float bt[], float at[]){

    float tempBT, tempAT;
    int tempProcess;

    for(int i = 0; i < numOfProcess - 1; i++){
        for(int j = i + 1; j < numOfProcess; j++){

            if(at[i] == at[j]){
                if(process[i] > process[j]){
                    tempAT = at[i];
                    at[i] = at[j];
                    at[j] = tempAT;

                    tempBT = bt[i];
                    bt[i] = bt[j];
                    bt[j] = tempBT;

                    tempProcess = process[i];
                    process[i] = process[j];
                    process[j] = tempProcess;
                }
            }
            
            if(at[i] > at[j]){
            tempAT = at[i];
            at[i] = at[j];
            at[j] = tempAT;

            tempBT = bt[i];
            bt[i] = bt[j];
            bt[j] = tempBT;

            tempProcess = process[i];
            process[i] = process[j];
            process[j] = tempProcess;

           /*  for(int k = 0; k < numOfProcess; k++){
                printf("%d %2.2f\n", process[k], at[k]);
            } */
        }

        }

       
    }
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

