/*
    https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

    The cost of stock on each day is given in an array price[] of size n.
    Each day you may decide to either buy or sell the stock i at price[i],
    you can even buy and sell the stock on the same day, Find the maximum profit which you can get.
    Note: You can only hold one stock at a time.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int profit = 0;
        int price = -1;
        for (int i = 0; i < n-1; i++) {
            if (price == -1 && prices[i] < prices[i+1]) {
                price = prices[i];
            }
            if (price != -1 && prices[i] > prices[i+1]) {
                profit += prices[i] - price;
                price = -1;
            }
            cout << i << " " << profit << " " << endl;
        }
        cout << endl;
        if (price != -1) {
            profit += *prices.rbegin()-price;
        }
        return profit;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends