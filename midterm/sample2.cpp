#include<iostream>

using namespace std;

bool isPrime(int x);

int main()
{
    int a;
    cin>>a;

    if(isPrime(a)) cout<<"This number is Prime!"<<endl;
    else cout<<"I like CPP"<<endl;
    return 0;
}


bool isPrime(int x)
{
    bool counter = false;
    for(int i=2;i<=x/2;i++)
    {
        if(x%i==0)
        {
            counter=true;
            break;
        }
    }
    return !counter;
}
