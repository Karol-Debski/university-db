#ifndef CONSOLE_UI_BUILDER_H
#define CONSOLE_UI_BUILDER_H

#include "database.hpp"

class IRecordBuilder;

enum EConsoleUIState
{
   Home = 0,
   AddingNewRecord,
   DisplayEntireDatabase,
   Searching,
   Sorting,
   DeletingRecords,
   LoadOrCreateDatabase,
   SaveDatabase,
   Exit,
};

using IConsoleInHandler  = std::basic_istream<char>; 
using IConsoleOutHandler = std::basic_ostream<char>;
using IBuilders_t        = std::vector<std::shared_ptr<IRecordBuilder>>;

class ConsoleUI 
{
public:
   ConsoleUI(IConsoleOutHandler& out, 
             IConsoleInHandler&  in, 
             Datebase&           database, 
             const IBuilders_t&  builders);

   ~ConsoleUI() = default;

   void run();

private:
   void executeHome();
   void executeAddingNewRecord();
   void executeDisplayEntireDatabase();
   void executeSearching();
   void executeSorting();
   void executeDeletingRecords();
   void executeLoadOrCreateDatabase();
   void executeSaveDatabase();
   void executeExit();

   IConsoleOutHandler& out_;
   IConsoleInHandler&  in_;
   Datebase&           database_;
   const IBuilders_t&  builders_;
   EConsoleUIState     state_;
};

#endif // CONSOLE_UI_BUILDER_H