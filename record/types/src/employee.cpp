#include "employee.hpp"



const std::string& Employee::getFirstName() const  
{
   return firstName_;
};

const std::string& Employee::getLastName() const  
{
   return lastName_;
};

const std::string& Employee::getAddress() const 
{
   return address_;
};

const std::string& Employee::getPeselNumber() const 
{
   return peselNumber_;
};

const std::string& Employee::getGender() const 
{
   return gender_;
};

Salary_t Employee::getSalary() const 
{
   return salary_;
};

const std::string Employee::getData() const
{
   std::stringstream ss;
   
   ss<<firstName_<<'\n';
   ss<<lastName_<<'\n';
   ss<<address_<<'\n';
   ss<<peselNumber_<<'\n';
   ss<<gender_<<'\n';
   ss<<salary_<<'\n';

   return ss.str();
};

RecordType Employee::getType() const
{
   return RecordType::Employee;
}