#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool outOfOrder(vector<int> vec, int i){
    int current = vec[i];
    
    if(i == 0) 
        return current > vec[i + 1];
    if(i == vec.size() -1) 
        return current < vec[i - 1];

    return current > vec[i + 1] || current < vec[i - 1]; 
}

/*
    Time complexity is O(N).

    With this aproach we find the index of the correct position of
    the smallest and the largest elements that are out of order.
*/
pair<int,int> subarraySort(vector<int> vec) {
    
    int smallest = INT_MAX;
    int largest = INT_MIN;

    // Finds what are the smallest and largest out of order elements
    for(int i = 0; i < vec.size(); i++){
        int current = vec[i];

        if(outOfOrder(vec, i)){
            smallest = min(smallest, current);
            largest = max(largest, current);
        }
    }

    if(smallest == INT_MAX) return {-1, -1};
    
    // Finds correct positions for the smallest and the largest elements.
    int left = 0;
    while(smallest >= vec[left]) left++;

    int right = vec.size() - 1;
    while(largest <= vec[right]) right--;

    return {left, right};
}

/*
    Given an array of size at least two, find the smallest subarray that needs to be sorted
    so that entire input array becomes sorted

    If the input array is already sorted the function should return [-1,-1], otherwise
    return start and end index of smallest subarray.
*/
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(arr);
    
    cout <<"Subarray index are: ";
    cout << p.first << " and " << p.second << endl;

    return 0;
}