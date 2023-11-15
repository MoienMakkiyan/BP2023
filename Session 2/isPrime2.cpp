#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int a);

int main()
{
    int n = 49;
    if(isPrime(n)&&n!=1)
        cout<<"This number is Prime :))"<<endl;
    else
        cout<<"Please try again!"<<endl;

    return 0;
}

/*
bool isPrime(int a)
{
    for(int i=2;i<a;i++)
    {
        if(a%i==0) return false;
    }
    return true;
}
*/

bool isPrime(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) return false;
    }
    return true;
}

