#include <iostream>
using namespace std;

int main() {
   // your code goes here
   
   int month, day, allDay = 0;
   int dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   string strMonToSun[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
   
   cin >> month >> day;
   
   for(int i = 0 ; i < month - 1 ; i++){
      allDay += dayOfMonth[i];
   }
   
   allDay += day;
   
   cout << strMonToSun[allDay % 7]; 
   
   return 0;
}