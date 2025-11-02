#ifndef RECORD_HPP
#define RECORD_HPP

#include <string>

enum class RecordType
{
   Student,
   Employee
};

class Record {
public:
   virtual ~Record() {};
   virtual const std::string getData() const = 0;
   virtual RecordType getType() const = 0;
};

using IndexNumber_t = unsigned long;
using Salary_t      = unsigned int;

class HasFirstName
{
public:
   virtual ~HasFirstName() = default;
   virtual const std::string& getFirstName() const = 0;
};

class HasLastName
{
public:
   virtual ~HasLastName() = default;
   virtual const std::string& getLastName() const = 0;
};

class HasAddress
{
public:
   virtual ~HasAddress() = default;
   virtual const std::string& getAddress() const = 0;
};

class HasPeselNumber
{
public:
   virtual ~HasPeselNumber() = default;
   virtual const std::string& getPeselNumber() const = 0;
};

class HasGender
{
public:
   virtual ~HasGender() = default;
   virtual const std::string& getGender() const = 0;
};

class HasIndexNumber
{
public:
   virtual ~HasIndexNumber() = default;
   virtual IndexNumber_t getIndexNumber() const = 0;
};

class HasSalary
{
public:
   virtual ~HasSalary() = default;
   virtual Salary_t getSalary() const = 0;
};

#endif // RECORD_HPP