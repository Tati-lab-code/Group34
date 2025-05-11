#include <stdio.h>

//process structure
typedef struct
{
   int ID,
       arrivalTime,
       burstTime;
}process;

void execute(int);
int createProcess();
void sortProcesses(int);
void printProcesses(process* ,int);
void executeProcess(process* , int);
int checkArrivalTime(process*, int, int);
int compareBurstTime(process*, int);

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
       sortprocess,
       runTime;
   //Process Creation || New State
   numberOfProcesses = createProcess();
   //sorting/queueing proceses || Ready State
   sortProcesses(numberOfProcesses);
   printProcesses(processes,numberOfProcesses);
   //Process execution || Execute State
   int At, Bt;
   At = checkArrivalTime(processes,numberOfProcesses, 0);
   Bt = compareBurstTime(processes,At);
   printf("Number of Processes with same arrival time:%i\nShortest BurstTime time: %i\n",At,processes[Bt].burstTime);
   execute(numberOfProcesses);
}

int createProcess()
{
   int numberOfProcesses;
   printf("Enter number of Processes to Execute: ");
   scanf("%i",&numberOfProcesses);
   for (int i = 0; i < numberOfProcesses; i++)
   {
      processes[i].ID = 10100 + i;//deletemw
      printf("Enter Arrival Time Of Process %i :", i+1);
      scanf("%i", &processes[i].arrivalTime);
      printf("Enter Burst Time Of Process %i: ", i+1);
      scanf("%i", &processes[i].burstTime);
   }
   return numberOfProcesses;
}
void sortProcesses(int n)
{
   process sort;
   for (int i = 0; i < n; i++)
   {
      int minIndex = i;
      for (int j = i+1; j < n; j++)
      {
         if (processes[j].arrivalTime < processes[minIndex].arrivalTime)
         {
            minIndex = j;
         }
      }
      sort.arrivalTime = processes[i].arrivalTime;
      sort.ID = processes[i].ID;
      sort.burstTime = processes[i].burstTime;

      processes[i].ID = processes[minIndex].ID;
      processes[i].arrivalTime = processes[minIndex].arrivalTime;
      processes[i].burstTime = processes[minIndex].burstTime;

      processes[minIndex].ID = sort.ID;
      processes[minIndex].arrivalTime = sort.arrivalTime;
      processes[minIndex].burstTime = sort.burstTime;

   }
}

void printProcesses(process thisOne[], int n)
{
   printf("PID\tAT\tBT\n");
   for (int i = 0; i < n; i++)
   {
      printf("%i\t%i\t%i\n",thisOne[i].ID ,thisOne[i].arrivalTime, thisOne[i].burstTime);
   }
}
/*
void executeProcess(process execute[], int n)
{
   process wait[n];
   int executionTime, remainingTime, time = 0;
   for(int i = 0; i < n; i++)
   {
      executionTime  = execute[i].burstTime - execute[i].arrivalTime;
      while( time <= executionTime)
      {
         if (execute[i+1].arrivalTime == executionTime)
         {
            if (execute[i+1].burstTime < executionTime)
            {
               //send current process to wait
               wait[i].ID = execute[i].ID;
               wait[i].arrivalTime = execute[i].arrivalTime;
               wait[i].burstTime = execute[i].burstTime;
               remainingTime[i] = execute[i].burstTime - executionTime[i];
               ///execute next process;
               executionTime = execute[i+1].burstTime - execute[i+1].arrivalTime;
            }
         }
         time++;
      }
   }
}
*/
int checkArrivalTime(process P[], int n, int AT)
{
   int counter = 0;
   for(int i = 0; i < n; i++)
   {
      if (P[i].arrivalTime == AT)
      {
         counter++;
      }
   }
   return counter;
}

int compareBurstTime(process P[], int n)
{
   int first = 0;
   for (int h = 0; h <= 3; h++)
   {
      for (int i = 0; i <= n; i++)
      {
         if (P[i].burstTime < P[first].burstTime)
         {
            first = i;
         }
      }
   }
   return first;
}

void execute(int numberOfProcesses)
{
    //dbTool
        printf("Woo\n");
   int currentTime = 0, completedProcess = 0, remainingProcesses = 0, sameArrivalTime, exe = 0,
       completionTime[numberOfProcesses];
   while (completedProcess < numberOfProcesses)
   {
       //dbTool
       printf("woo1\n");
//execute first process
      //find number of remaining processes
      remainingProcesses = numberOfProcesses - completedProcess;
      printf("woo 1.35\n");
      //check for currenrt processes with same arrival time
      sameArrivalTime = checkArrivalTime(&processes[numberOfProcesses], remainingProcesses,currentTime);
      printf("woo 1.75");
      //choose which pocesss to execute first
      if (sameArrivalTime > 0)
      {
         exe = compareBurstTime(processes, remainingProcesses);
        // remainintTime[exe] = processes[exe].burstTime - 1;
        printf("Woo2\n");
      }
      if (currentTime == 0 && processes[exe].burstTime > 0)
      {
         processes[exe].burstTime = processes[exe].burstTime - 1;
         //db tools
         printf("at T = %i, Process %i was executed. remaining time = %i", currentTime, processes[exe].ID, processes[exe].burstTime);
      }//
      else
      {
         //check for least burstTime
         int least;
         for (int i = 0; i < remainingProcesses ; i++)
         {
            for (int h = 0; h < remainingProcesses; h++)
            {
               if( processes[h].burstTime < processes[i].burstTime && (processes[i].burstTime > 0 || processes[h].burstTime))
               {
                  least = h;
               }
            }
         }
         if (processes[least].burstTime < processes[exe].burstTime)
         {
            processes[least].burstTime = processes[least].burstTime - 1;
            //db tools
            printf("at T = %i, Process %i was executed. remaining time = %i", currentTime, processes[least].ID, processes[exe].burstTime);

         }
         else if (processes[exe].burstTime > 0)
         {
            processes[exe].burstTime = processes[exe].burstTime - 1;
            //db Tools
         }
      }//
      //check If processes are complete
      if (processes[exe].burstTime == 0)
      {
         completedProcess++;
         completionTime[exe] = currentTime;
      }
      currentTime++;
   }
}
