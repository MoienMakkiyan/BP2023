#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    string file_name;
    cin>>file_name;

    int shift;
    cin>>shift;
    shift%=26;

    ifstream input;
    ofstream output;

    input.open(file_name.c_str(),ios::in);

    file_name=file_name.substr(0,file_name.size()-4)+"_encoded.txt";
    output.open(file_name.c_str(),ios::out);

    string d;

    while(getline(input,d))
    {
        for(int i=0;i<d.length();i++)
        {
            if(64<d[i]&&d[i]<91)
            {
                if(d[i]+shift<91) d[i]+=shift;
                else d[i]+=(shift-26);
            }
            if(96<d[i]&&d[i]<123)
            {
                if(d[i]+shift<123) d[i]+=shift;
                else d[i]+=(shift-26);
            }
                //cout<<(char)d[i];
                output<<(char)d[i];
        }
        output<<endl;
        //cout<<endl;
    }
    input.close();
    output.close();
}

