#include<iostream>

using namespace std;

int main()
{
    string input;
    cin>>input;

    int k; cin>>k;

    ///تضمین میشود که ورودی 0 نداریم
    int sum[9]={0,0,0,0,0,0,0,0,0};

    for(int i=0;i<input.length();i++)
    {
        sum[(int)input[i]-48]++;
    }

    bool hasAns = true;

    for(int i=0;i<sizeof(sum)/4;i++)
    {
        if(sum[i]%k!=0)
        {
            hasAns = false;
            break;
        }
    }

    if(hasAns)
    {
        int output = 0;
        for(int i=0;i<sizeof(sum)/4;i++)
        {
            for(int j=0;j<sum[i]/k;j++)
                if(sum[i]!=0)
                {
                    output*=10;
                    output+=i;
                }
        }
        cout<<output<<endl;
    }
    else cout<<"-1"<<endl;

    return 0;
}
