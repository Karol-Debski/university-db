#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "record.hpp"
#include <sstream>


class Employee : public Record,
                 public HasFirstName,
                 public HasLastName,
                 public HasAddress,
                 public HasPeselNumber,
                 public HasGender,
                 public HasSalary 
{
public:
   explicit Employee(const std::string& firstName, 
                     const std::string& lastName, 
                     const std::string& address,
                     const std::string& peselNumber,
                     const std::string& gender,
                     const Salary_t     salary)
      : firstName_(firstName),
        lastName_(lastName),
        address_(address),
        peselNumber_(peselNumber),
        gender_(gender),
        salary_(salary) {};


   const std::string&  getFirstName()   const override;
   const std::string&  getLastName()    const override;
   const std::string&  getAddress()     const override;
   const std::string&  getPeselNumber() const override;
   const std::string&  getGender()      const override;
   Salary_t            getSalary()      const override;

   const std::string  getData() const override;

private:
   std::string firstName_;
   std::string lastName_;
   std::string address_;
   std::string peselNumber_;
   std::string gender_;
   Salary_t    salary_;
};

#endif // EMPLOYEE_H