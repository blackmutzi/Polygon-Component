#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "stdafx.h"

namespace Arch
{

struct ComponentLocation
{
    std::string  database_name;
    unsigned int component_id;
};

class IComponent
{
    using IComponentMap = std::map< std::string , ComponentLocation >;

    public:
        IComponent( const std::string & component_name );
        virtual ~IComponent() = default;

        void setID( unsigned int );
        void setDatabaseName( const std::string & database_name );
        void setResourceName( const std::string & resource_name );

        unsigned int getID(void) const;
        const std::string getComponentName(void) const;
        const std::string getDatabaseName(void) const;
        const std::string getResourceName(void) const;

        virtual void attach( IComponent * component );

        bool isAttached( const std::string & component_name );
        ComponentLocation getLocation( const std::string & component_name );

    protected:

        void _attach( const std::string & component_name , ComponentLocation & location );

        IComponentMap m_components;

        std::string   m_database_name;
        std::string   m_component_name;
        std::string   m_resource_name;
        unsigned int  m_id;
};

}

#endif // ICOMPONENT_H
