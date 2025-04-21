#include<stdio.h>
int main()
{
    double number, number1,sum,differnce,product;
    char sign;

    
    printf("Enter the symbol of the operation you'd like to use\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Remainder (%%)\n");
    scanf("%c", &sign);


    printf("Enter first number\n");
    scanf("%d", &number);
    //printf("%d", number);
    printf("Enter second number\n");
     scanf("%d", &number1);
   // printf("%d", &number1);


   if(sign == '+'|| sign == '-'|| sign == '*'|| sign == '/'|| sign == '%')
   {
    switch(sign)
    {
        case '+': 
        printf("The sum of your numbers is : %d\n", number+number1);
        break;
        case '-': 
        printf("The difference of your numbers is :%d\n",number-number1);
        break;
        case '*':
        printf("The product of your numbers is :%d\n ",number*number1);
        break;
        case '/':
        printf("The quotent of your numbers is :%d\n",number/number1);
        break;
        case '%':
        int num = (int)number;//typecasting double into integer
        int num1 = (int)number1;
        printf("The remainder of the quotent is : ",num%num1);
        break;
    }
   }
   else 
   {
    printf("Invalid Entry\n");
   }

    printf("The lecturer said I love C 100%%");

}