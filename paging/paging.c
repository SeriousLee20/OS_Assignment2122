#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

int main(){

    int memorySize, pageSize, numOfPage, numOfProcess, pageNum, offset, phyAddress, freePage, page, process;
    
    int pmt[50][20];
    int ramSize = 64;
    int occupiedFrame[64];
    

    printf("\n\n");

    /* Initialize memory size, page size */
    printf("Enter memory size (KB): ");
    scanf("%d", &memorySize);

    printf("Enter size of pages (KB): ");
    scanf("%d", &pageSize);

    numOfPage = memorySize / pageSize;
    freePage = numOfPage;

    printf("Number of pages available: %d\n", freePage);

    /* Get number of process need to allocate */
    printf("Enter number of jobs to be allocated: ");
    scanf("%d", &numOfProcess);

    int n = numOfProcess;
    int *jobTable = calloc(numOfProcess, sizeof(int));
    int *totalRow = calloc(numOfProcess, sizeof(int));

    /* Get the size of each process
    
     * Allocate each page to a frame
     */
    for(int i = 0; i < numOfProcess; i++){

        // Print number of free pages in virtual memory
        printf("\nNumber of free page: %d\n", freePage);

        // Input size of the process
        printf("Enter number of pages required by process %d: ", i + 1);
        scanf("%d", &jobTable[i]);

        // check if the pages required is enough in virtual memory
        if(jobTable[i] > freePage){
            printf("Memory is full! Please go to next process.\n");
            continue;
        }

        freePage -= jobTable[i];
        

        printf("Please enter page table for process %d\n", i);
        printf("Page Number     Frame Number\n");

        // allocate each page a frame
        for(int j = 0; j < jobTable[i]; j++){

            int temp;

            printf("%d\t\t", j);

            // input frame number for the page
            scanf("%d", &temp);

            // if the frame is out of range, re-enter the frame
            while(temp >= ramSize / pageSize){
                printf("Frame not exist. Please choose another frame: ");
                scanf("%d", &temp);
            }
            
            pmt[i][j] = temp;

        }

    }

    printf("\n------------ Current Page Table -------------\n");
    printf("Process     Page Number     Frame Number\n");

    // Print the filled page table
    for(int i = 0; i < numOfProcess; i++){
        for(int j = 0; j < jobTable[i]; j++){
            
            printf("%d\t\t%d\t\t%d\n", i, j, pmt[i][j]);
        }
    }


    printf("Enter Logical Address to find Physical Address\n");
    printf("Process Number     Page Number      Offset\n");


    scanf("%d\t%d\t%d", &process, &page, &offset);

    // search for the physical address of an instruction
    if(process > numOfProcess){
        printf("Invalid process");
    }
    else if (page >= jobTable[process]){
        printf("Invalid page");
    }else if(offset >= pageSize){
        printf("Invalid offset.");
    }else{
        phyAddress = (pmt[process][page]*pageSize + offset);
        printf("Physical Address: %d", phyAddress);
    }


    return 0;
}

