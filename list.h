#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Student.h"

namespace scolarships
{

    namespace students
    {

        namespace List
        {

            struct Node
            {
                Node * next;
                Student * element;

                Node()
                {
                    next = NULL;
                    element = NULL;
                }

                ~Node()
                {
                    delete element;
                }
            };

            void Create();

            void Destroy();

            void Add(Student * student);

            void Sort( int (*CmpFunc)(Student *, Student *) );

            void Map(void (*CallbackFunc) (Student*));
        }
    }
}

#endif // LIST_H_INCLUDED
