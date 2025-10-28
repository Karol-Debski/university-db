#include <iostream>
#include <vector>
#include "student.hpp"
#include "employee.hpp"







int main()
{
   Student s1("Pawel", "Krakowiak", "Rzeczy 3",  97042900122, "male", 1233191);
   Student s2("Mariusz", "Orzel", "Grundwald 4", 87042900122, "male", 1233121);

   Employee emp1("Alicja", "Konkol", "Kwiatowa 4", 23423122, "female", 345343u);

   std::vector<Record*> records{&s1, &s2, &emp1};

   for(const auto& rec : records)
   {
      std::cout<<rec->getData();
   }
}