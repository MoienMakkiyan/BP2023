#include<iostream>

using namespace std;

int x = 5;//global varible

void print_number();


int main()
{
    int a = 5;
    for(int i=1;i<=20;i++)
        print_number();
    return 0;
}


void print_number()
{
    static int counter = 0;
    counter++;
    int b = 3;
    for(int i=1;i<=10;i++)
        cout<<i*b*x<<endl;
    cout<<"COUNTER = "<<counter<<endl;
}
