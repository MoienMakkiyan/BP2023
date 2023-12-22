#include<iostream>

using namespace std;

int main()
{
    string DNA;
    cin>>DNA; ///ACGTCACGTACGTGTACGCATGATGCATGCTTCAGAGCT

    for(int i=0;i<DNA.length();i++)
    {
        ///string substr = myString.substr(startIndex, length);
        //string temp = DNA.substr(i,4);
        //string temp = DNA.substr(i);
        string temp = DNA.substr(i,4); i+=3;
        ///TODO....
        cout<<temp<<endl;
    }
    return 0;
}
