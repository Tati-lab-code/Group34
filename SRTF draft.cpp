#include<iostream>
using namespace std;
struct Process
{
    int burstTime;
    int remainingTime;
    int arrivalTime;
    //int waitingTime; not sure if it should be apart of the struct..
    bool isCompleted = false;

};
const int max = 100;//the max number of processes in the system
Process process[3]= 
{ {2,5,7,},{3,4,5},{1,3,5} };
int currentTime = 0;//to act as time in seconds
int completedProcess=0;//track of number of complete processes
void scheduling (Process process[],int n)
{
    while (completedProcess < n)
    {
       //Finding the process with the shortest remaining time.. I hope
       int shortestBurst = INT_MAX;//How long the shortest burst is
       int shortestProcessIndex;//to keep track of the shortest process(its dynamic)
       for ( int i =0; i<n; i++)
       {
        if(process[i].arrivalTime == currentTime && process[i].isCompleted == false)
        {//now we have narrowed down to all processes eligible to be executed
           if(process[i].remainingTime < shortestBurst)
           {
            //Now we narrow it down again to deal with the process' remaining time,
            // at the begining, remainingTime == BurstTime kaili nothing has been executed
            shortestBurst = process[i].remainingTime;
            shortestProcessIndex = i;  // so that we know which process exactly has the shortest process
            process[i].remainingTime = process[i].remainingTime - 1;// "THE EXECUTION"
            currentTime++;
           }
        }
        else
        { 
            //many processes with the same remaining time? FCFS
            if(process[i].remainingTime == shortestBurst && process[i].arrivalTime < process[shortestBurst].arrivalTime)
            {
                process[i].remainingTime = process[i].remainingTime - 1;
                //priority goes to who came first
                currentTime++;
            }
        }
       }
    }
}