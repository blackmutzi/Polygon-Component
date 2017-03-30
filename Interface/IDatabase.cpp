#include "idatabase.h"

using namespace Arch;

IDatabase::IDatabase( const std::string & name )
    : m_database_name( name )
{}

std::string IDatabase::getDatabaseName( void ) const
{
    return m_database_name;
}
