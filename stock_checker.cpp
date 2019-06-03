#include <bits/stdc++.h> 
using namespace std; 
  
// creates a class to be used in the final solution
class Interval { 
public: 
    int buy; 
    int sell; 
}; 

// This function takes in a stream of stock prices and determines how one
// Could have maximized the profit - used the idea of buy low, sell high
// where you want to buy at every local minimum and sell at every local maximum
void stockBuySell(int price[], int n) { 
    // if only one day is given, then you cannot make any profit
    if (n == 1) 
        return; 
  
    int transaction = 0;
    int i = 0; 
    Interval ans[n / 2 + 1]; 
  
    while (i < n - 1) {
        // local minimum - tells you when to buy
        while ((i < n - 1) && (price[i + 1] <= price[i])) 
            i++; // increments while the price is decreasing - wait
           
        // reached end of stream of numbers - break out of loop
        if (i == n - 1) 
            break; 
      
        // otherwise, buy at this spot
        ans[transaction].buy = i++; 
  
        // searches for local maximum - when to sell
        while ((i < n) && (price[i] >= price[i - 1])) 
            i++; // increments while the price is increasing - hold
  
        // sell at this spot
        sol[transaction].sell = i - 1; 
  
        // Indicates there is a transaction made (buy and sell)
        transaction++; 
    } 
  
    // if there are no transactions, indicate this to the user
    if (transaction == 0) 
        cout << "There is no way to earn a profit in this market" << endl; 
    // otherwise, transaction > 0, which means some profit was earned
    else { 
        for (int i = 0; i < transaction; i++) 
            cout << "Buy on day: " << ans[i].buy 
                 << "\t Sell on day: " << ans[i].sell << endl; 
    } 
  
    return; 
} 
  
int main() { 
    // defines market - each entry is the ending price at that day
    int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
  
    // defines number of days tracked in the given market
    int n = sizeof(price) / sizeof(price[0]); 
    stockBuySell(price, n); 
  
    return 0; 
} 
