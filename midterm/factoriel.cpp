#include<iostream>

using namespace std;

int fact(int a);

int main()
{
    int a; cin>>a;
    cout<<fact(a)<<endl;

    return 0;
}


int fact(int a)
{
    if(a==1) {
        return 1;
    }
    else {
        return a*fact(a-1);
    }
}
