#include <iostream>
using namespace std;

int main() {
    float Day[7][4] = {0};

    for (int i = 0; i < 7; i++) {
        cout << "輸入第" << i + 1 << "天各時段降雨量:\n";

        for (int j = 0; j < 4; j++) {
            cin >> Day[i][j];
        }
    }

    float MaxDay = 0;
    float MaxTotalDay = 0;
    float TotalDay = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            TotalDay += Day[i][j];

            if (TotalDay > MaxTotalDay) {
                MaxTotalDay = TotalDay;
                MaxDay = i + 1;
            }
        }

        TotalDay = 0;
    }

    float MaxTime = 0;
    float MaxTotalTime = 0;
    float TotalTime = 0;

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 7; i++) {
            TotalTime += Day[i][j];

            if (TotalTime > MaxTotalTime) {
                MaxTotalTime = TotalTime;
                MaxTime = j + 1;
            }
        }

        TotalTime = 0;
    }


    cout << MaxDay << "\n";
    if (MaxTime == 1) {
        cout << "morning";
    } else if (MaxTime == 2) {
        cout << "afternoon";
    } else if (MaxTime == 3) {
        cout << "night";
    } else if (MaxTime == 4) {
        cout << "evening";
    }
}

//650275 杜心妍
