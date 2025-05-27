#include <iostream>

//Jai Shree Ram
//Author : Aditya Singh
//Software Testing Next Date cpp code

int main() {
    int nextday{}, nextmonth{}, nextyear{}, day{}, month{}, year{};
    bool c1{}, c2{}, c3{};

    // Input
    std::cin >> day >> month >> year;

    // Validity checks
    if (day >= 1 && day <= 31) { c1 = true; } else { std::cout << "day out of the range\n"; }
    if (month >= 1 && month <= 12) { c2 = true; } else { std::cout << "month out of the range\n"; }
    if (year >= 1812 && year <= 2012) { c3 = true; } else { std::cout << "year out of the range\n"; }

    if (!(c1 && c2 && c3)) return 1;

    nextmonth = month;
    nextyear = year;

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10:
            if (day < 31) nextday = day + 1;
            else if (day == 31) {
                nextday = 1;
                nextmonth = month + 1;
            } else {
                std::cout << "invalid input date" << std::endl;
                return 1;
            }
            break;

        case 4: case 6: case 9: case 11:
            if (day < 30) nextday = day + 1;
            else if (day == 30) {
                nextday = 1;
                nextmonth = month + 1;
            } else {
                std::cout << "invalid input date" << std::endl;
                return 1;
            }
            break;

        case 2:
            if (day < 28) nextday = day + 1;
            else if (day == 28) {
                if (isLeap) nextday = 29;
                else {
                    nextday = 1;
                    nextmonth = 3;
                }
            } else if (day == 29 && isLeap) {
                nextday = 1;
                nextmonth = 3;
            } else {
                std::cout << "invalid input date" << std::endl;
                return 1;
            }
            break;

        case 12:
            if (day < 31) nextday = day + 1;
            else if (day == 31) {
                if (year == 2012) {
                    std::cout << "invalid year" << std::endl;
                    return 1;
                }
                nextday = 1;
                nextmonth = 1;
                nextyear = year + 1;
            } else {
                std::cout << "invalid input date" << std::endl;
                return 1;
            }
            break;

        default:
            std::cout << "invalid month" << std::endl;
            return 1;
    }

    std::cout << "Next date: " << nextday << "/" << nextmonth << "/" << nextyear << std::endl;
    return 0;
}
