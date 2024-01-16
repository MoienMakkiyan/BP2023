#include <iostream>

using namespace std;


int main()
{
	int n,k,a[1000];
	cin>>n;
	k=n*(n-1)+n+1;
	for(int i=1;i<=n;i++)
	{
		a[i-1]=k;
		for(int j=1;j<=n;j++)
	    {
	    	a[i-1]-=n;
	        cout<<a[i-1]<<" ";
	        
	    }
	    k+=1;
	    cout<<endl;
	    
		
	}
	
	
	return 0;
}
