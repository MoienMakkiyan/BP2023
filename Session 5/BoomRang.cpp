#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int m; cin>>m;

    char mat[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            mat[i][j]=' ';

    bool exit = false;
    while(!exit)
    {
        int type;
        int num;
        char m_char;

        cin>>type>>num>>m_char;

        if(type==0)
            exit = true;
        else {
            if(type==1){
                for(int j=0;j<m;j++)
                    mat[num-1][j]=m_char;
            }
            else if(type==2){
                for(int i=0;i<n;i++)
                    mat[i][num-1]=m_char;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout<<mat[i][j];
                cout<<endl;
            }
        }
    }
    return 0;
}
