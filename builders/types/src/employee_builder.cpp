#include "employee_builder.hpp"

std::shared_ptr<Record> EmployeeBuilder::build(IConsoleInHandler& in, IConsoleOutHandler& out) const
{
   std::string firstName;
   std::string lastName;
   std::string address;
   std::string peselNumber;
   std::string gender;
   Salary_t    salary;
   
   firstName   = readField<std::string>(in, out, "Type first name: ");
   lastName    = readField<std::string>(in, out, "Type last name: ");
   address     = readField<std::string>(in, out, "Type address: ");
   peselNumber = readField<std::string>(in, out, "Type pesel number: ");
   gender      = readField<std::string>(in, out, "Type gender (male or female): ");

   try
   {
      validatePeselNumber(peselNumber);
      validateGender(gender);
   }
   catch(const std::exception& e)
   {
      out << e.what() << '\n';
      return nullptr;
   }
   
   salary = readField<Salary_t>(in, out, "Type salary: ");

   return std::make_shared<Employee>(firstName, lastName, address, peselNumber, gender, salary);
}

std::string EmployeeBuilder::getBuildType() const
{
   return "Employee";
}