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
      processes[i].processId = 10100 + i;//deletemw
      printf("Enter Arrival Time Of Process %i :", i+1);
      scanf("%i", &processes[i].arrivalTime);
      printf("Enter Burst Time Of Process %i: ", i+1);
      scanf("%i", &processes[i].burstTime);
//      processes[i].processId = 1010000 + i;//deletemw
   }
   //sorting/queueing proceses 
   for (int i = 0; i < numberOfProcesses; i++)
   {
      int n = 0;
      while ( n < numberOfProcesses)
      {
         if(processes[i].arrivalTime > processes[n].arrivalTime)
         {
            waitingQueue[i] = processes[n].processId;
         }
         n++;
      }
   }
   for (int i = 0; i < 5; i++){
   printf("wait %i = %ins\n", i,waitingQueue[i]);
   }
}

