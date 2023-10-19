#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    SYSTEMTIME startTime;
    GetSystemTime(&startTime);

    while (true) {
        HWND notepadWnd = FindWindow(L"Notepad", NULL);

        if (notepadWnd != NULL) {
            SYSTEMTIME currentTime;
            GetSystemTime(&currentTime);
            FILETIME fileStartTime, fileCurrentTime;
            SystemTimeToFileTime(&startTime, &fileStartTime);
            SystemTimeToFileTime(&currentTime, &fileCurrentTime);
            ULARGE_INTEGER startTime64, currentTime64;
            startTime64.LowPart = fileStartTime.dwLowDateTime;
            startTime64.HighPart = fileStartTime.dwHighDateTime;
            currentTime64.LowPart = fileCurrentTime.dwLowDateTime;
            currentTime64.HighPart = fileCurrentTime.dwHighDateTime;
            ULONGLONG elapsedMilliseconds = (currentTime64.QuadPart - startTime64.QuadPart) / 10000;

            std::wstring title = L"Час виконання: " + std::to_wstring(elapsedMilliseconds) + L" мс";

            SetWindowText(notepadWnd, title.c_str());
        }
        else { cout << "Error"; }

        Sleep(1000); 
    }

    return 0;
}
