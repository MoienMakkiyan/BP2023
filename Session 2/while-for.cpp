#include<iostream>

using namespace std;

int main()
{
    /*
    ///while
    int a = 0;
    int b = 0;
    while (a<=1000)
    {
        cout<<"a = "<<a++<<"\n";
        cout<<"b = "<<++b<<endl;
    }
    return 0;
    */

    //while(true)
    //{
    //    cout<<"CPP is best!!"<<endl;
    //}

    ///int - double - float - bool
    //bool a = true;
    //cout<<a<<endl;

    /*int n=-1;
    while(n!=0)
    {
        cin>>n;
        if(n==0)
            {
                continue;
            }
        else {
                cout<<n%7<<endl;
        }
    }
    */

    /*
    int n=-1;
    bool exit = false;
    while(!exit)
    {
        //cout<<"!!!!"<<endl;

        cin>>n;
        if(n==0)
            {
                exit = true;
                //cout<<"@";
            }
        else {
                cout<<n%7<<endl;
                //cout<<"%";
        }
        //cout<<"&&";
    }
    */

    /*
    int a = 0;
    while(true)
    {
        cin>>a;
        if(a%5==0)
        {
            break;
            //continue;
            //return 0;
        }
        else {
            cout<<"Try again!!!!!"<<endl;
        }
        cout<<"Wellllll"<<endl;
    }
    */

    /*int i=0;
    while(i<10)
    {
        ///TODO
        i++;
    }

    for(int i=0;i<10;i++){

    }
    */

    /*
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<(i+1)*(j+1)<<"\t";
        }
        cout<<"\n";
        //cout<<j<<endl;
    }

    */


    int n;
    cin>>n;

    for(int i=0,j=0;i<n&&j<n;i++,j+=2)
    {
        cout<<(i+1)*(j+1)<<"\t";
    }



    /*
    int n = -1;

    while(n!=0||n%11!=0)
    {
        cin>>n;
        cout<<"Hey Guys"<<endl;
    }

    */

    //int n,m,k,x,y,z;
    //cout<<n<<endl<<m<<endl<<k<<endl<<x<<endl<<y<<endl<<z<<endl;


}
