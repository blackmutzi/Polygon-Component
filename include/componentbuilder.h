#ifndef COMPONENTBUILDER_H
#define COMPONENTBUILDER_H

#include "databasemanager.h"

namespace Arch
{

class ComponentBuilder
{
    public:
        ComponentBuilder();

        IComponent * createComponent( const std::string & component_name , const std::string & database_name );

        template < typename Component >
        Component * createComponent( const std::string & database_name );

        template < typename Component >
        IDatabase * createDatabase( const std::string & database_name );

        void removeComponent( const std::string & database_name , unsigned int id );
        void deleteComponent( IComponent * );

        void deleteDatabase( const std::string & database_name );
};


}

#include "componentbuilder.temp"

#endif // COMPONENTBUILDER_H
