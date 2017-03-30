#include "icomponent.h"

using namespace Arch;

IComponent::IComponent( const std::string & component_name )
    : m_component_name( component_name ) , m_id(0)
{
    m_database_name = "";
    m_resource_name = "";
}

const std::string IComponent::getComponentName(void) const
{
    return m_component_name;
}

unsigned int IComponent::getID(void) const
{
    return m_id;
}

void IComponent::setID(unsigned int id)
{
    m_id = id;
}

void IComponent::setResourceName(const string &resource_name)
{
    m_resource_name = resource_name;
}

void IComponent::setDatabaseName(const string &database_name)
{
    m_database_name = database_name;
}

const std::string IComponent::getResourceName(void) const
{
    return m_resource_name;
}

const std::string IComponent::getDatabaseName(void) const
{
    return m_database_name;
}

void IComponent::attach( IComponent * component )
{
    if( component->getID() != 0 )
    {
        ComponentLocation _location;
        _location.component_id   = component->getID();
        _location.database_name  = component->getDatabaseName();

        _attach( component->getComponentName() , _location );
    }
}

void IComponent::_attach( const std::string & component_name , ComponentLocation & location )
{
    m_components.insert( IComponentMap::value_type( component_name , location ));
}

bool IComponent::isAttached( const std::string & component_name )
{
    ComponentLocation location = getLocation( component_name );

    if( location.component_id != 0 )
             return true;

    return false;
}

ComponentLocation IComponent::getLocation(const string & component_name )
{
    IComponentMap::iterator it = m_components.find( component_name );
    ComponentLocation component;

    component.component_id  = 0;
    component.database_name = "";

    if( it != m_components.end() )
          component = (ComponentLocation) it->second;

    return component;
}
