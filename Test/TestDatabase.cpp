#include "testdatabase.h"

using namespace Arch;

TestDatabase::TestDatabase()
    : ITempDatabase<TestContainer>("TestDatabase")
{

}



TestContainer * TestDatabase::getTestContainer( unsigned int id )
{
    return ( TestContainer * ) ITempDatabase::getContainer( id );
}

