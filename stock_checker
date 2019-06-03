#include <bits/stdc++.h> 
using namespace std; 
  
class Interval { 
public: 
    int buy; 
    int sell; 
}; 
  
void stockBuySell(int price[], int n) { 
    if (n == 1) 
        return; 
    int count = 0;
  
    Interval ans[n / 2 + 1]; 
  
    int i = 0; 
    while (i < n - 1) {
        // local minimum
        while ((i < n - 1) && (price[i + 1] <= price[i])) 
            i++; 
            
        // end of stream
        if (i == n - 1) 
            break; 
        ans[count].buy = i++; 
  
        while ((i < n) && (price[i] >= price[i - 1])) 
            i++; 
  
        // Store the index of maxima 
        sol[count].sell = i - 1; 
  
        // Increment count of buy/sell pairs 
        count++; 
    } 
  
    if (count == 0) 
        cout << "There is no way to earn a profit"; 
    else { 
        for (int i = 0; i < count; i++) 
            cout << "Buy on day: " << ans[i].buy 
                 << "\t Sell on day: " << ans[i].sell << endl; 
    } 
  
    return; 
} 
  
// Driver code 
int main() 
{ 
    int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
    int n = sizeof(price) / sizeof(price[0]); 
    stockBuySell(price, n); 
  
    return 0; 
} 
