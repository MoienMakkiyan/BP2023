#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;

    switch(n)
        {
            case 1: cout<<"Sat"<<endl;break;
            case 2: cout<<"Sun"<<endl;break;
            case 3: cout<<"Mon"<<endl;break;
            case 4: cout<<"Tus"<<endl;break;
            case 5: cout<<"Wed"<<endl;break;
            case 6: cout<<"Thu"<<endl;break;
            case 7: cout<<"Fri"<<endl;break;
            default: cout<<"Have a good time!!"<<endl;
        }
    return 0;
}
