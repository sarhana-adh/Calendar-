//
//  Yearlywork.h
//  Calendar
//
//  Created by Sarhana Adhikari on 12/10/2021.
//
#include <iostream>
#include <map>
#include <string>

#include <iterator>
#include <fstream>
#include <algorithm>
#ifndef Yearlywork_h
#define Yearlywork_h
using namespace std;
string monthName [12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
map<string, int> monthDays {{"JANUARY", 31}, {"FEBRUARY", 28}, {"MARCH", 31}, {"APRIL", 30},{"MAY", 31},{"JUNE", 30},{"JULY", 31},{"AUGUST", 31},{"SEPTEMBER", 30},{"OCTOBER", 31},{"NOVEMBER", 30},{"DECEMBER", 31}};

// return bool true if the year is a leapYear
inline bool LeapYear(int yearNumber){
    
    if(abs(yearNumber%4)==0){
        return true;
    }
    else {return false;}
}


// finds the firstWeekDay of the year
inline int findFirstWeekDay(int year){
// October  2 2021 is Saturday
    int dayslater=5;
    int weekindex;
    map<string, int> weekMap { {"Sunday", 1}, {"Monday", 2}, {"Tuesday", 3}, {"Wednesday", 4},{"Thursday", 5},{"Friday", 6},{"Saturday", 7}};

    if (year==2021){
        weekindex=5; // jan 1 of 2021 is the reference
    }
    else if (year>2021){
        for(int i=2021;i<year;i++){
            if(LeapYear(i)){
                dayslater=dayslater+366;
            }
            else {dayslater=dayslater+365;};
        }
        weekindex= abs((dayslater)%7); // gives 0-6 (0 is Sunday)
    }
    else{
        for(int i=2021;i>year;i--){
            if(LeapYear(i-1)){
                dayslater= dayslater - 366;
            }
            else {dayslater= dayslater - 365;};
        }
        weekindex= abs (7- abs((dayslater)%7)); // gives 0-6 (0 is Sunday)

    }
    return weekindex;
}

int getIndexForMonth(int monthNumber, int yearNumber){
    int weekindex;
    weekindex=findFirstWeekDay(yearNumber);
    if(monthNumber==0){
         // nth changes 
    }else{
        int *days;
        for(int g=0;g<monthNumber;g++){
            days = &monthDays[monthName[g]];  
            if(g==1 && LeapYear(yearNumber)){
                weekindex = weekindex+29;
            }
            else{
                weekindex=weekindex+ *days;//number of days since added
        }// in most cases the map has correct number of days in the month
        }
        
    }
    weekindex=weekindex%7;
    return weekindex;
}

#endif /* Yearlywork_h */
