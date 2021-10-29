#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > solve(int A) {
    vector<vector<int>>vec;
    vector<int>current;
    for(int i=0; i<A; i++) {
        for( int j=0; j<=i; j++) {
            if(j == 0 || j == i)
                current.push_back(1);
            else
                current.push_back(vec[i-1][j-1]+ vec[i-1][j]);
        }
        vec.push_back(current);
        current.clear();
    }
    return vec;
}
int main() {
    int n;
    cin>>n;
    vector<vector<int>> vec = solve(n);
    for( auto i: vec) {
        for( auto j : i)
            cout<<j << " ";
        cout<<endl;
    }
    return 0;
}