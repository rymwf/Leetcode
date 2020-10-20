/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.

Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true

Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.

 

Constraints:

    1 <= name.length <= 1000
    1 <= typed.length <= 1000
    The characters of name and typed are lowercase letters.

*/
#include"common.h"

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p0=name.length()-1;
        int p1=typed.length()-1;
        if(p0>p1||name[p0]!=typed[p1])return false;
        p0--;
        p1--;
        while(p0>=0&&p1>=0){
            if(name[p0]==typed[p1]){
                p0--;
                p1--;
                continue;
            }
            if(typed[p1]!=typed[p1+1])
                return false;
            p1--;
            if(p0>p1)return false;
        }
        while(p1>=0){
            if(typed[p1]!=typed[p1+1])return false;
            p1--;
        }
        return true;
    }
};

int main(){
    string a="laiiden";
    string b="allaiiddenn";
    Solution s;
    printf("%d",s.isLongPressedName(a,b));
}