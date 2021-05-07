/*
 * https://leetcode.com/problems/two-sum/
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int, int> mymap;
        vector <int> res;

        for (vector <int> :: iterator itr = nums.begin(); itr != nums.end();
             itr++) {
            unordered_map <int, int> :: iterator it =
                mymap.find(target - (*itr));
            if (it != mymap.end()) {
                res.push_back(itr - nums.begin());
                res.push_back((*it).second);
                break;
            } else {
                mymap.insert(pair<int, int> (*itr, itr-nums.begin()));
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector <int> vec = {2,7,11,15};
    vector <int> res = s.twoSum(vec, 9);
    for (vector <int> :: iterator itr = res.begin(); itr != res.end(); itr++) {
        cout<<*itr<<" ";
    }
    cout<<endl;

    return 0;
}
