#include<bits/stdc++.h>
using namespace std;

vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int temp = 0;
        for(int i=0; i< nums.size(); i++) {
            for(int j=i+1; j< nums.size(); j++) {
                if(nums[i]+nums[j] == target) {
                    return vector<int>{i, j};// can use this as well {i,j}
                    break;
                }
            }
        }
        return vector<int>{0,0};// can use this as well {}
    }

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i=0; i<nums.size(); i++) {
        if(map.find(target-nums[i]) != map.end()){
            return {i, map[target-nums[i]]};
        }
        map[nums[i]] = i;
    }
     return {};
}
int main() {
    return 0;
}