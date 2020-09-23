#include <string>
#include <unordered_set>
int lengthOfLongestSubstring(std::string s)
{
    std::unordered_set<char> myset;
    int left = 0, right = 0;
    int maxNum = 0;
    for (; right < s.size(); ++right)
    {

        for (auto it = myset.begin(); it != myset.end(); ++it)
        {
            printf("%c ", *it);
        }
        printf("\n");
        if (myset.find(s[right]) != myset.end())
        {
            printf("%c, %c === ", s[left], s[right]);
            while (s[left] != s[right])
            {
                myset.erase(s[left]);
                left++;
            }
            myset.erase(s[right]);
            left++;
        }
        printf("%d==", myset.size());
        myset.emplace(s[right]);
        maxNum = maxNum < (right - left + 1) ? right - left + 1 : maxNum;
        printf("%d %d %d\n", right, left, maxNum);
    }

    return maxNum;
}

int main()
{
    std::string str = "tmmzuxt";
    int r = lengthOfLongestSubstring(str);
    printf("%d", r);
    return 0;
}