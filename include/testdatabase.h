#ifndef TESTDATABASE_H
#define TESTDATABASE_H

#include "databasemanager.h"
#include "testcontainer.h"

namespace Arch
{


class TestDatabase : public ITempDatabase< TestContainer >
{
    public:
        TestDatabase();

        //void finish();
        //void addContainer(IComponent *);
        //IComponent * getContainer( unsigned int );


        TestContainer * getTestContainer( unsigned int );
};

}

#endif // TESTDATABASE_H
