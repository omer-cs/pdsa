#include<bits/stdc++.h>
using namespace std;

void printArrary(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}
// Below function rotate array with 0(N) time and 0(k) space
void fun1(int arr[], int n, int k) {
    int temp[k];
    for(int i=0; i<k; ++i) {
        temp[i] = arr[i];
    }

    for(int i=0; i<n-k; ++i) {
        arr[i] = arr[i+k];
    }

    for(int i=0; i<k; ++i) {
        arr[n-k+i] = temp[i];
    }

    printArrary(arr, n);
}

void leftRotate(int arr[], int n) {
    int temp = arr[0];
    for(int i=0; i<n; ++i) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}
//Below function rotates array with 0(N*K) time and 0(1) space
void fun2(int arr[], int n, int k) {
    for(int i=0; i<k; ++i) {
        leftRotate(arr, n);
    }
    printArrary(arr,n);
}

int gcd(int a, int b) {     // this is modified euclidean algorithm to find gcd or hcf of two numbers
    return b==0 ? a : gcd(b, a % b);
}

void fun3(int arr[], int n, int k) {
    
    k = k%n;

    int div = gcd(n, k);

    for(int i=0; i<)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    // fun1(arr, n, k);
    // fun2(arr, n, k);
    fun3(arr, n, k);
    return 0;
}