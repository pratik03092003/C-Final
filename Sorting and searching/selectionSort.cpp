#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {7, 8, 4, 2, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n - 1; i++){
        // Find the index of the minimum element in the unsorted part
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[i], arr[min_idx]);
    }

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}