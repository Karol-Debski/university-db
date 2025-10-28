#include <iostream>
#include <vector>
#include "student.hpp"
#include "employee.hpp"
#include "datebase.hpp"



int main()
{
   Student s1("Pawel", "Krakowiak", "Rzeczy 3",  97042900122, "male", 1233191);
   Student s2("Mariusz", "Orzel", "Grundwald 4", 87042900122, "male", 1233121);

   Employee emp1("Alicja", "Konkol", "Kwiatowa 4", 23423122, "female", 345343u);

   std::ofstream stream;

   Datebase datebase(stream, "database-uni.txt");

   datebase.addNewRecord(std::make_shared<Student>(s1));
   datebase.addNewRecord(std::make_shared<Student>(s2));
   datebase.addNewRecord(std::make_shared<Employee>(emp1));

   datebase.displayDatabase();
}