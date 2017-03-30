#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "stdafx.h"
#include "idatabase.h"

namespace Arch
{

class DatabaseManager
{
    using IDatabaseMap = std::map< std::string , IDatabase * >;

    private :

        static DatabaseManager * ptrInstance;

        DatabaseManager() = default;
        DatabaseManager( const DatabaseManager & ) = default;

   public:

        static DatabaseManager * getSingletonPtr(void);

        bool hasDatabase( const std::string & database_name );
        void addDatabase( IDatabase * database );

        IDatabase * getDatabase( const std::string & database_name );

        void deleteDatabase( const std::string & database_name );
        void removeDatabase( const std::string & database_name );


   private:

        IDatabaseMap m_database_map;
};

}

#endif // DATABASEMANAGER_H
