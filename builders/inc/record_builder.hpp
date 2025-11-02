#ifndef RECORD_BUILDER_H
#define RECORD_BUILDER_H

#include "console_ui.hpp"

template<typename T>
T readField(IConsoleInHandler& in, IConsoleOutHandler& out, const std::string& prompt)
{
   T field;

   out << prompt;
   in >> field;

   return field;
}

void validatePeselNumber(const std::string& peselNumber);
void validateGender(const std::string& peselNumber);

class IRecordBuilder
{
public:
   virtual ~IRecordBuilder() = default;

   virtual std::string getBuildType() const = 0;
   virtual std::shared_ptr<Record> build(IConsoleInHandler& in, IConsoleOutHandler& out) const = 0;
};

#endif // RECORD_BUILDER_H