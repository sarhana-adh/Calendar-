//
//  CalendarClasses.h
//  Calendar
//
//  Created by Sarhana Adhikari on 13/10/2021.
//

#ifndef CalendarClasses_h
#define CalendarClasses_h
#include"Yearlywork.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> monthMap {{"JANUARY", 0}, {"FEBRUARY", 1}, {"MARCH", 2}, {"APRIL", 3},{"MAY", 4},{"JUNE", 5},{"JULY", 6},{"AUGUST", 7},{"SEPTEMBER", 8},{"OCTOBER", 9},{"NOVEMBER", 10},{"DECEMBER", 11}};


class Calendar{
    
private:
    
    virtual void printCalendar()=0;
    
public:
    
    // Calendar contains the actual function that makes strings of the Calendar and function to SaveitAsFile
    Calendar(){
        
    }
    
    
    
inline void printMonths(int year, int e, string& Calendar_Printing){
        string month = monthName[e];
        // bool all
        transform(month.begin(), month.end(),month.begin(), ::toupper);
        // columns ought to be calculated here

        string onlyMonth;
        bool Leapyear = LeapYear(year);
        // real printing
        int column= getIndexForMonth(e, year);
        int days = monthDays[monthName[e]];
        if(Leapyear && e == 1){days=29;}
        Calendar_Printing+="\n\n"+monthName[e]+" of " + to_string(year)+"\n";
        Calendar_Printing+="Weekdays\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n           \t";
        
        for(int k=1;k<=days;k++){
            if(k==1){
                for(int l=0;l<column;l++){
                    Calendar_Printing+= "\t";
                }
            }
            Calendar_Printing+= to_string(k)+"\t";
            column++;
            if(column>=7){
            Calendar_Printing+= "\n           \t";//only when it is a new week
            column=0;
            } // changes the column if it exceeds a week
            
        }// spits out the number (in a calendar)
            // make a day object instead
            // day is a object of Year or Month
        }
    
    inline void SaveasFile(string Calendar){
        char saveInFile;
        string  nameoffile;

    cout<<"\nDo you want to save the above calendar in a file? (Y/n)\n";
    cin>>saveInFile;
    if (signed(tolower(saveInFile))== 'y'){
        cout<<"Type in the name of the file you want it to be saved as. (The file will be exported as tab separated values. Do not write .tsv at the end)\n";
        cin>>nameoffile;
        ofstream MyFile;
        nameoffile=nameoffile+".tsv";
        MyFile.open(nameoffile);    // Write to the file
        if(MyFile.fail()){
            cout<<"Failed to open the file\n";
        }
        MyFile<<Calendar;   // Close the file
        MyFile.close();
        cout<<"Succesfully saved the Calendar file as "<<nameoffile<<endl;
    }}

};



class Month: private Calendar {
private:
    string CalendarContent="";
    int* yearOfMonth;
    void UpdateYear(int yearOfUpdate, int i){
        *yearOfMonth = yearOfUpdate;
        string month = monthName[i];
        CalendarContent="";
        printMonths(*yearOfMonth, monthMap[month], CalendarContent);// calendar content is added
    }

public :
    friend class Year;


    Month(int& year, string month){
        yearOfMonth= &year;
        transform(month.begin(), month.end(),month.begin(), ::toupper);
        printMonths(*yearOfMonth, monthMap[month], CalendarContent);// calendar content is added
        
    }
    
    void printCalendar(){
        cout<<CalendarContent;
    }
    void SaveFile(){
        SaveasFile(CalendarContent);
    }
    string getContent(){
        return CalendarContent;
    }
    
};

class Year: private Calendar{
private:
    string CalendarContent="";
    Month* monthsofYear[12]={NULL} ;
    int* yearNumber;
    
public:
    Year(int& year){
        yearNumber= &year;
        for(int i=0;i<12;i++){
             monthsofYear[i]= new Month(*yearNumber, monthName[i]);
        }
    }
    
    void printCalendar(){
        for(int i=0;i<12;i++){
            monthsofYear[i]->printCalendar();
        }
    }
    
    
    void SaveFile(){
        for(int i=0;i<12;i++){
            CalendarContent= CalendarContent + monthsofYear[i]->getContent();
        }
        SaveasFile(CalendarContent);
    }
    int getYear(){
        return *yearNumber;
    }
    
    
    void operator ++(){
        ++*yearNumber;
        for(int i=0;i<12;i++){
            monthsofYear[i]->UpdateYear(*yearNumber, i);
        }
        
    }
    
    void operator --(){
        --*yearNumber;
        for(int i=0;i<12;i++){
            monthsofYear[i]->UpdateYear(*yearNumber, i);
        }
        
    }
    
    ~Year(){
        for(int i=0;i<12;i++){
            delete monthsofYear[i];
        } // deleting from dynamic memory allocation
    }

};



#endif /* CalendarClasses_h */
