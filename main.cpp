#include <iostream>
#include <vector>
#include <memory>
#include "student.hpp"
#include "employee.hpp"
#include "database.hpp"
#include "student_builder.hpp"
#include "employee_builder.hpp"
#include "console_ui.hpp"


int main()
{
   std::streambuf* coutBuffer = std::cout.rdbuf();
   std::streambuf* cinBuffer  = std::cin.rdbuf();

   std::ostream  oStream(coutBuffer);
   std::istream  iStream(cinBuffer);
   std::fstream fileStream;

   Datebase database(fileStream);

   std::vector<std::shared_ptr<IRecordBuilder>> builders;

   builders.push_back(std::make_shared<StudentBuilder>());
   builders.push_back(std::make_shared<EmployeeBuilder>());

   ConsoleUI consoleUI(oStream, iStream, database, builders);

   consoleUI.run();
}