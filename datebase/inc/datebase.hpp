#ifndef DATEBASE_H
#define DATEBASE_H

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "record.hpp"

using FileHandler = std::ofstream; 

class Datebase
{
public:
   Datebase(FileHandler& fileHandler, const std::string& pathToFile);

   ~Datebase();

   void addNewRecord(std::shared_ptr<Record> sp_record);
   void displayDatabase();

private:
   FileHandler& fileHandler_;
   std::string pathToFile_;
   std::vector<std::shared_ptr<Record>> records_; 
};

#endif // DATEBASE_H