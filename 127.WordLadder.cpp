/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/
#include "common.h"
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<int> history;
        int endWordIndex = -1;
        int flag=0;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if(flag==2)break;
            if (wordList[i] == endWord)
            {
                endWordIndex = i;
                flag++;
                break;
            }
            if(wordList[i]==beginWord){
                history.emplace(i);
                flag++;
            }
        }
        if (endWordIndex == -1)
            return 0;

        auto isTransformable = [](string &a, string &b) {
            int res = 0;
            for (int i = 0; i < a.size(); ++i)
            {
                res += a[i] != b[i];
            }
            return res == 1;
        };
        if(isTransformable(beginWord,endWord))return 2;
        int ret = 1;
        queue<int> myque;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (isTransformable(beginWord, wordList[i])&&history.find(i)==history.end())
            {
                myque.emplace(i);
                history.emplace(i);
            }
        }
        while (!myque.empty())
        {
            ret++;
            int l = myque.size();
            int a=history.size();
            for (int i = 0; i < l; ++i)
            {
                if (isTransformable(wordList[myque.front()], endWord))
                {
                    return ret+1;
                }
                history.emplace(myque.front());
                for (int i = 0; i < wordList.size(); ++i)
                {
                    if (history.find(i) == history.end() && isTransformable(wordList[myque.front()], wordList[i]))
                    {
                        myque.emplace(i);
                        history.emplace(i);
                    }
                }
                myque.pop();
            }
        }
        return 0;
    }
};
int main()
{

    //string a="a";
    //string b="c";
    //vector<string> str={"a","b","c"};

    string a="hit";
    string b="cog";
    vector<string> str={"hot","dot","dog","lot","log","cog"};
    //vector<string> str={"hit","cog"};

    //string a = "qa";
    //string b = "sq";
    //string a = "cet";
    //string b = "ism";

    auto aaa=str.size();
    Solution s;
    auto r = s.ladderLength(a, b, str);
    std::cout << r;
}