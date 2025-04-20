#include<stdio.h>
int main()
{
    int x, y, result=0, choice;
    printf("Enter any number: ");
    scanf("%i", &x);
    printf("Enter another number: ");
    scanf("%i", &y);
    printf("Do you want to \n1. Add\n2. Subtract\n3. Divide\n4. Multiply\n5. Find the remainder: ");
    scanf("%i", &choice);
    if(choice==1)
    {
        result=x+y;
        printf("%i", result);
        printf("\n");
    }
    else if(choice==2)
    {
        result=x-y;
        printf("%i", result);
        printf("\n");
    }
    else if(choice==3 && y!=0)
    {
        result=x/y;
        printf("%i", result);
        printf("\n");
    }
    else if(choice==4)
    {
        result=x*y;
        printf("%i", result);
        printf("\n");
    }
    else if(choice==5)
    {
        result=x%y;
        printf("%i", result);
        printf("\n");
    }
    else
    {
        printf("Invalid option");
        printf("\n");
    }
    printf("The lecturer said, \"I love C 100%\"");
}
