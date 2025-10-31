#ifndef DATEBASE_H
#define DATEBASE_H

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "record.hpp"
#include "student.hpp"
#include "employee.hpp"

using FileHandler = std::ofstream; 

class Datebase
{
public:
   Datebase(FileHandler& fileHandler, const std::string& pathToFile);

   ~Datebase();

   void addNewRecord(std::shared_ptr<Record> sp_record);
   void displayDatabase() const;

   std::vector<std::shared_ptr<const Record>> searchByLastName(const std::string& lastName) const;
   std::vector<std::shared_ptr<const Record>> searchByPeselNumber(const std::string& peselNumber) const;
   
   void sortByPeselNumber();
   void sortByLastName();
   void sortBySalary();
   void deleteStudent(const IndexNumber_t id);
   void fillDatebaseWithArtificialRecords();

private:
   FileHandler& fileHandler_;
   std::string pathToFile_;
   std::vector<std::shared_ptr<Record>> records_; 
};

#endif // DATEBASE_H