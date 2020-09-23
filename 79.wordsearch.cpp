
#include <unordered_set>
#include <utility>
#include <iostream>
using namespace std;

unordered_set<int> history;

bool func(vector<vector<char>> &board, int x, int y, string &word, int i)
{
    if (i == word.size())
        return true;
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
        return false;
    auto a = x * board[0].size() + y;
    printf("%d %d %d %d\n", x, y, i, a);
    if (history.find(a) != history.end())
        return false;
    else
    {
        history.emplace(a);
        printf("emplace %d \n", a);
    }
    if (board[x][y] == word[i] && (func(board, x - 1, y, word, i + 1) || func(board, x + 1, y, word, i + 1) || func(board, x, y - 1, word, i + 1) || func(board, x, y + 1, word, i + 1)))
        return true;
    else
    {
        printf("erase %d", a);
        history.erase(a);
        return false;
    }
}

bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            printf("aaa");
            history.clear();
            if (func(board, i, j, word, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> a;

    a.resize(2);
    a[0].push_back('a');
    a[0].push_back('b');
    a[1].push_back('c');
    a[1].push_back('d');
    int r = exist(a, "cdba");
    printf("%d", r);
    return 0;
}