#include <iostream>

using namespace std;

void my_print();

int main()
{
    while(true) my_print();
    return 0;
}


void my_print()
{
    int a;
    cin>>a;
    if(a>0)
        cout<<a<<endl;
    else cout<<a*-1<<endl;
}
