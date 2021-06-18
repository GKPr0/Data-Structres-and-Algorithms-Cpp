#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <algorithm>
#include <windows.h>
using namespace std;


int widest_mountain(vector<int> vec){
    
    int n = vec.size();
    
    if( n == 0) return 0;

    int widest = 1;

    for(int i = 1; i < n-2;){
        // Check vec[i] is peak 
        if(vec[i] > vec[i-1] && vec[i] > vec[i+1]){
            int cnt = 1;
            int j = i;

            // Count backwards (left)
            while(j >= 1 && vec[j] > vec[j - 1]){
                j--;
                cnt++;
            }

            // Count forwards (right)
            while(i <= n-2 && vec[i] > vec[i +1]){
                i++;
                cnt++;
            }
            widest = max(widest, cnt);
        }
        else{
            i++;
        }
    }

    return widest;
}


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void vizualize_mountains(vector<int> vec, char selChar){

    const int max = *max_element(vec.begin(), vec.end());
    const int min = *min_element(vec.begin(), vec.end());

   int rowOff = max + 1;
    for(int col = 0; col < vec.size(); col++){
        
        int row = 0;

        while(abs(row) <= abs(vec[col])){
            gotoxy(col, rowOff - row);
            cout << selChar;
            
            if( vec[col] > 0)
                row++;
            else
                row--;
        }
        
    }
    gotoxy(0, abs(max) + abs(min) + 2);
}



/*
   Write a function that takes array of distinc integers as input, and return the width of highest mountain.

   A mountain is defined as adjacent integers that are strictly increasing until they reach a peak, at which they start to become strictly decresing
   At least 3 numbers are required to form a mountain.
*/
int main()
{
    vector<int> vec{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

    char selChar = '*';
    vizualize_mountains(vec, selChar);

    cout << "Widest mouintain has width of " << widest_mountain(vec) << " "<< selChar << endl;
    
    return 0;
}