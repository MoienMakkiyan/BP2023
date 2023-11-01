#include <iostream>

using namespace std;

int main()
{
    /*int a = 2;
    int b = 7;
    if(a==b)
    {
        cout<<"a is equal b"<<endl;
        //cout<<"a ="<<a<<"   b="<<b<<endl;
    }
    else {
        if(a>b)
    {
        cout<<"a is biger than b"<<endl;
    }
    else {
        cout<<"b is biger than a"<<endl;
    }
    }*/

    int a = 0;
    int b = 0;
    int c = 0;

    if(a>b){
        if(a>c){
            if(a*a==b*b+c*c) cout<<"Yes"<<endl;
            else{cout<<"No"<<endl;}
        }
        else {
            if(c*c==b*b+a*a) cout<<"Yes"<<endl;
            else{cout<<"No"<<endl;}
        }
    }
    else{
        if(b>c)
        {
            if(b*b==a*a+c*c) cout<<"Yes"<<endl;
            else{cout<<"No"<<endl;}
        }
        else{
            if(c*c==a*a+b*b) cout<<"Yes"<<endl;
            else{cout<<"No"<<endl;}
        }
    }

    return 0;
}
