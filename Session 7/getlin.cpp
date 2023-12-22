#include<iostream>

using namespace std;

int main()
{
    string name;
    string last_name;

    cout<<"Please Enter your Name in a single line :"<<endl;
    getline(cin,name);

    cout<<"Please Enter your Last Name in a single line :"<<endl;
    getline(cin,last_name);

    string full_name = name+" "+last_name;

    cout<<full_name<<endl;

    return 0;
}

