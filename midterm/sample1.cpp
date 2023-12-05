//برنامه ای بنویسید که به طور پیوسته اسامی افراد را دریافت کند و زمانی که اسمی با حرف m شروع شد، برنامه را متوقف کند.

#include<iostream>

using namespace std;

int main()
{
    while(1)
    {
        char input;
        cin>>input;
        if(input=='m'||input=='M')
        {
            cout<<"Name Found!"<<endl;
            break;
        }
    }
    return 0;
}
