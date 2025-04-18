/*
***Congratulations***
You've managed to clone a repo (repository).
Now let's learn about The C programming Language

First of all C is similar to C++.
with that being said, Let's compare the basic diffences


Basic Concept                    C                                                       C++
I/O header file         <stdio.h>                                               <iostream>
Printing to screen      printf("String/FormatSpecifier",OutputVariable);        cout<<"String"<<OutputVariable;
User input              cin>>InputVariable;                                     scanf("formatSpecifier",&InputVariable);
...                     getline(cin,inputVariable);                             fgets(buffer,n,stream);

Let's look at some example
*/

#include <stdio.h>
int main(void)
{
   //printing to the screen
   printf("Hello, Mate\n");

   //getting and printing user input
   char*name;
   printf("What's your name?\n: ");
   scanf("%s", name);
   printf("Hello, %s\n",name);
   return 0;
}

/*
In case you're wondering: The main function is still the same one we use in C++. I just like explicitly declaring that it's void

Note that in order to print the content of a variable or pass user input, we used a format specifier
to get the input data.
%s is an example of a format specifier
What Are Format Specifiers?
These are special characters that tell the compiler where and what type of data to display.
Here are some of the common formt specifies with their datatypes

%i       - int
%c       - char
%d       - double or float
%f       - float
%l       - long
%lf      - double
%s       - string
%ld      - long
...you can look up the rest

This is one of the reasons why people say "C IS HARD", we specify the type of data that the
program should use, therefore, it is important that you understand format specifiers.

*/

/* delete this comment (from line 56 to line 77) to see the example's output
//Format Specifier Examples
#include <stdio.h>
int main(void)
{
   char Character = '7';
   int Integer = 72;
   double DoubleNumber = 2.23606796666666666666666666666;
   float FloatNumber = 2.23606796666666666666666666666;
   long LongNumber = 2.23606796666666666666666666666;

   printf("Character value = %c\n",Character);
   printf("Integer value = %i\n",Integer);
   printf("Double value = %f\n",DoubleNumber);
   printf("Float value = %f\n",FloatNumber);
   printf("Long value = %ld\n",LongNumber);

   //Note if we use %c for an int, we get the correspomding ascii Character
   printf("Interger: %c\n",Integer);
   printf("Character: %i\n",Integer);
   
   Now you see why it is important to know format specifiers?
   As much as you can swap them for int and char, the other datatypes will give errors
   if you use the wrong format specifiers.
   Have you also noticed that the new line escape character "\n" has made our code look sophisticated?
   It is another reason why people say C is hard because, the use of special characters makes our code look complex. As a result,
   it becomes hard to understant, expecially when dealing with complex systems involving complex datatypes (e.g pointers) 
}
*/

/*
Exercise
1.Create a calculator that does the following five operations on two numbers.
The numbers must be provided by the user.
#.add
#.subtract
#.divide
#.multiply
#.give remainder

2. Print the statement below to the screen
   The lecturer said "I love C 100%".

***Submit Via github to the repository ***
*/
