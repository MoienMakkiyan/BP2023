#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


void inputHugeInt(short int a[]);
void printHugeInt(short int a[]);
void reverseHugeInt(short int a[]);
unsigned short int lengthHugeInt(short int a[]);
void addHugeInt(short int a[],short int b[],short int c[], bool reversed=false);
void mulHugeInt(short int a[],short int b[],short int c[]);
void movReverseShiftedHugeInt(short int a[],short int b[], unsigned i);
void mulSingleDigitHugeInt(short int a[],short int d);

int main()
{

    short int a[1000],b[1000],c[1000];
    inputHugeInt(a);
    inputHugeInt(b);
    mulHugeInt(a,b,c);
    printHugeInt(c);
    cout<<endl;


    return 0;
}

void inputHugeInt(short int a[])
{
    int i=0;
    char c=0;
    while(c!='#')
    {
        cin>>c;
        if((c>='0')&&(c<='9'))
        {

            a[i++]=c-'0';
        }
    }
    if(i>0)
    {
        a[i]=-1;
    }
    else
    {
        a[i++]=0;
        a[i]=-1;
    }
}

void printHugeInt(short int a[])
{
    int i=0;
    while(a[i]!=-1)
    {
        cout<<a[i++];
    }
}

void reverseHugeInt(short int a[])
{
    int l=lengthHugeInt(a);
    for(int i=0;i<l/2;i++)
        swap(a[i],a[l-i-1]);
}

unsigned short int lengthHugeInt(short int a[])
{
    int l=0;
    while(a[l]!=-1)
        l++;
    return l;
}

void addHugeInt(short int a[],short int b[],short int c[], bool reversed)
{
    int i=0;
    if(!reversed)
    {
        reverseHugeInt(a);
        reverseHugeInt(b);
    }
    while((a[i]!=-1)&&(b[i]!=-1))
    {
        c[i]=a[i]+b[i];
        i++;
    }
    if(a[i]!=-1)
    {
        while(a[i]!=-1)
        {
            c[i]=a[i];
            i++;
        }
    }
    else if(b[i]!=-1)
    {
        while(b[i]!=-1)
        {
            c[i]=b[i];
            i++;
        }
    }
    c[i]=-1;
    i=0;
    while(c[i+1]!=-1)
    {
        c[i+1]+=c[i]/10;
        c[i]%=10;
        i++;
    }
    if(c[i]>9)
    {
        c[i+1]=c[i]/10;
        c[i]%=10;
        c[i+2]=-1;
    }

    if(!reversed)
    {
        reverseHugeInt(a);
        reverseHugeInt(b);
        reverseHugeInt(c);
    }
}

void movReverseShiftedHugeInt(short int a[],short int b[], unsigned i)
{
    int j=0;
    while(j<i)
    {
        b[j]=0;
        j++;
    }
    while(a[j-i]!=-1)
    {
        b[j]=a[j-i];
        j++;
    }
    b[j]=-1;
}

void mulSingleDigitHugeInt(short int a[],short int d)
{
    int i=0;
    while(a[i]!=-1)
    {
        a[i]*=d;
        i++;
    }
    i=0;
    while(a[i+1]!=-1)
    {
        a[i+1]+=a[i]/10;
        a[i]%=10;
        i++;
    }
    if(a[i]>9)
    {
        a[i+1]=a[i]/10;
        a[i]%=10;
        a[i+2]=-1;
    }
}

void mulHugeInt(short int a[],short int b[],short int c[])
{
    //assumption: b is shorter
    short int t[1000];
    unsigned short l=lengthHugeInt(b);
    c[0]=0;
    c[1]=-1;
    reverseHugeInt(a);
    reverseHugeInt(b);
    for(int i=0;i<l;i++)
    {
        movReverseShiftedHugeInt(a,t,i);
        mulSingleDigitHugeInt(t,b[i]);
        addHugeInt(c,t,c,true);
    }

    reverseHugeInt(a);
    reverseHugeInt(b);
    reverseHugeInt(c);
}

