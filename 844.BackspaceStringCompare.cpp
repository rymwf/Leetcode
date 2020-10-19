/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.

Follow up:

    Can you solve it in O(N) time and O(1) space?

*/
#include "common.h"

class Solution
{
public:
    //this is ignore #
    bool Compare(string S, string T)
    {
        int i = S.size() - 1, j = T.size() - 1;
        while (i >= 0 && j >= 0)
        {
            while (i > 0 && S[i] == '#')
                i--;
            while (j > 0 && T[j] == '#')
                j--;
            if (S[i] != T[j])
                return false;
            i--;
            j--;
        }
        if (i < 0 && j < 0)
            return true;
        else if (i < 0)
        {
            while (j >= 0 && T[j] == '#')
                j--;
            if (j >= 0)
                return false;
            return true;
        }
        else if (j < 0)
        {
            while (i >= 0 && S[i] == '#')
                i--;
            if (i >= 0)
                return false;
            return true;
        }
        return true;
    }
    bool backspaceCompare(string S, string T)
    {
        int i0 = S.size() - 1, j0 = T.size() - 1;
        int i1 = 0, j1 = 0;

        while (i0 >= 0 || j0 >= 0)
        {
            while (i0 >= 0)
            {
                if (S[i0] == '#')
                    i1++;
                else
                {
                    if (i1 == 0)
                        break;
                    i1--;
                }
                i0--;
            }
            while (j0 >= 0)
            {
                if (T[j0] == '#')
                    j1++;
                else
                {
                    if (j1 == 0)
                        break;
                    j1--;
                }
                j0--;
            }
            if ((i0 < 0 && j0 >= 0) || (i0 >= 0 && j0 < 0))
                return false;
            while (i0 >= 0 && j0 >= 0 && S[i0] != '#' && T[j0] != '#')
            {
                if (S[i0] != T[j0])
                    return false;
                i0--;
                j0--;
            }
        }
        return true;
    }
};

int main()
{
    string s = "abc", t = "abd#c";
    Solution S;
    int res = S.backspaceCompare(s, t);
    printf("%d\n", res);
}
