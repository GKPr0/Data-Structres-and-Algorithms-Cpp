#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
    Time complexity O(N)
*/
int maxSubarraySum(vector<int> vec){

    int n = vec.size();
    int maxSum = 0;

    int sum = 0;
    for(int num : vec){

        sum = (sum < 0) ? num : sum + num;
        
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

/*
    Given an array of size N, prints the maximum subarray sum that can be formed.
    A subarray is defined as consecutive segments (indexes) of the array.
    If all numbers are negative, then return 0;

*/
int main() {
    vector<int> vec{-1,2,3,4,-2,6,-10,1,5};

    cout << "Max sum of subarray is " << maxSubarraySum(vec) << endl;   
    return 0;
}