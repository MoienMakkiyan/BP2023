#include<iostream>

using namespace std;

int my_sum(int a, int b);

int main()
{
    int a = 9999;
    //b = 12;

    cout<<my_sum(1,2)<<endl;
    return 0;
}


int my_sum(int a, int b)
{
    return a+b;
}
