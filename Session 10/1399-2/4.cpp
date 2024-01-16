#include <iostream>
#include <string>
using namespace std;

void func(int,string,string,string );
int main()
{
    int n;
    cin>>n;
    string s1,s2,s3;
    
    cin.get();
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);

	func(n,s1,s2,s3);
	
    return 0;
}

void func(int n, string s1,string s2,string s3)
{
    if(n == 1)
    {
            cout<<"\nmove disk 1 from "<<s1<<" to "<<s3;
    }
    else
    {
        func(n-1,s1,s3,s2);
        cout<<"\nmove disk "<<n<<" from "<<s1<<" to "<<s3;
        func(n-1,s2,s1,s3);
    }
}