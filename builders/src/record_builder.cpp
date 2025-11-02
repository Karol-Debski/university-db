#include "record_builder.hpp"


static bool isLeapYear(int year)
{
   return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 ==0));
}

void validatePeselNumber(const std::string& peselNumber)
{
   int year;
   int month;
   int day;

   if(peselNumber.size() != 11)
   {
      throw std::runtime_error("Wrong number of digits"); 
   }

   year = 1900 + std::stoi(peselNumber.substr(9, 2));

   /* month validation */

   month = std::stoi(peselNumber.substr(7, 2));

   if(month == 0 && month > 12)
      throw std::runtime_error("Month equals to 0 or it is bigger than 12"); 

   /* day validation */

   day = std::stoi(peselNumber.substr(5, 2));

   int daysInMonth[] = {31,0,31,30,31,30,31,31,30,31,30,31};

   daysInMonth[1] = (isLeapYear(year)) ? 29 : 28;

   if(day == 0 && day > daysInMonth[month-1])
      throw std::runtime_error("Day number equals to 0 or exceed days number of the month"); 
}

void validateGender(const std::string& gender)
{
   if((gender != "male") && (gender != "female"))
   {
      throw std::runtime_error("Wrong gender"); 
   }
}