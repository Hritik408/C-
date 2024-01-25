#include <iostream>

int main() {
    int arr[] = {6, 5, 2, 5, 6, 7, 2};
    int x = 0;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        x ^= arr[i];
    }

    std::cout << x << std::endl;

    return 0;
}


