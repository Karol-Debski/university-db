#ifndef EMPLOYEE_BUILDER_H
#define EMPLOYEE_BUILDER_H

#include "record_builder.hpp"

class EmployeeBuilder : public IRecordBuilder
{
public:
   EmployeeBuilder() {};

   std::shared_ptr<Record> build(IConsoleInHandler& in, IConsoleOutHandler& out) const override;
   std::string getBuildType() const override;
};

#endif // EMPLOYEE_BUILDER_H