#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm localTime = *localtime(&now_c);

    cout << "Today's date: " << put_time(&localTime, "%Y-%m-%d") << endl;
    cout << "Today is: " << put_time(&localTime, "%A") << endl;

    tm userDate = {};
    cout << "\n" <<"Enter a date (Year Month Day): ";
    
    if (!(cin >> userDate.tm_year >> userDate.tm_mon >> userDate.tm_mday)) {
        cout << "Invalid input! Please enter numeric values." << endl;
        return 1;
    }

    userDate.tm_year -= 1900;  
    userDate.tm_mon -= 1;      
    userDate.tm_isdst = -1;    

    time_t timeVal = mktime(&userDate);
    if (timeVal == -1) {
        cout << "Invalid date!" << endl;
        return 1;
    }

    
    userDate = *localtime(&timeVal);

    
    const char* daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    cout <<"\n" "The date is: " << daysOfWeek[userDate.tm_wday] << endl;

    return 0;
}
