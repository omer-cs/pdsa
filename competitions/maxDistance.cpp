#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int bruteForce(int arr[], int n, int k) {
    int Max = INT_MIN;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            Max = max(Max, abs(k-arr[i])+abs(k-arr[j]));
        }
    }
    return Max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int arr[n];
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<bruteForce(arr, n, k)<<endl;

    return 0;
}
