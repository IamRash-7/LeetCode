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
        for(int i=0;i<n/2;i++)
        {
            tmp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = tmp;
        }
        for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
        cout<<endl;
	}
	return 0;
}