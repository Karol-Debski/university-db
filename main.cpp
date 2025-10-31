#include <iostream>
#include <vector>
#include "student.hpp"
#include "employee.hpp"
#include "datebase.hpp"



int main()
{
   Student s1("Pawel1", "Krakowiak", "Rzeczy 3",  "97042900122", "male", 1233191);
   Student s2("Pawel2", "Krakowiak", "Rzeczy 3",  "77042900122", "male", 1233192);
   Student s3("Pawel3", "Krakowiak", "Rzeczy 3",  "87042900122", "male", 1233193);
   Student s4("Mariusz", "Orzel", "Grundwald 4",  "67042900122", "male", 1233121);

   Employee emp1("Alicja", "Konkol", "Kwiatowa 4", "57042900122", "female", 745343u);
   Employee emp2("Patryk", "Konkol", "Kwiatowa 4", "27042900122", "male",   345343u);

   std::ofstream stream;

   Datebase datebase(stream, "database-uni.txt");

   datebase.addNewRecord(std::make_shared<Student>(s1));
   datebase.addNewRecord(std::make_shared<Student>(s2));
   datebase.addNewRecord(std::make_shared<Student>(s3));
   datebase.addNewRecord(std::make_shared<Student>(s4));
   datebase.addNewRecord(std::make_shared<Employee>(emp1));
   datebase.addNewRecord(std::make_shared<Employee>(emp2));

   auto results1 = datebase.searchByLastName("Krakowiak");
   auto results2 = datebase.searchByPeselNumber("97042900122");

   std::cout<<"Number of records with \"Krakowiak\" as last name: "<<results1.size()<<std::endl;

   std::cout<<"Number of records with \"97042900122\" as pesel number: "<<results2.size()<<std::endl;

   datebase.fillDatebaseWithArtificialRecords();
   
   datebase.sortByPeselNumber();

   datebase.sortByLastName();

   datebase.sortBySalary();

   datebase.deleteStudent(1233191);
   datebase.deleteStudent(1233192);

   datebase.displayDatabase();
}