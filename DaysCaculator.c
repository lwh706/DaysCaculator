#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main (void){
    int year_1, year_2, month_1, month_2, day_1, day_2;
    int firstDay, lastDay;
    int leapyear_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int normalyear_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int trig_1 = 1;
    while(trig_1){
        printf("Start date : ");
        scanf("%d", &firstDay);
        fflush(stdin);
        year_1 = firstDay/10000;
        month_1 = (firstDay%10000)/100;
        day_1 = firstDay%100;
        if(year_1 < 0){
            printf("Start year must be an integer greater than zero ! Please try again.\n");
            continue;
        }
        if(month_1 <= 0 || month_1 > 12){
            printf("Start month must be an integer between 1 and 12 ! Please try again.\n");
            continue;
        }
        if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
            if(day_1 <= 0 || day_1 > leapyear_month[month_1-1]){
                printf("Start day is NOT correct ! Please try again.\n");
                continue;
            }
        }
        else{
            if(day_1 <= 0 || day_1 > normalyear_month[month_1-1]){
                printf("Start day is NOT correct ! Please try again.\n");
                continue;
            }
        }
        printf("End date : ");
        scanf("%d", &lastDay);
        fflush(stdin);
        year_2 = lastDay/10000;
        month_2 = (lastDay%10000)/100;
        day_2 = lastDay%100;
        if(year_2 < 0){
            printf("Last year must be an integer greater than zero ! Please try again.\n");
            continue;
        }
        if(month_2 <= 0 || month_2 > 12){
            printf("Last month must be an integer between 1 and 12 ! Please try again.\n");
            continue;
        }
        if((year_2%4 == 0 && year_2%100 != 0) || year_2%400 == 0){
            if(day_2 <= 0 || day_2 > leapyear_month[month_2-1]){
                printf("Last day is NOT correct ! Please try again.\n");
                continue;
            }
        }
        else{
            if(day_2 <= 0 || day_2 > normalyear_month[month_2-1]){
                printf("Last day is NOT correct ! Please try again.\n");
                continue;
            }
        }
        // check if lastDay > firstDay
        if(year_1 > year_2){
            printf("StartYear %d > LastYear %d ! Please try again.\n",year_1 ,year_2);
            continue;
        }
        else if(year_1 == year_2 && month_1 > month_2){
            printf("StartMonth %d%d > LastMonth %d%d ! Please try again.\n",year_1 ,month_1, year_2 ,month_2);
            continue;
        }
        else if(year_1 == year_2 && month_1 == month_2 && day_1 > day_2){
            printf("StartDay %d > LastDay %d ! Please try again.\n", firstDay, lastDay);
            continue;
        }
        else{
            trig_1 = 0;
        }
    }
    // caculate days
    int i, result = 0; 
    if(year_2 - year_1 == 0){
        for(i = (month_1 - 1); i < month_2; i++){
            if(i == (month_1 - 1)){
                if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
                    result += leapyear_month[i] - day_1;
                }
                else{
                    result += normalyear_month[i] - day_1;
                }
            }
            else if(i == (month_2 - 1)){
                result += day_2;
            }
            else{
                if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
                    result += leapyear_month[i];
                }
                else{
                    result += normalyear_month[i];
                }
            }
        }
    }
    else if(year_2 - year_1 == 1){
        for(i = (month_1 - 1); i < 12; i++){
            if(i == (month_1 - 1)){
                if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
                    result += leapyear_month[i] - day_1;
                }
                else{
                    result += normalyear_month[i] - day_1;
                }
            }
            else{
                if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
                    result += leapyear_month[i];
                }
                else{
                    result += normalyear_month[i];
                }
            }
        }
        for(i = 0; i < month_2; i++){
            if(i == (month_2 - 1)){
                result += day_2;
            }
            else{
                if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
                    result += leapyear_month[i];
                }
                else{
                    result += normalyear_month[i];
                }
            }
        }

    }
    else{
        printf("Cross year\n");
        for(i = (month_1 - 1); i < 12; i++){
            if(i == (month_1 - 1)){
                if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
                    result += leapyear_month[i] - day_1;
                }
                else{
                    result += normalyear_month[i] - day_1;
                }
            }
            else{
                if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
                    result += leapyear_month[i];
                }
                else{
                    result += normalyear_month[i];
                }
            }
        }
        for(i = (year_1 + 1); i < year_2; i++){
            if((i%4 == 0 && i%100 != 0) || i%400 == 0){
                result += 366;
            }
            else{
                result += 365;
            }
        }
        for(i = 0; i < month_2; i++){
            if(i == (month_2 - 1)){
                result += day_2;
            }
            else{
                if((year_1%4 == 0 && year_1%100 != 0) || year_1%400 == 0){
                    result += leapyear_month[i];
                }
                else{
                    result += normalyear_month[i];
                }
            }
        }
    }
    printf("\n");
    printf("Passing %d Days! \n", result);
    printf("\n");
    system("pause");
}