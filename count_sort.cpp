#include<bits/stdc++.h>
using namespace std;
// time complexity: O(n);

int main()
{
    vector<int>arr={4,2,0,1,0};
    // declare maximum element + 1 size array with default value 0;
    vector<int>count_arr(5,0);
    for(int i=0;i<arr.size();i++){
        count_arr[arr[i]]++;
    };
    // comulative sum of the elements of the count array that will helps
    // us to place the elements to the correct index in the sorted array:
    for(int i=1;i<count_arr.size();i++)
        count_arr[i]+= count_arr[i-1];
    for(int i=0;i<count_arr.size();i++)
        cout << count_arr[i] << " ";
    cout << "\n";
    // counting sort:
    vector<int>sorted_arr(5);
    for(int i=arr.size()-1;i>=0;i--){
        sorted_arr[count_arr[arr[i]] - 1]=arr[i];
        count_arr[arr[i]]--;
    }
    for(int i=0;i<sorted_arr.size();i++)
        cout << sorted_arr[i] << " ";
    return 0;
}
