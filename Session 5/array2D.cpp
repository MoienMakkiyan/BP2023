#include <iostream>
using namespace std;

//int n;
//void print_mat(char mat[][INT_MAX]);

int main()
{
    int n;
    cin>>n;
    char mat[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mat[i][j]=' ';

    bool exit = false;
    while(!exit)
    {
        int temp_x;
        int temp_y;

        cin>>temp_x>>temp_y;

        if(temp_x==-1||temp_y==-1)
            exit = true;
        else {
            mat[temp_x-1][temp_y-1]='#';
            //print_mat(mat);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<mat[i][j];
                cout<<endl;
            }
        }
    }
    return 0;
}

//void print_mat(char mat[][INT_MAX])
//{
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//            cout<<mat[i][j];
//        cout<<endl;
//    }
//}
