#pragma once
#include <functional>
#include <memory>
#include <vector>

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

//radix must be power of 2 or 10
inline void radixSort(std::vector<int> &arr, int radix = 10)
{
    //could find max value first
    if (radix!= 10)
    {
        int r = radix;
        int n = -1;
        while (r)
        {
            r>>= 1;
            n++;
        }
        bool flag = true;
        int k = 0;
        std::vector<std::vector<int>> temp;
        while (flag)
        {
            temp.clear();
            temp.resize(radix);
            flag = false;
            for (long i : arr)
            {
                int b=(i >> (k * n));
                if (b > 0)
                    flag = true;
                int a =  b& (radix - 1);
                temp[a].emplace_back(i);
            }
            int i = 0;
            for (auto v : temp)
                for (auto e : v)
                {
                    arr[i] = e;
                    i++;
                }
            k++;
        }
    }
    else
    {
        std::vector<std::vector<int>> temp;
        long divider = 1;
        bool flag = true;
        while (flag)
        {
            temp.clear();
            temp.resize(radix);
            flag = false;
            for (int i : arr)
            {
                int b=i/divider;
                if(b>0)flag=true;
                int a = b % radix;
                temp[a].emplace_back(i);
            }
            int i = 0;
            for (auto v : temp)
                for (auto e : v)
                {
                    arr[i] = e;
                    i++;
                }
            divider *= 10;
        }
    }
}