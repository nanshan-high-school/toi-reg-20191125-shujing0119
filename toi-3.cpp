#include <iostream>
using namespace std;

int main() {
    int step;
    cout << "請輸入站牌數量:";
    cin >> step;

    int startTimeHours = 0;
    int startTimeMinute = 0;

    cout << "請輸入起始小時及分鐘:\n";
    cin >> startTimeHours;
    cin >> startTimeMinute;

    startTimeMinute += startTimeHours * 60;

    int interval[1001] = {0};
    cout << "請輸入各站牌間隔時間:\n";

    for (int i = 1; i <= step; i++) {
        cin >> interval[i];
        interval[i] += interval[i - 1];
    }

    int stepNum = 0;
    int totalTimeHour[1001] = {0};
    int totalTimeMinute[1001] = {0};
    cout << "請輸入想查詢的站牌:\n";

    do {
        cin >> stepNum;

        totalTimeHour[stepNum] = (startTimeMinute + interval[stepNum]) / 60;
        if (totalTimeHour[stepNum] >= 24) {
            totalTimeHour[stepNum] -= 24;
        }
        
        totalTimeMinute[stepNum] = (startTimeMinute + interval[stepNum]) % 60;
    } while (stepNum != 0);

    for (int i = 1; i <= 1001; i++) {
        if (totalTimeHour[i] == 0 && totalTimeMinute[i] == 0) {

        } else {
            if (totalTimeHour[i] < 10) {
                cout << "0";
                cout << totalTimeHour[i] << ":";

                if (totalTimeMinute[i] < 10) {
                    cout << "0";
                    cout << totalTimeMinute[i] << "\n";
                } else {
                    cout << totalTimeMinute[i] << "\n";
                }
            } else {
                cout << totalTimeHour[i] << ":" << totalTimeMinute[i] << "\n";
            }
        }
    }
}

// 650275 杜心妍
