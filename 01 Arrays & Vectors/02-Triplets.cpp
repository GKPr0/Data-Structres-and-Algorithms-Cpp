#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


/*
    Time complexity is O(N^2)
*/
vector<vector<int>> triplets(vector<int> vec, int targetSum){
    //Sort vector
    int vecSize = vec.size();
    sort(vec.begin(), vec.end());
    vector<vector<int>> result;

    // Pick every vec[i] and solve pair sum problem for remaining part
    // Loop thru every number in vector so that remaining part has at least 2 elements.
    for(int i = 0; i <= vecSize -3; i++) { 

        // Using 2 pointer approach
        int leftIndex = i + 1;
        int rightIndex = vecSize -1;

        while (leftIndex < rightIndex){
            int currentSum = vec[i];
            currentSum += vec[leftIndex];
            currentSum += vec[rightIndex];

            if(currentSum == targetSum){
                result.push_back({vec[i], vec[leftIndex], vec[rightIndex]});
                leftIndex++;
                rightIndex--;
            }
            else if(currentSum < targetSum)
                leftIndex++;
            else
                rightIndex--;
        }
    }

    return result;
}

/*
    Given an vector containing N integers, and number "sum" denoting a target sum.

    Find all distinct integers that can add up to form targat sum. 
    The numbers in each triplet should be ordered in ascending order, and tripletrs should be ordered too.
    Return empty vector if no such triplet exists
*/
int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 15, 9, 8};
    int sum = 18;

    auto result = triplets(vec, sum);

    for(auto v : result){
        for(auto n : v){
            cout << n << ",";
        }
        cout << endl;
    }
    
    return 0;
}