#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int a);

int main()
{
    int n = 0;

    while(n!=1)
    {
        cin>>n;
        if(isPrime(n)&&n!=1)
            cout<<"This number is Prime :))"<<endl;
        else
            cout<<"Please try again!"<<endl;

    }
    return 0;
}

bool isPrime(int a)
{
    for(int i=2;i<a;i++)
    {
        if(a%i==0) return false;
    }
    return true;
}

/*
bool isPrime(int a)
{
    for(int i=2;i<sqrt(a);i++)
    {
        if(a%i==0) return false;
    }
    return true;
}
*/

/*bool isPrime(int a)
{
    int temp = 0;
    bool ans;

    for(int i=2;i<a;i++)
    {
        if(a%i==0) temp++;
    }

    if(temp==0) ans = true;
    else ans = false;

    return ans;
}
*/
