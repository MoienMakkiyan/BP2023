#include<iostream>

using namespace std;

int main()
{
    string name;
    cin>>name;

    ///myString.insert(position, "new");
    name.insert(0,"New Member = ");
    cout<<name<<endl;
    return 0;
}
