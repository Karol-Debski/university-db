#ifndef STUDENT_BUILDER_H
#define STUDENT_BUILDER_H

#include "record_builder.hpp"

class StudentBuilder : public IRecordBuilder
{
public:
   StudentBuilder() {};

   std::shared_ptr<Record> build(IConsoleInHandler& in, IConsoleOutHandler& out) const override;
   std::string getBuildType() const override;
};

#endif // STUDENT_BUILDER_H