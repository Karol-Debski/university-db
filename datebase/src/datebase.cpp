#include "datebase.hpp"
#include <fstream>

Datebase::Datebase(FileHandler& fileHandler, const std::string& pathToFile)
   : fileHandler_(fileHandler),
     pathToFile_(pathToFile),
     records_{}
{
   fileHandler_.open(pathToFile, std::ios_base::app
                                 | std::ios_base::in
                                 | std::ios_base::out);

   /* read records */
}

Datebase::~Datebase()
{
   fileHandler_.close();
};

void Datebase::addNewRecord(std::shared_ptr<Record> sp_record)
{
   records_.push_back(sp_record);
}

void Datebase::displayDatabase()
{
   for(const auto& rec : records_)
   {
      std::cout<<rec->getData();
   }
}