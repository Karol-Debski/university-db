#include "student_builder.hpp"

std::shared_ptr<Record> StudentBuilder::build(IConsoleInHandler& in, IConsoleOutHandler& out) const
{
   std::string   firstName;
   std::string   lastName;
   std::string   address;
   std::string   peselNumber;
   std::string   gender;
   IndexNumber_t index;
   
   firstName   = readField<std::string>(in, out, "Type first name: ");
   lastName    = readField<std::string>(in, out, "Type last name: ");
   address     = readField<std::string>(in, out, "Type address: ");
   peselNumber = readField<std::string>(in, out, "Type pesel number: ");
   gender      = readField<std::string>(in, out, "Type gender (male or female): ");
out<<gender<<'\n';
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
   
   index  = readField<IndexNumber_t>(in, out, "Type index number: ");

   return std::make_shared<Student>(firstName, lastName, address, peselNumber, gender, index);
}

std::string StudentBuilder::getBuildType() const
{
   return "Student";
}