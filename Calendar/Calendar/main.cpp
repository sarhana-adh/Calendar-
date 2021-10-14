//
//  main.cpp
//  Calendar
//
//  Created by Sarhana Adhikari on 30/09/2021.
//
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>
#include "Yearlywork.h"
#include "CalendarClasses.h"
using namespace std;

void CalendarFunction(Year& yearObject){
    yearObject.printCalendar();
    yearObject.SaveFile();
}

void CalendarFunction(Month& monthObject){
    monthObject.printCalendar();
    monthObject.SaveFile();
}
// function overloading here 

// use the operator overloading

int main() {
    // insert code here...

    int inputbyuser;
    do{
    bool valid=false;
    do{
        cout << "\n[1] Type in 1 for Printing a Month. \n[2] Type in 2 for view of a Year. \n[3] Type in 3 for exiting the program.\n";
        cin>>inputbyuser;
        if (inputbyuser==1||inputbyuser==2||inputbyuser==3){
            valid =true;
        }
        if(!valid){cout<<"The input was not valid. Please re-enter the value \n"<<endl;}
    }while(!valid);
    
    switch(inputbyuser){
            // incase Month is chosen to be printed at once
        case 1:{
            string month;
            int* YeartoPrintptr;
            int YearToPrint;
            cout<<"What month from what year would you like to be printed ?\nEnter the Year first."<<endl; // function overloading here
            cin>>YearToPrint;
            YeartoPrintptr=&YearToPrint;
            cout<<"Enter the month now. "<<endl;
            cin>>month;
            Month MonthOfUser(YearToPrint, month);
            CalendarFunction(MonthOfUser);
            
            // write an event 
            
            break;
        }
        case 2:{ // incase Year is chosen to be printed at once
            int YeartoPrint;
            cout<<"What year would you like to be printed? "<<endl;
            cin>> YeartoPrint;
            Year YearOfUser(YeartoPrint);
            CalendarFunction(YearOfUser);
            int inputInnerMenu;
            do{
                cout<<"[1] Enter 1 for next Year to be printed! \n[2]Enter 2 for previous Year to be printed!\n[3]Enter 3 to go back to the main Menu\n";
               
                try {cin>> inputInnerMenu;
                    // a lot of stuff
                    switch(inputInnerMenu){
                        case 1:
                            ++YearOfUser;
                            cout<<"Year right now is: "<<YearOfUser.getYear()<<endl;;
                            CalendarFunction(YearOfUser);
                            break;
                        case 2:
                            --YearOfUser;
                                CalendarFunction(YearOfUser);
                            break;
                        case 3:
                            break; break;
                        default:throw inputInnerMenu;
                            
                    }}
                catch(int input){
                    cout<<input<<" is invalid input."<<endl;
                }
                    
                         // Throw an exception when a problem arise

                    
                  // Block of code to handle errors
                
                
                
                
            }while(inputInnerMenu!=3);
            
            // add events to particular day
            // binary search to get the day
            
            
            break;}
            

        case 3:{
            cout<<"Exiting the program..."<<endl;
            exit(0);
            break;}
            
        default: throw inputbyuser;
            break;
    }
    }while(inputbyuser!=3);
    

        
        return 0;
    }
    
    

     
