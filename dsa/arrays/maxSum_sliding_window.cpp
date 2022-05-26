#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int k, int n) {
    int result =0;
    for(int i=0; i<k; i++)
        result = arr[i];

    for(int i=0; i<n-k; i++){
        temp = arr[i+k] + result -arr[i];
        if(temp > result) {
            result = temp;
        }
    }
    return result;
}

int main() {
    return 0;
}