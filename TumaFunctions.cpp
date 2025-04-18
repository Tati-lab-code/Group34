#include<iostream>
using namespace std;
void menu();
float product(float, float);
int main()
{
    //menu();
    cout<<product(4, 4);
}
void menu()
{
    cout<<"Pick a choice:\n1. Add record\n2. Search record\n3. Delete record\n4. Exit\n";
}
float product(float a, float b)
{
   // cout<<"Enter two numbers of your choice separated by a space: ";
    //cin>>a>>b;
    float product=a*b;
    return product;
}
