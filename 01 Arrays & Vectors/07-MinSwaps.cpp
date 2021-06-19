#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int countMinSwaps(vector<int> vec) {

    int n = vec.size();
    int ans = 0;

    // First we need to create arrays of pairs where we will store value and original index 
    pair<int, int> ap[n];
    for(int i = 0; i < n; i++){
        ap[i].first = vec[i];
        ap[i].second = i;
    }

    // Second we sort array be value
    sort(ap, ap+n);

    // Lastly we find cycle references which will 
    // tell us how many swaps wee need to perform
    
    // To be able to tell if we found cycle wee need to know which element has been visited
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){

        int old_position = ap[i].second;
        // If element has been visisted or is in right place
        if(visited[i] == true || old_position == i)
            continue;

        // Visiting the element (index) for the first time
        int node = i;
        int cycle = 0;

        // This will tell us if we have reached the cycle
        while(!visited[node]){
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle++;
        }

        // Number of swaps is eaqual to number of nodes in the cycle - 1
        ans += cycle - 1;
    }

    return ans;
}

/*
    Given an array of size N, find the minimum number of swaps
    needed to make the array sorted.
*/
int main() {
    vector<int> arr{2,4,5,1,3};
    cout << countMinSwaps(arr) << endl;
    return 0;
}