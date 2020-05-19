#include <stdio.h>
#include <time.h>
#include <math.h>

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24
#define PROMPT_STRING "Type any key to show time, q to show time then quit: "

#define TIME_TYPE unsigned long 

char getChar() ;
void updateTimes() ;
void initTimes() ;
void printPrompt() ;
void printTime (TIME_TYPE timeInit) ;

TIME_TYPE start, end;

int main (const char argc, char* argv[]) {
        char command = 0;
        initTimes();
        delay();
        updateTimes();
        printTime(end-start);
        return 0;
}

int getstarttime()
{
    int starttime;
    starttime = 1;
    return starttime;
}

int getendtime()
{
    int endtime;
    endtime = 32767;
    return endtime;
}

int delay()
{
   int a = getstarttime();
   int b = getendtime();
   int c = a;
   int d = b;
   
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
       
   return 0;
}


void updateTimes() {
        end = time(0);
}

void initTimes() {
        start = time(0);
        end = start;
}

void printPrompt() {
        printf(PROMPT_STRING);
}

void printTime (TIME_TYPE timeInit) {
        TIME_TYPE time = timeInit;
        int days, hours, minutes, seconds;
        int timeDifferential = 0;
        
        timeDifferential = (SECONDS_PER_MINUTE *
                                MINUTES_PER_HOUR *
                                HOURS_PER_DAY);
        days = (time/timeDifferential);
        time -= timeDifferential*days;
        /* Hours */
        timeDifferential = (SECONDS_PER_MINUTE *
                                MINUTES_PER_HOUR);
        hours = (time/timeDifferential);
        time -= timeDifferential*hours;
        /* Minutes */
        timeDifferential = (SECONDS_PER_MINUTE);
        minutes = (time/timeDifferential);
        time -= timeDifferential*minutes;
        /* Seconds */
        seconds = time;
        /* Check for validity of times, then print.
         * Also print error if need be.*/
        if (!(seconds < 60 && seconds >= 0 &&
                        minutes < 60 && minutes >= 0 &&
                        hours < 24 && hours >= 0 )) {
                printf ("ERROR! TIME FORMAT!\n");
        }
        printf ("Total time (s): %u\n %2dd %2dh %2dm %2ds\n", timeInit, 
                        days, hours, minutes, seconds);
}