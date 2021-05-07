#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_set <int> myset;
        
        for (vector <int> :: iterator itr = nums.begin(); itr != nums.end(); itr++) {
            unordered_set <int> :: iterator it = myset.find(*itr);
            if (it != myset.end()) {
                myset.erase(it);
            } else {
                myset.insert(*itr);
            }
        }
        return *(myset.begin());
    }
};

int main(int argc, char **argv)
{
    vector <int> vec = {2, 2, 1};
    Solution s;
    cout<<"result : "<<s.singleNumber(vec)<<endl;
    return 0;
}
