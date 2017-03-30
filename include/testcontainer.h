#ifndef TESTCONTAINER_H
#define TESTCONTAINER_H

#include "stdafx.h"
#include "icomponent.h"

namespace Arch
{


class TestContainer : public IComponent
{
public:
    TestContainer();

    int getTestContainerFunction(void);

};

}

#endif // TESTCONTAINER_H
