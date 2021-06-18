#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
    Time complexity O(NLogN + N) -> Sort + 1 iteration
*/
int longestBand(vector<int> vec){

    int n = vec.size();
    if(n == 0) return 0;
    
    sort(vec.begin(), vec.end());

    int longest = 1;
    int length = 1;

    for(int i = 0; i <= n-2; i++){
        if((vec[i + 1] - vec[i]) == 1)
            length++;
        else{
            longest = max(longest, length);
            length = 0;
        }
    }
   
    return max(longest, length); 
}

/*
    Time complexity O(N) - O(2*N)
*/
int longestBand2(vector<int> vec){
    
    // Create unordered set
    unordered_set<int> set;
    for(int num : vec)
        set.insert(num);

    int longest = 0;
    for(int num : set){
        int parentValue = num - 1;

        // If set does not contain parentValue then current value is head of new band
        if(set.find(parentValue) == set.end()){
            int nextValue = num + 1;
            int cnt = 1;

            while(set.find(nextValue) != set.end()){
                nextValue++;
                cnt++;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;
}

/*
    Given an vector containing N integers, find length of longest band.

    A band is defined as a subsequence which can be reordered in such a manner that all elements appear
    consecutive (ie with absolute difference of 1 between neigbouring elements)

    A longest band is the band (subsequence) which contains maximum integers.
*/
int main()
{
    vector<int> vec{1, 9, 3, 0, 18 ,5 ,2 ,4 ,10 ,7 ,12, 6};
    
    cout << "Version 1: The longest band has langth of " << longestBand(vec) << endl;
    cout << "Version 2: The longest band has langth of " << longestBand2(vec) << endl;
    return 0;
}