#include<iostream>
#include<fstream>
#include<string>
#include<strstream>
long long int tavan(int n){
    int i=0;
    long long int x=1;
    for(;i<n;i++)   x=x*6;
    return x;
}

using namespace std;
int main(){
    long int n,i;
    long long int m,s,j;
    cin>>n>>m;
     int x[n];
    for(j=0,i=n-1;i>=0;i--,j++){
        if (m>=tavan(i)){
        if (i==0)   x[i]=m;
        else{
        if (m%tavan(i)==0){
                x[i]=m/tavan(i);
                m=tavan(i);
        }
        else{
            x[i]=m/tavan(i)+1;
            m=m%tavan(i);
        } }
    }
    else    x[i]=1;
    }
    for(i=0;i<n;i++) cout<<x[n-i-1];
    return 0;
}
