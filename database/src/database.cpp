#include "database.hpp"
#include <fstream>
#include <algorithm>
#include <random>

Datebase::Datebase(IFileHandler& fileHandler)
   : fileHandler_(fileHandler),
     fileName_{},
     records_{}
{

}

void Datebase::readDatabase()
{
   fileHandler_.open(fileName_, std::ios::in | std::ios::out | std::ios::binary);

   if(!fileHandler_.is_open()) {
      fileHandler_.clear();
      fileHandler_.open(fileName_, std::ios::out | std::ios::binary); // utwórz plik
      fileHandler_.close();
      fileHandler_.open(fileName_, std::ios::in | std::ios::out | std::ios::binary);
   }
             
   int recordId;

   while(fileHandler_>>recordId)
   {
      if(recordId == static_cast<int>(RecordType::Student))
      {
         std::string   firstName;
         std::string   lastName;
         std::string   address;
         std::string   peselNumber;
         std::string   gender;
         IndexNumber_t index;
   
         fileHandler_>>firstName;
         fileHandler_>>lastName;
         fileHandler_>>address;
         fileHandler_>>peselNumber;
         fileHandler_>>gender;
         fileHandler_>>index;
         
         records_.push_back(std::make_shared<Student>(firstName, lastName, address, peselNumber, gender, index));
      }
      else if(recordId == static_cast<int>(RecordType::Employee))
      {
         std::string firstName;
         std::string lastName;
         std::string address;
         std::string peselNumber;
         std::string gender;
         Salary_t    salary;

         fileHandler_>>firstName;
         fileHandler_>>lastName;
         fileHandler_>>address;
         fileHandler_>>peselNumber;
         fileHandler_>>gender;
         fileHandler_>>salary;

         records_.push_back(std::make_shared<Student>(firstName, lastName, address, peselNumber, gender, salary));
      }
   }
}

void Datebase::writeDatabase()
{
   fileHandler_.clear();
   fileHandler_.seekp(0, std::ios::beg);

   for(const auto& rec : records_)
   {
      fileHandler_<<static_cast<int>(rec->getType())<<'\n';
      fileHandler_<<rec->getData();
   }
}

void Datebase::setPathToFile(const std::string& pathToFile)
{
   fileName_ = pathToFile;
}

std::string Datebase::getPathFile()
{
   return fileName_;
}

Datebase::~Datebase()
{
   fileHandler_.close();
};

void Datebase::addNewRecord(std::shared_ptr<Record> sp_record)
{
   records_.push_back(sp_record);
}

std::vector<std::shared_ptr<const Record>> Datebase::searchByLastName(const std::string& lastName) const
{
   std::vector<std::shared_ptr<const Record>> records;
   HasLastName* p_hasLastName = nullptr;

   for(const auto& rec : records_)
   {
      if((p_hasLastName = dynamic_cast<HasLastName*>(rec.get())))
      {
         if(p_hasLastName->getLastName() == lastName)
         {
            records.push_back(rec); 
         }
      }
   }
   
   return records; /* RVO */
}

std::vector<std::shared_ptr<const Record>> Datebase::searchByPeselNumber(const std::string& peselNumber) const
{
   std::vector<std::shared_ptr<const Record>> records;
   HasPeselNumber* p_hasPeselNumber = nullptr;

   for(const auto& rec : records_)
   {
      if((p_hasPeselNumber = dynamic_cast<HasPeselNumber*>(rec.get())))
      {
         if(p_hasPeselNumber->getPeselNumber() == peselNumber)
         {
            records.push_back(rec); 
         }
      }
   }
   
   return records; /* RVO */
}

void Datebase::sortByPeselNumber()
{
   std::sort(records_.begin(), records_.end(), 
      [p_hasPeselNumber1 = static_cast<HasPeselNumber*>(nullptr), 
       p_hasPeselNumber2 = static_cast<HasPeselNumber*>(nullptr)]
      (const auto& rec1, const auto& rec2) mutable
   {
      p_hasPeselNumber1 = dynamic_cast<HasPeselNumber*>(rec1.get());
      p_hasPeselNumber2 = dynamic_cast<HasPeselNumber*>(rec2.get());

      if(p_hasPeselNumber1 && p_hasPeselNumber2)
      {
         return std::lexicographical_compare(p_hasPeselNumber1->getPeselNumber().crbegin(), 
                                             p_hasPeselNumber1->getPeselNumber().crend(),
                                             p_hasPeselNumber2->getPeselNumber().crbegin(),
                                             p_hasPeselNumber2->getPeselNumber().crend());
      }

      if(p_hasPeselNumber1 && !p_hasPeselNumber2)
      {
         return true;
      }

      if(!p_hasPeselNumber1 && p_hasPeselNumber2)
      {
         return false;
      }

      return true;
   });
}

void Datebase::sortByLastName()
{
   std::sort(records_.begin(), records_.end(), 
      [p_hasLastName1 = static_cast<HasLastName*>(nullptr), 
       p_hasLastName2 = static_cast<HasLastName*>(nullptr)]
      (const auto& rec1, const auto& rec2) mutable
   {
      p_hasLastName1 = dynamic_cast<HasLastName*>(rec1.get());
      p_hasLastName2 = dynamic_cast<HasLastName*>(rec2.get());

      if(p_hasLastName1 && p_hasLastName2)
      {
         return p_hasLastName1->getLastName() < p_hasLastName2->getLastName();
      }

      if(p_hasLastName1 && !p_hasLastName2)
      {
         return true;
      }

      if(!p_hasLastName1 && p_hasLastName2)
      {
         return false;
      }

      return true;
   });
}

void Datebase::sortBySalary()
{
   std::sort(records_.begin(), records_.end(), 
      [p_hasSalary1 = static_cast<HasSalary*>(nullptr), 
       p_hasSalary2 = static_cast<HasSalary*>(nullptr)]
      (const auto& rec1, const auto& rec2) mutable
   {
      p_hasSalary1 = dynamic_cast<HasSalary*>(rec1.get());
      p_hasSalary2 = dynamic_cast<HasSalary*>(rec2.get());

      if(p_hasSalary1 && p_hasSalary2)
      {
         return p_hasSalary1->getSalary() < p_hasSalary2->getSalary();
      }

      if(p_hasSalary1 && !p_hasSalary2)
      {
         return true;
      }

      if(!p_hasSalary1 && p_hasSalary2)
      {
         return false;
      }

      return true;
   });
}

void Datebase::deleteStudent(const IndexNumber_t id)
{
   HasIndexNumber* p_hasIndexNumber = nullptr;

   for(auto it = records_.begin(); it != records_.end(); ++it)
   {
      if((p_hasIndexNumber = dynamic_cast<HasIndexNumber*>(it->get())))
      {
         if(p_hasIndexNumber->getIndexNumber() == id)
         {
            records_.erase(it);
            break;
         }
      }
   }
}

void Datebase::fillDatebaseWithArtificialRecords()
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<char> dist(97, 122);

   std::string firstName;
   std::string lastName;
   std::string address;
   std::string pesel;
   std::string gender;
   
   for(size_t j = 0; j < 10; ++j)
   {

      for(size_t k = 0; k < 2; ++k)
      {
         for(size_t i = 0; i < 10; ++i)
         {
            firstName.push_back(dist(gen));
            lastName.push_back(dist(gen));
            address.push_back(dist(gen));
         }
   
         firstName[0] = static_cast<char>(std::toupper(firstName[0]));
         lastName[0]  = static_cast<char>(std::toupper(lastName[0]));
         address[0]   = static_cast<char>(std::toupper(address[0]));
   
         pesel.append(std::to_string(10 + (dist(gen) % 89)));
         pesel.append(std::to_string(10 + (dist(gen) % 2)));
         pesel.append(std::to_string(10 + (dist(gen) % 18)));
         pesel.append(std::to_string(12340 + j));
         
         gender = (dist(gen) % 2 == 1) ? "male" : "female";
   
         if(k == 0)
            records_.push_back(std::make_shared<Student>(firstName, lastName, address, pesel, gender, 12345 + j));
         else
            records_.push_back(std::make_shared<Employee>(firstName, lastName, address, pesel, gender, 32425 + j));
      }

      firstName.clear();    
      lastName.clear();    
      address.clear();    
      pesel.clear();     
      gender.clear();    
   }
}

std::string Datebase::getContentString() const
{
   std::string content;

   {
      for(const auto& rec : records_)
      {
         content += "----------\n";
         content += rec->getData();
      }
   }

   return content;
}
