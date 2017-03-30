#ifndef IDATABASE_H
#define IDATABASE_H

#include "stdafx.h"
#include "icomponent.h"

namespace Arch
{

class IDatabase
{
    public:
        explicit IDatabase( const std::string & name );
        virtual ~IDatabase() = default;

        virtual void countReset(void) =0;
        virtual void finish(void) =0;
        virtual void addContainer( IComponent *  )   = 0;
        virtual bool hasContainer( unsigned int  )   = 0;
        virtual void removeContainer( unsigned int ) = 0;

        virtual IComponent * getContainer( unsigned int ) = 0;

        std::string getDatabaseName(void) const;

    protected:

        std::string m_database_name;

};

template< typename Container >
class ITempDatabase : public IDatabase
{
    using ContainerMap    = std::map< unsigned int , Container * >;
    using ContainerVector = std::vector< Container *>;
    using ContainerList   = std::list< Container *>;

    public:
        ITempDatabase( const std::string & name );
        ~ITempDatabase();

        void countReset(void);
        void finish(void);
        void addContainer( IComponent * );
        IComponent * getContainer( unsigned int );

        bool hasContainer     ( unsigned int );
        void removeContainer  ( unsigned int );

        void removeFromMap    ( unsigned int );
        void removeFromVector ( IComponent * );
        void removeFromList   ( IComponent * );

        ContainerMap    getContainerMap();
        ContainerVector getContainerVector();
        ContainerList   getContainerList();

    protected:

        ContainerMap     m_container_map;
        ContainerVector  m_container_vector;
        ContainerList    m_container_list;

    private:

        unsigned int     m_component_id_count;
};

}

#include "itempdatabase.temp"

#endif // IDATABASE_H
