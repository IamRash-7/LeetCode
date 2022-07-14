#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t-- >0)
	{
	    int n,tmp;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        for(int i=n-1;i>=0;i--)
	        cout<<arr[i]<<" ";
        cout<<endl;
	}
	return 0;
}