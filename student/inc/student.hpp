#include "record.hpp"
#include <sstream>

#ifndef STUDENT_H
#define STUDENT_H

class Student : public Record,
                public HasFirstName,
                public HasLastName,
                public HasAddress,
                public HasPeselNumber,
                public HasGender,
                public HasIndexNumber 
{
public:
   explicit Student(const std::string&  firstName, 
                    const std::string&  lastName, 
                    const std::string&  address,
                    const PeselNumber_t peselNumber,
                    const std::string&  gender,
                    const IndexNumber_t indexNumber)
      : firstName_(firstName),
        lastName_(lastName),
        address_(address),
        peselNumber_(peselNumber),
        gender_(gender),
        indexNumber_(indexNumber) {};


   const std::string& getFirstName()   const override;
   const std::string& getLastName()    const override;
   const std::string& getAddress()     const override;
   PeselNumber_t      getPeselNumber() const override;
   const std::string& getGender()      const override;
   IndexNumber_t      getIndexNumber() const override;

   const std::string  getData() const override;

private:
   std::string   firstName_;
   std::string   lastName_;
   std::string   address_;
   PeselNumber_t peselNumber_;
   std::string   gender_;
   IndexNumber_t indexNumber_;
};

#endif // STUDENT_H