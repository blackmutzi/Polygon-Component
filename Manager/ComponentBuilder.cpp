#include "componentbuilder.h"

using namespace Arch;

ComponentBuilder::ComponentBuilder(){}

IComponent * ComponentBuilder::createComponent(const string &component_name, const string &database_name)
{
    DatabaseManager * manager   = DatabaseManager::getSingletonPtr();
    IDatabase       * database  = nullptr;
    IComponent      * component = nullptr;

    if( manager->hasDatabase( database_name ) )
    {
        database  = manager->getDatabase( database_name );
        component = new IComponent( component_name );
        database->addContainer( component );
    }
    else
    {
        database  = createDatabase<IComponent>( database_name );
        component = new IComponent( component_name );
        database->addContainer( component );
    }

    return component;
}

void ComponentBuilder::removeComponent(const string &database_name, unsigned int id)
{
    DatabaseManager * manager = DatabaseManager::getSingletonPtr();

    if( manager->hasDatabase( database_name ) )
    {
        IDatabase * database = manager->getDatabase( database_name );
        database->removeContainer( id );
    }
}

void ComponentBuilder::deleteComponent(IComponent * component )
{
    //--------------
    // Remove from Database
    //--------------
    removeComponent( component->getDatabaseName() , component->getID() );

    //------------------
    // Delete Pointer
    //------------------
    delete component;
}

void ComponentBuilder::deleteDatabase( const std::string & database_name )
{
     DatabaseManager * manager = DatabaseManager::getSingletonPtr();
     manager->deleteDatabase( database_name );
}




