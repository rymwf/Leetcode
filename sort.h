#pragma once
#include <functional>
#include <memory>

inline void quickSort(int arr[], int count)
{
    static std::function<void(int, int)> f = [&](int l, int r) {
        if (l >= r)
            return;
        int t = (l + r) / 2, p = l;
        std::swap(arr[r], arr[t]);
        for (int i = l; i < r; ++i)
        {
            if (arr[i] < arr[r])
            {
                std::swap(arr[i], arr[p]);
                p++;
            }
        }
        std::swap(arr[p], arr[r]);
        f(l, p - 1);
        f(p + 1, r);
    };
    f(0, count - 1);
}