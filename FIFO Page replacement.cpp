#include <iostream>
using namespace std;

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = 12;
    int frames[3];
    int faults = 0;

    for (int i = 0; i < 3; i++)
        frames[i] = -1;

    int index = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;

        for (int j = 0; j < 3; j++) {
            if (frames[j] == page) {
                found = true;
                break;
            }
        }

        if (!found) {
            frames[index] = page;
            index = (index + 1) % 3;
            faults++;
        }

        cout << "Frames: ";
        for (int j = 0; j < 3; j++)
            cout << frames[j] << " ";
        cout << endl;
    }

    cout << "Total Page Faults = " << faults;

    return 0;
}
