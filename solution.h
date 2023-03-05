/*
    Time Complexity : O(N * log(M))
    Space Complexity : O(1)

    Where 'N' denotes the number of elements int the given array,
    'M' denotes the value of the maximum element in the array.
*/

#include <math.h>
#include <climits>

int smallestDivisor(vector<int>& arr, int n, int limit) 
{

    // Minimum possible divisor.
    int minDiv = 1; 

    // Maximum possible divisor.
    int maxDiv = INT_MIN; 

    for(int i = 0; i < n; i++)
    {
        maxDiv = max(maxDiv, arr[i]);
    }

    int divisor = - 1;
    int sum = 0;

    while(minDiv <= maxDiv)
    {

        // Check for mid can be divisor. 
        int mid = (minDiv + maxDiv) / 2; 

        sum = 0;

        for(int i = 0; i < n; i++)
        {    

            // Sum after division.
            sum = sum + (ceil)((double)arr[i] / mid); 
        }
        
        // If sum is greater than limit then we have to increase mid so that we can reduce the sum to limit.
        if(sum > limit)
        {
            minDiv = mid + 1;
        }
        
        else
        {
            maxDiv = mid - 1;
            divisor = mid;
        }
    }

    return divisor;
}


