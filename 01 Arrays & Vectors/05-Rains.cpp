#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int trappedWater(vector<int> heights){
    
    int n = heights.size();
    if (n <= 2) return 0;

    // Left Max, Right Max
    vector<int> left(n, 0), right(n, 0);
    left[0] = heights[0];
    right[n-1] = heights[n-1];

    // Crates maximum height comming from the left/right
    for( int i = 1; i < n; i++){
        left[i] = max(left[i - 1], heights[i]);
        right[n-i-1] = max(right[n-i], heights[n-i-1]);
    }

    // Water level
    int water = 0;
    for(int i = 0; i < n; i++){
        water += min(left[i], right[i]) - heights[i];
    }

    return water;
}

/*
    Given N non-negative integers representing an elevation map where the width of each bar is 1.
    Compute how much water can be traped after raining.
    
    See example below, where '#' represents given map and '0' represents rained water.
    Answer for the shown example is 6.
          
          #
      #OOO##O#
    #O##O###### 
*/
int main()
{
    vector<int> blockHeights = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trappedWater(blockHeights) << endl;

    return 0;
}