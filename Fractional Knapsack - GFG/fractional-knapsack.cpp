// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double w = W;
        vector<pair<double,pair<double,double>>> wbp(n);
        for(int i=0;i<n;i++)
        {
            wbp[i].first = (double)arr[i].value/(double)arr[i].weight;
            wbp[i].second.first = arr[i].value;
            wbp[i].second.second = arr[i].weight;
        }
        sort(wbp.begin(),wbp.end());
        double prof = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(wbp[i].second.second <= w)
            {
                double temp = wbp[i].second.first;
                prof += temp;
                temp = wbp[i].second.second;
                w -= temp;
            }
            else
            {
                double temp = wbp[i].first;
                prof += temp * w;  
                break;
            }
        }
        return prof;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends