#include<iostream>

using namespace std;
void put_two(int *a);

int main()
{
    int x = 5;
    put_two(&x);
    cout<<x<<endl;

    return 0;
}

void put_two(int *a)
{
    *a += 2;
}
