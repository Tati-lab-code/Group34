#include <stdio.h>

//process structure
typedef struct
{
   int processId,
       arrivalTime,
       burstTime;
}process;

process processes[70];

int main(void)
{
   //Variable Declaration
   int numberOfProcesses = 0,
       waitingTime[numberOfProcesses],
       waitingQueue[numberOfProcesses],
       completionTime[numberOfProcesses],
       turnAroundTime[numberOfProcesses],
       averageTurnAroundTime,
       runTime;
   //Process Creation
   printf("Enter number of Processes to Execute: ");
   scanf("%i",&numberOfProcesses);
   for (int i = 0; i < numberOfProcesses; i++)
   {
      printf("Enter Arrival Time Of Process %i :", i+1);
      scanf("%i", &processes[i].arrivalTime);
      printf("Enter Burst Time Of Process %i: ", i+1);
      scanf("%i", &processes[i].burstTime);
   }
   //sorting/queueing proceses 
 
}

