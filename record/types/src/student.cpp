#include "student.hpp"



const std::string& Student::getFirstName() const  
{
   return firstName_;
};

const std::string& Student::getLastName() const  
{
   return lastName_;
};

const std::string& Student::getAddress() const 
{
   return address_;
};

const std::string& Student::getPeselNumber() const 
{
   return peselNumber_;
};

const std::string& Student::getGender() const 
{
   return gender_;
};

IndexNumber_t Student::getIndexNumber() const 
{
   return indexNumber_;
};

const std::string Student::getData() const
{
   std::stringstream ss;
   
   ss<<firstName_<<'\n';
   ss<<lastName_<<'\n';
   ss<<address_<<'\n';
   ss<<peselNumber_<<'\n';
   ss<<gender_<<'\n';
   ss<<indexNumber_<<'\n';

   return ss.str();
};

RecordType Student::getType() const
{
   return RecordType::Student;
}