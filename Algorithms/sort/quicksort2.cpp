//
//  quicksort2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-11-25.
//

#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

using namespace std;

namespace {
// ---------------- Partition 函数 ----------------
// Lomuto partition：以 arr[high] 作为 pivot
// 功能：把数组分成两部分，左边 <= pivot，右边 > pivot
// 返回 pivot 最终位置
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];      // 选择最后一个元素作为 pivot
    int i = low - 1;            // i 指向小于等于 pivot 的最后一个元素
    
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {   // 小于等于 pivot 的元素放左边
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);  // 把 pivot 放到正确位置
    return i + 1;               // 返回 pivot 的索引
}

int partition2(vector<int> &data, int low, int hi)
{
    int pivot = data[hi];
    int i = low - 1;
    
    for (int j = low; j < hi; j++)
    {
        if(data[j] <= pivot)
        {
            i++;
            swap(data[i], data[j]);
        }
    }
    
    swap(data[hi], data[i+1]);
    return i + 1;
}

// ---------------- QuickSort 函数 ----------------
void quicksort(vector<int>& arr, int low, int high) {
    if(low >= high) return;           // 空数组或单元素数组直接返回
    int pi = partition(arr, low, high); // 分区
    quicksort(arr, low, pi - 1);     // 递归左半部分
    quicksort(arr, pi + 1, high);    // 递归右半部分
}

}

// ---------------- 主函数测试 ----------------
int quicksort2main() {
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1, 5};
    
    cout << "原数组: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    quicksort(arr, 0, arr.size() - 1);

    cout << "排序后: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
