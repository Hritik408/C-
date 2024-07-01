#include <iostream>

int main() {
    int arr[] = {1,4,4,5,5,5,5,6,6,6,7,11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p1 = 0, p2 = n - 1, count = 0;
    int k = 10;

    while (p1 < p2) {
        if (arr[p1] + arr[p2] == k) {
            if (arr[p1] != arr[p2]) {
                int cnt1 = 0;
                int x = arr[p1];
                while (p1 < n && arr[p1] == x) {
                    cnt1++;
                    p1++;
                }

                int cnt2 = 0;
                int y = arr[p2];
                while (p2 >= 0 && arr[p2] == y) {
                    cnt2++;
                    p2--;
                }

                count += cnt1 * cnt2;
            } else {
                int cnt3 = p2 - p1 + 1;
                count += (cnt3 * (cnt3 - 1)) / 2;
                break;
            }
        } else if (arr[p1] + arr[p2] < k) {
            p1++;
        } else {
            p2--;
        }
    }

    std::cout << count;

    return 0;
}

