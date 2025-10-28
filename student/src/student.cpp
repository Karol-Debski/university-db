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

PeselNumber_t Student::getPeselNumber() const 
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
   
   ss<<"Student"<<std::endl;
   ss<<"First name: "<<firstName_<<std::endl;
   ss<<"Last name: "<<lastName_<<std::endl;
   ss<<"Address: "<<address_<<std::endl;
   ss<<"Pesel number: "<<peselNumber_<<std::endl;
   ss<<"Gender: "<<gender_<<std::endl;
   ss<<"Index number: "<<indexNumber_<<std::endl;

   return ss.str();
};
