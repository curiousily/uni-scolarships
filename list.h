#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Student.h"

namespace scolarships
{

    namespace students
    {

        namespace List
        {

            void Create(int maxSize);

            void Destroy();

            void Add(Student * student);

            Student * Get(const int & index);

            int Size();

            void Sort( int (*CmpFunc)(Student *, Student *) );

            void Map( void (*CallbackFunc) (Student *) );
        }
    }
}

#endif // LIST_H_INCLUDED
