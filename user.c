#include "user.h"


void initHash(){
    for(int i=0;i<size;i++)
        userHash[i].ID=-1;
}

long makeID(){
    //srand(time(NULL));  //preferably, this must be seeded in main.c instead of inside this function
    int whatever;
    //assume close to 8,000 maximum potential users ==> 4-digit unique ID suffices

    //use rand to generate the number

    long ID = rand();

    while (ID < 1000 || ID > 9999) {
        if (ID > 9999) {
            ID = ID % 10000;
            }

        else {
            whatever = rand() % 10;
            if (whatever == 0) {
                whatever += 1;
                }
            ID += (whatever*1000) ;
            }
        }
    
    if(userHash[ID-1000].ID==-1){
        userHash[ID-1000].ID = ID;
        return ID;
    }
    else{
        makeID();
    }
    
}

void setDate(long id){
    int day, month, year;
 
    // `time_t` is an arithmetic time type
    time_t now;
 
    // Obtain current time
    // `time()` returns the current time of the system as a `time_t` value
    time(&now);
 
    // Convert to local time format and print to stdout
    //printf("Today is %s", ctime(&now));
 
    // localtime converts a `time_t` value to calendar time and
    // returns a pointer to a `tm` structure with its members
    // filled with the corresponding values
    struct tm *local = localtime(&now);
 
    //hours = local->tm_hour;         // get hours since midnight (0-23)
    //minutes = local->tm_min;        // get minutes passed after the hour (0-59)
    //seconds = local->tm_sec;        // get seconds passed after a minute (0-59)
 
    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;      // get month of year (0 to 11)
    year = local->tm_year + 1900;   // get year since 1900
 
    // print local time
    // if (hours < 12) {    // before midday
    //     printf("Time is %02d:%02d:%02d am\n", hours, minutes, seconds);
    // }
    // else {    // after midday
    //     printf("Time is %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
    // }
 
    // // print the current date
    // printf("Date is: %02d/%02d/%d\n", day, month, year);

 
    (userHash[id-1000]).join.dd=day;
    (userHash[id-1000]).join.mm=month;
    (userHash[id-1000]).join.yy=year;
}

void setTime(long id){
    int hours, minutes, seconds, day, month, year;
 
    // `time_t` is an arithmetic time type
    time_t now;
 
    // Obtain current time
    // `time()` returns the current time of the system as a `time_t` value
    time(&now);
 
    // Convert to local time format and print to stdout
    //printf("Today is %s", ctime(&now));
 
    // localtime converts a `time_t` value to calendar time and
    // returns a pointer to a `tm` structure with its members
    // filled with the corresponding values
    struct tm *local = localtime(&now);
 
    hours = local->tm_hour;         // get hours since midnight (0-23)
    minutes = local->tm_min;        // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;        // get seconds passed after a minute (0-59)
 
    //day = local->tm_mday;            // get day of month (1 to 31)
    //month = local->tm_mon + 1;      // get month of year (0 to 11)
    //year = local->tm_year + 1900;   // get year since 1900
 
    // print local time
    // if (hours < 12) {    // before midday
    //     printf("Time is %02d:%02d:%02d am\n", hours, minutes, seconds);
    // }
    // else {    // after midday
    //     printf("Time is %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
    // }
 
    // // print the current date
    // printf("Date is: %02d/%02d/%d\n", day, month, year);
 
    // return 0;
    (userHash[id-1000]).tim.hrs=hours;
    (userHash[id-1000]).tim.min=minutes;
}

void makeUser(){
    long id=makeID();
    setDate(id);
    setTime(id);

    printf("Enter initial balance: ");
    scanf("%lf",&(userHash[id-1000].balance));

    //to delete later
    printf("ID: %ld\n", id);
    printf("Balance: %lf\n",userHash[id-1000].balance);
    printf("Date : %d/%d/%d\n",userHash[id-1000].join.dd,userHash[id-1000].join.mm,userHash[id-1000].join.yy);
    printf("Time : %d:%d\n",userHash[id-1000].tim.hrs,userHash[id-1000].tim.min);
}
