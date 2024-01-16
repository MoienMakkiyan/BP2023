#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string counting(string name);
int main()
{
    int L,i;
    string mystr;
    cin>>mystr;
    mystr=counting(mystr);
    L=mystr.length();
    for(i=0; i<L; i++)
        cout<<mystr[L-i-1];
}
string counting(string name)
{
    string newname="";
    int L=name.length();
    int cnt=1,flag=0;
    for(int i=1; i<=L; i++)
    {
        if(name[i]==name[i-1])
        {
            cnt++;
            if(cnt>15)
            {
                newname+=name[i-1];
                newname+="f";
                cnt=1;
            }
        }
        else
        {
            newname+=name[i-1];
            if(cnt<10)
                newname+=to_string(cnt);
            else
            {
                switch(cnt)
                {
                case 10:
                    newname+="a";
                    break;
                case 11:
                    newname+="b";
                    break;
                case 12:
                    newname+="c";
                    break;
                case 13:
                    newname+="d";
                    break;
                case 14:
                    newname+="e";
                    break;
                case 15:
                    newname+="f";
                    break;
                }
            }
            cnt=1;
        }
    }
    return newname;
}
