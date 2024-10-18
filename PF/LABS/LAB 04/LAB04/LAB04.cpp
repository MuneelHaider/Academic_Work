#include <iostream>
using namespace std;

void task1(int n, int c) {

    if (n == 0) {
        if (c == 0) {

            return;
        }
        
        cout << endl;
        return task1(n + c, c - 1);
    }
    else {

        cout << "*";
        return task1(n - 1, c);
    }
}

int getCharCount(const char* ptr, char c) {

    if (*ptr == '\0') {

        return 0;
    }

    else if (*ptr == c) {

        return 1 + getCharCount(ptr + 1, c);
    }
    else {

        return getCharCount(ptr + 1, c);
    }
}

int getUniCharCount(const char* ptr, const char* current) {

    if (*ptr == '\0') {

        return 0;
    }

    if (getCharCount(ptr, *ptr) > 1) {

        return getUniCharCount(ptr + 1, current);
    }
    else {

        return 1 + getUniCharCount(ptr + 1, current);
    }

}

int main()
{
    task1(5, 4);

    char array[] = "wavelength";
    const char* ptr = &array[0];
    const char* current = &array[0];

    cout << endl << endl;

    char c;
    cin >> c;

    cout << getCharCount(ptr, c) << endl << endl;

    cout << getUniCharCount("frequency", current) << endl;

    return 0;
}