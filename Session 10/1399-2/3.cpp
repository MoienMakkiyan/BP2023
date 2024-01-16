#include <iostream>

using namespace std;

bool horizental(int n,int numbers[]);
bool vertical(int n,int numbers[]);

int main()
{
    int n;
    cin>>n;
    bool threat=false;
    int numbers[n][n],num_hor[n],num_ver[n],num_obl[n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>numbers[i][j];

    for(int i=0; i<n && !threat; i++){
        for(int j=0; j<n && !threat; j++){
            if(numbers[i][j]==1){

                for(int k=0; k<n; k++)
                    num_hor[k]=numbers[i][k];
                for(int k=0; k<n; k++)
                    num_ver[k]=numbers[k][j];

                int ii,jj;
                int k=0;
                ii=i-1;
                jj=j-1;
                while((ii>=0)&&(jj>=0))
                    k+=numbers[ii--][jj--];
                ii=i-1;
                jj=j+1;
                while((ii>=0)&&(jj<n))
                k+=numbers[ii--][jj++];
                ii=i+1;
                jj=j+1;
                while((ii<n)&&(jj<n))
                    k+=numbers[ii++][jj++];
                ii=i+1;
                jj=j-1;
                while((ii<n)&&(jj>=0))
                    k+=numbers[ii++][jj--];
                if(k>=1)
                    threat = true;
                if(threat)
                    break;

                threat = horizental(n,num_hor);
                if(threat)
                    break;
                threat = vertical(n,num_ver);
                if(threat)
                    break;
            }
        }
    }
    if(threat)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}

bool horizental(int n,int numbers[]){
    int cnt=0;
    for(int k=0; k<n; k++){
        if(numbers[k]==1)
            cnt++;
    }
    if(cnt>=2)
        return true;
    return false;
}

bool vertical(int n,int numbers[]){
    int cnt=0;
    for(int k=0; k<n; k++){
        if(numbers[k]==1)
            cnt++;
    }
    if(cnt>=2)
        return true;
    return false;
}
