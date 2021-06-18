#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


/*
    Time complexity when using unordered set is O(N)
*/
vector<int> pairSum(vector<int> vec, int sum){
    unordered_set<int> set;

    for(int i = 0; i < vec.size(); i++){
        
        int desired_number = sum - vec[i];
        if(set.find(desired_number)!= set.end())
            return {desired_number, vec[i]};
        
        set.insert(vec[i]);
    }
    return {};
}

/*
    Find pair of numbers in the given list so its sum is equal to some given number.
*/
int main()
{
    vector<int> vec{10, 5, 2, 3, -6, 9, 11};
    int sum = 4;

    auto p = pairSum(vec, sum);
    if(p.size() == 0)
        cout << "No such pair" << endl;
    else
        cout << p[0] << "," << p[1] << endl;
}