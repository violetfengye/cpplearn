#include <iostream>

template <typename T>
void BubbleSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void PrintArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr1[] = {4, 3, 2, 1};
    float arr2[] = {4.4, 3.3, 2.2, 1.1};

    BubbleSort(arr1, 4);
    BubbleSort(arr2, 4);

    PrintArray(arr1, 4);
    PrintArray(arr2, 4);

    return 0;
}
