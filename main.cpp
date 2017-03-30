#include "stdafx.h"
#include "databasemanager.h"
#include "testdatabase.h"
#include "testcontainer.h"
#include "componentbuilder.h"

int main()
{

      ComponentBuilder * builder           = new ComponentBuilder();
      DatabaseManager  * database_manager  = DatabaseManager::getSingletonPtr();

      IComponent       * shared_attribute  = builder->createComponent("ATTRIBUTE_0102", "ATTRIBUTE_DATABASE");
      TestContainer    * container         = builder->createComponent<TestContainer>("TestDatabase");

      container->attach( shared_attribute );
      builder->deleteComponent( shared_attribute );


      bool isAttached       = container->isAttached("ATTRIBUTE_0102");
      bool exists_database  = false;
      bool exists_container = false;

      if( isAttached )
      {
         ComponentLocation location_attribute = container->getLocation("ATTRIBUTE_0102");

         exists_database   = database_manager->hasDatabase( location_attribute.database_name );

        if( exists_database )
        {
            IDatabase * database = database_manager->getDatabase( location_attribute.database_name );
            exists_container     = database->hasContainer( location_attribute.component_id );
        }

      }

    return 0;
}

