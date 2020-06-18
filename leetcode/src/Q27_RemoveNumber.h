
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        int pos = 0;
        while (pos < len)
        {
            if (nums[pos] == val)
                nums[pos] = nums[--len];
            else
                ++pos;
        }

        return len;
    }
};