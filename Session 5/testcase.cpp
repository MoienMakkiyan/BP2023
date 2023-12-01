    #include <iostream>
    #include <fstream>
    #include <bits/stdc++.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>

    using namespace std;


    string bin(int n,int m){
    string s="";
    while (n>=1){
        if (n%2==0)
            s='0'+s;
        else
            s='1'+s;
        n/=2;
    }
    while (s.size()!=m)
        s='0'+s;
    return s;
}

    int main()
    {

        ifstream input;
        ofstream output;

        //file_name=file_name.substr(0,file_name.size()-4)+"_encoded.txt";
        //output.open(file_name.c_str(),ios::out);
        string file_name;


        srand(time(0));//starting point
//        for(int K=1;K<21;K++)
//        {
//            int n = rand()%5+1;
//            n = pow(2,n);
//            int arr[n];
//            for(int l=0;l<n;l++)
//                arr[l]=rand();
//
//
//            file_name="input"+to_string(K)+".txt";
//            output.open(file_name.c_str(),ios::out);
//            for(int i =0 ; i<n ; i++)
//            {
//                output<<arr[i];
//                if(i!=n-1) output<<" ";
//            }
//
//            output.close();
//
//            file_name="output"+to_string(K)+".txt";
//            output.open(file_name.c_str(),ios::out);
//            sort(arr,arr+n);
//            for(int i =0 ; i<n ; i++)
//                output<<arr[i]<<" ";
//            output.close();
//        }

//        for(int K=21;K<41;K++)
//        {
//            int n = rand()%5+1;
//            n = pow(2,n);
//            int arr[n];
//            for(int l=0;l<n;l++)
//            {
//                arr[l]=rand();
//                if(rand()%2==0)
//                    arr[l]*=-1;
//            }
//
//
//
//            file_name="input"+to_string(K)+".txt";
//            output.open(file_name.c_str(),ios::out);
//            for(int i =0 ; i<n ; i++)
//            {
//                output<<arr[i];
//                if(i!=n-1) output<<" ";
//            }
//
//            output.close();
//
//            file_name="output"+to_string(K)+".txt";
//            output.open(file_name.c_str(),ios::out);
//            sort(arr,arr+n);
//            for(int i =0 ; i<n ; i++)
//                output<<arr[i]<<" ";
//            output.close();
//        }

         for(int K=1;K<51;K++)
        {
            int n = K-1;

            file_name="input"+to_string(K)+".txt";
            output.open(file_name.c_str(),ios::out);
            output<<n;

            output.close();

            int m,t=1,v;
            m=n;
            while (m--)
                t*=2;

            file_name="output"+to_string(K)+".txt";
            output.open(file_name.c_str(),ios::out);

            for (int i=t-1;i>=0;i--){
                v=0;
                output<<'{';
                for (int j=0;j<n;j++){
                    if (bin(i,n)[j]=='1' && v==1)
                        output<<' ';
                    if (bin(i,n)[j]=='1'){
                        v=1;
                        output<<j+1;
                    }
                }
                if (v==0)
                    output<<' ';
                output<<'}'<<endl;
            }
            output.close();
        }
    }



