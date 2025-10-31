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
   
   ss<<"Employee"<<std::endl;
   ss<<"First name: "<<firstName_<<std::endl;
   ss<<"Last name: "<<lastName_<<std::endl;
   ss<<"Address: "<<address_<<std::endl;
   ss<<"Pesel number: "<<peselNumber_<<std::endl;
   ss<<"Gender: "<<gender_<<std::endl;
   ss<<"Salary: "<<salary_<<std::endl;

   return ss.str();
};
