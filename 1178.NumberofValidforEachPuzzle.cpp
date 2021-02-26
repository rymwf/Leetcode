/*
With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:

    word contains the first letter of puzzle.
    For each letter in word, that letter is in puzzle.
    For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; while invalid words are "beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle).

Return an array answer, where answer[i] is the number of words in the given word list words that are valid with respect to the puzzle puzzles[i].

 

Example :

Input: 
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation:
1 valid word for "aboveyz" : "aaaa" 
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There're no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.

 

Constraints:

    1 <= words.length <= 10^5
    4 <= words[i].length <= 50
    1 <= puzzles.length <= 10^4
    puzzles[i].length == 7
    words[i][j], puzzles[i][j] are English lowercase letters.
    Each puzzles[i] doesn't contain repeated characters.
*/
#include "common.h"

class Solution {
public:
	//exceed time limit
	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
		array<bool, 26> puzzleLetters;
		int len = puzzles.size();
		vector<int> ret(len);
		bool containFirstLetter;
		while (--len >= 0)
		{
			memset(puzzleLetters.data(), 0, sizeof puzzleLetters);
			for (auto &&e : puzzles[len])
				puzzleLetters[e - 'a'] = true;
			for (auto &&word : words)
			{
				containFirstLetter = false;
				for (auto &&c : word)
				{
					if (!puzzleLetters[c - 'a'])
						goto FLAG1;
					else if (c == puzzles[len][0])
						containFirstLetter = true;
				}
				if (containFirstLetter)
					++ret[len];
			FLAG1:
				continue;
			}
		}
		return ret;
	}
	vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
	{
		auto f = [](const string &str) {
			int a{};
			for (auto &&c : str)
				a |= 1 << (c - 'a');
			return a;
		};
		int len = puzzles.size();
		vector<int> puzzleCodes(len);
		vector<int> ret(len);
		int i;
		for (i = 0; i < len; ++i)
			puzzleCodes[i] = f(puzzles[i]);
		
		for (auto &&word : words)
		{
			auto wordCode = f(word);
			for (i = 0; i < len; ++i)
			{
				if (wordCode == (wordCode & puzzleCodes[i]) && ((wordCode >> (puzzles[i][0] - 'a')) & 1))
					++ret[i];
			}
		}
		return ret;
	}
	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
		auto f = [](const string &str) {
			int a{};
			for (auto &&c : str)
				a |= 1 << (c - 'a');
			return a;
		};
		int len = puzzles.size();
		vector<int> ret(len);
		unordered_map<int, int> wordCodeMap;
		for (auto &&word : words)
		{
			auto a = f(word);
			if (bitset<26>(a).count() <= 7)
				++wordCodeMap[a];
		}
		auto it = wordCodeMap.begin(), end = wordCodeMap.end();
		for (int i = 0; i < len; ++i)
		{
			int puzzleCode{};
			for (int j = 1; j < 7; ++j)
			{
				puzzleCode |= (1 << (puzzles[i][j] - 'a'));
			}
			int subset = puzzleCode;
			do
			{
				int s = subset | (1 << (puzzles[i][0] - 'a'));
				if (wordCodeMap.count(s))
					ret[i] += wordCodeMap[s];
				subset = (subset - 1) & puzzleCode;
			} while (subset != puzzleCode);
		}
		return ret;
	}
};
