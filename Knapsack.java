class Knapsack { 
  
    static int max(int a, int b) { 
    	return (a > b)? a : b; 
    } 
    
    static int optimize(int W, int wt[], int val[], int n) { 
    	// if we have run out of space or run out of items, return 0
    	if(n == 0 || W == 0) {
    		return 0;
    	}
    	// if the weight of the item is larger than what is left, we continue our search
    	if(wt[n-1] > W) {
    		return optimize(W, wt, val, n-1);
    	}
    	else {
    		// Case A: you choose to include the item in which case you now have:
    		//	(1) More value in your inventory: val[n-1]
    		//	(2) Less space in your bag: W-wt[n-1])
    		int caseA = val[n-1] + optimize((W-wt[n-1]), wt, val, n-1);
    		// Case B: you choose not to include the item in which you now have:
    		// 	-The same amount of space, and the same value, and you continue to fill such space
    		int caseB = optimize(W, wt, val, n-1);
    		
    		// Find the optimum result of these two cases (recursively)
    		return max(caseA, caseB);
    	}  
    } 
  
    
    // Driver program to test above function 
    public static void main(String args[]) {
    	String tasks[] =  new String[]{"Task1", "Task2", "Task3"};
        int dependencies[] = new int[]{0, 3, 5}; 
	    int time[] = new int[]{50, 30, 180}; 
	    int  W = 180; 
	    int n = time.length; 
	    System.out.println(optimize(W, time, dependencies, n)); 
    } 
} 