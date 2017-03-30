#include "databasemanager.h"

using namespace Arch;

DatabaseManager * DatabaseManager::ptrInstance = nullptr;

DatabaseManager * DatabaseManager::getSingletonPtr(void)
{
    if( ptrInstance == nullptr )
    {
        ptrInstance = new DatabaseManager();
    }

    return ptrInstance;
}

void DatabaseManager::addDatabase( IDatabase * database )
{
    m_database_map.insert( IDatabaseMap::value_type( database->getDatabaseName() , database ) );
}

bool DatabaseManager::hasDatabase( const std::string & database_name )
{
    if( getDatabase( database_name ) != nullptr )
            return true;

    return false;
}

void DatabaseManager::deleteDatabase( const std::string & database_name )
{
    IDatabase * database = getDatabase( database_name );
    database->finish();

    removeDatabase( database_name );
    delete database;
}

void DatabaseManager::removeDatabase( const std::string & database_name )
{
     if( hasDatabase( database_name ) )
     {
          m_database_map.erase( database_name );
     }
}

IDatabase * DatabaseManager::getDatabase(const string & database_name )
{
    IDatabaseMap::iterator database_it = m_database_map.find( database_name );

    if( database_it != m_database_map.end() )
            return database_it->second;

    return nullptr;
}
