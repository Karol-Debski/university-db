#include <functional>
#include "console_ui.hpp"
#include "record_builder.hpp"

ConsoleUI::ConsoleUI(IConsoleOutHandler& consoleOutHandler, 
                     IConsoleInHandler&  consoleInHandler, 
                     Datebase&           database,
                     const IBuilders_t&  builders)
   : out_(consoleOutHandler),
     in_(consoleInHandler),
     database_(database),
     builders_(builders),
     state_(EConsoleUIState::Home)
{
   //database_.readDatabase();
}

void ConsoleUI::executeHome()
{
   int desiredState = 0;

   out_<<"------------------------------------------------\n"
         "State: Home\n"
         "1. Add new record.\n"
         "2. Display entire database.\n"
         "3. Search records by field.\n"
         "4. Sort records by field.\n"
         "5. Delete records by field.\n"
         "6. Load or create database.\n"
         "7. Save database.\n"
         "8. Exit.\n"
         "Type number of associated state to enter it: ";
   
   in_>>desiredState;

   if(desiredState < 0 || desiredState > 8)
   {
      out_<<"Invalid index\n";
      state_ = EConsoleUIState::Home;
   }
   else
   {
      state_ = static_cast<EConsoleUIState>(desiredState);
   }
}

void ConsoleUI::executeAddingNewRecord()
{
   size_t index;

   out_<<"------------------------------------------------\n"
         "State: AddingNewRecord\n"
         "Chose one of available types:\n";
                     
   for(auto it = builders_.cbegin(); it != builders_.cend(); ++it)
   {
      index = static_cast<size_t>(std::distance(builders_.cbegin(), it));
      out_<<index<<". "<<(*it)->getBuildType()<<'\n';
   }

   out_<<"Type number of associated type to start adding it: ";

   in_>>index;
                        
   if(index >= builders_.size())
   {
      out_<<"Invalid type, you typed: "<<index<<"\n";
      state_ = EConsoleUIState::Home;
      return;
   }

   std::shared_ptr<Record> p_record = builders_[index]->build(in_, out_);

   if(p_record != nullptr)
   {
      database_.addNewRecord(p_record);
      out_<<"Adding the record was successful"<<'\n';
   }
   else
   {
      out_<<"Adding the record failed"<<'\n';
   }

   state_ = EConsoleUIState::Home;
}

void ConsoleUI::executeDisplayEntireDatabase()
{
   out_ << "Entire database:\n" << database_.getContentString();
   state_ = EConsoleUIState::Home;
}

void ConsoleUI::executeSearching()
{
   int fieldId;

   out_ << "------------------------------------------------\n"
           "State: Searching\n"
           "Available fields: \n"
           "0. Last name.\n"
           "1. Pesel number.\n"
           "Type index associated with type of field to search by: ";

   in_ >> fieldId;

   if(fieldId == 0)
   {
      std::string lastName;

      out_ << "Type last name: ";
      in_ >> lastName;

      auto results = database_.searchByLastName(lastName);

      out_ << "---------\n"
              "Results: \n";

      for(const auto& rec : results)
      {
         out_ << "---------\n";
         out_ << rec->getData();
      }
   }
   else if(fieldId == 1)
   {
      std::string peselNumber;

      out_ << "Type pesel number: ";
      in_ >> peselNumber;

      auto results = database_.searchByPeselNumber(peselNumber);

      out_ << "Results: \n";

      for(const auto& rec : results)
      {
         out_ << rec->getData();
      }
   }
   else
   {
      out_<<"Invalid index\n";
   }


   state_ = EConsoleUIState::Home;
}

void ConsoleUI::executeSorting()
{
   int fieldId;

   out_ << "------------------------------------------------\n"
           "State: Sorting\n"
           "Available fields: \n"
           "0. Last name.\n"
           "1. Pesel number.\n"
           "2. Salary.\n"
           "Type index associated with type of field to search by: ";

   in_ >> fieldId;

   if(fieldId == 0)
   {
      database_.sortByLastName();
   }
   else if(fieldId == 1)
   {
      database_.sortByPeselNumber();
   }
   else if(fieldId == 2)
   {
      database_.sortBySalary();
   }
   else
   {
      out_<<"Invalid index\n";
   }

   state_ = EConsoleUIState::Home;
}

void ConsoleUI::executeDeletingRecords()
{
   int fieldId;

   out_ << "------------------------------------------------\n"
           "State: DeletingRecords\n"
           "Available fields: \n"
           "0. Index number.\n"
           "Type index associated with type of field to delete: ";

   in_ >> fieldId;

   if(fieldId == 0)
   {
      IndexNumber_t indexNumber;

      out_ << "Type index number: ";
      in_ >> indexNumber;

      database_.deleteStudent(indexNumber);
   }
   else
   {
      out_<<"Invalid index\n";
   }

   state_ = EConsoleUIState::Home;
}

void ConsoleUI::executeLoadOrCreateDatabase()
{
   std::string fileName;

   out_ << "------------------------------------------------\n"
           "State: LoadOrCreateDatabase\n"
           "Type file name of the database: ";

   in_ >> fileName;

   database_.setPathToFile(fileName);

   database_.readDatabase();

   state_ = EConsoleUIState::Home;
}

void ConsoleUI::executeSaveDatabase()
{
   out_ << "------------------------------------------------\n"
           "State: SaveDatabase\n";

   if(database_.getPathFile().empty())
   {
      out_<<"File does not exist!\n";
      state_ = EConsoleUIState::Home;
      return;   
   }

   database_.writeDatabase();

   out_<<"Save the database was successful\n";

   state_ = EConsoleUIState::Home;
}

void ConsoleUI::executeExit()
{
   state_ = EConsoleUIState::Exit;
}

struct State
{
   EConsoleUIState                 state;
   std::function<void(ConsoleUI*)> stateFun;
};

void ConsoleUI::run()
{
   State states[] = {
      {EConsoleUIState::Home,                  &ConsoleUI::executeHome},
      {EConsoleUIState::AddingNewRecord,       &ConsoleUI::executeAddingNewRecord},
      {EConsoleUIState::DisplayEntireDatabase, &ConsoleUI::executeDisplayEntireDatabase},
      {EConsoleUIState::Searching,             &ConsoleUI::executeSearching},
      {EConsoleUIState::Sorting,               &ConsoleUI::executeSorting},
      {EConsoleUIState::DeletingRecords,       &ConsoleUI::executeDeletingRecords},
      {EConsoleUIState::LoadOrCreateDatabase,  &ConsoleUI::executeLoadOrCreateDatabase},
      {EConsoleUIState::SaveDatabase,          &ConsoleUI::executeSaveDatabase},
      {EConsoleUIState::Exit,                  &ConsoleUI::executeExit},
   };

   while(true)
   {
      for(const auto& state : states)
      {
         if(state.state == state_)
         {
            state.stateFun(this);
         }
      }

      if(state_ == EConsoleUIState::Exit)
         break;
   }
}