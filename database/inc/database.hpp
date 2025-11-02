#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "record.hpp"
#include "student.hpp"
#include "employee.hpp"




using IFileHandler = std::basic_fstream<char>; 

class Datebase
{
public:
   Datebase(IFileHandler& fileHandler);

   ~Datebase();

   void readDatabase();
   void writeDatabase();

   void addNewRecord(std::shared_ptr<Record> sp_record);
   std::string getContentString() const;

   void setPathToFile(const std::string& pathToFile);
   std::string getPathFile();

   std::vector<std::shared_ptr<const Record>> searchByLastName(const std::string& lastName) const;
   std::vector<std::shared_ptr<const Record>> searchByPeselNumber(const std::string& peselNumber) const;
   
   void sortByPeselNumber();
   void sortByLastName();
   void sortBySalary();
   void deleteStudent(const IndexNumber_t id);
   void fillDatebaseWithArtificialRecords();

private:
   IFileHandler& fileHandler_;
   std::string   fileName_;
   std::vector<std::shared_ptr<Record>> records_; 
};



#endif // DATABASE_H