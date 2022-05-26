#include<bits/stdc++.h>
using namespace std;

void reverseArrayItr(int arr[], int start, int end) {
    while(start< end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start+=1;
        end -=1;
    }
}

void reverseArray(int arr[], int start, int end) {
    if(start >= end){
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start+1, end-1);
}

int main() {
    return 0;
}