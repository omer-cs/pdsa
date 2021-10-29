#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sapce ' '

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        cin>>b[i];
    int count=0;

    for(int i=0; i<n-1; i++) {
        count += max(abs(a[i+1]-a[i]),abs(b[i+1]-b[i]));
    }
    cout<<count<<endl;
}