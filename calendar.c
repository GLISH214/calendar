#include <stdio.h>
#include <stdlib.h>

int first_weekday(int year) {
    int x;
    x = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return x;
}

int main() {
    system("Color 0F");
    int year, month, day, daysInMonth, wday = 0, sday;
    printf("\nEnter your desired year: ");
    scanf("%d", &year);

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int mDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        mDay[1] = 29;
    }

    sday = first_weekday(year);

    for (month = 0; month < 12; month++) {
        daysInMonth = mDay[month];
        printf("\n\n%s:\n", months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (wday = 0; wday < sday; wday++) {
            printf("     ");
        }

        for (day = 1; day <= daysInMonth; day++) {
            printf("%5d", day);

            if (++wday > 6) {
                printf("\n");
                wday = 0;
            }

            sday = wday;
        }
        printf("\n");
    }

    return 0;
}
