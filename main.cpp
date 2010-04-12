#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

using namespace std;

namespace utility
{
    namespace output
    {

        void Write(const char * line, ostream & outputStream)
        {
            outputStream << line;
        }

        void Write(const char * line)
        {
            Write(line, cout);
        }

        void WriteLine(const char * line, ostream & outputStream, const char * format = "", ...)
        {
            Write(line, outputStream);
            va_list argumentList;
            va_start(argumentList, format);
            for (int i = 0; format[i] != '\0'; i++)
            {
                if (format[i] == 'i')
                {
                    cout << va_arg(argumentList, int);
                }
                else if (format[i] == 's')
                {
                    cout << va_arg(argumentList, char *);
                }
            }
            va_end(argumentList);
            outputStream << endl;
        }

        void WriteLine(const char * line)
        {
            WriteLine(line, cout);
        }

        void WriteEmptyLine(ostream & outputStream)
        {
            WriteLine("", outputStream);
        }

        void WriteEmptyLine()
        {
            WriteLine("");
        }
    }

    namespace input
    {

        template <class NumberType>
        NumberType ReadNumber(const NumberType & minValue, const NumberType & maxValue, istream & inputStream)
        {
            NumberType result;
            while (true)
            {
                inputStream >> result;
                if (inputStream && result >= minValue && result <= maxValue)
                {
                    return result;
                }
            }
        }

        template <class NumberType>
        NumberType ReadNumber(const NumberType & minValue, const NumberType & maxValue)
        {
            return ReadNumber(minValue, maxValue, cin);
        }

        char * ReadString(const int & minLength, const int & maxLength, istream & inputStream)
        {
            char * result = new char[maxLength];
            while (true)
            {
                inputStream.getline(result, maxLength + 300);
                int resultLength = inputStream.gcount() - 1;
                if (inputStream && resultLength >= minLength && resultLength <= maxLength)
                {
                    return result;
                }
            }
        }

        char * ReadString(const int & minLength, const int & maxLength)
        {
            return ReadString(minLength, maxLength, cin);
        }

    }
}

namespace scolarships
{

    namespace students
    {

        struct Student
        {
            int number;
            char * name;
            double averageGrade;
            double averageIncome;
        };

        char * GetStudentAbbreviatedName(Student * student, int length)
        {
            char * result = new char[length];
            char * temp = strtok(student->name , " ");
            char * firstAndSurName = new char[5];

            int spaceCount = 0;
            while(temp != NULL)
            {
                if(spaceCount < 2)
                {
                    strncat(firstAndSurName, temp, 1);
                    strcat(firstAndSurName, ".");
                }
                else
                {
                    firstAndSurName[4] = '\0';
                    strcat(result, temp);
                    strcat(result, " ");
                    strcat(result, firstAndSurName);
                }
                temp = strtok(NULL, " ");
                spaceCount++;
            }
            return result;
        }

        namespace List
        {

            typedef scolarships::students::Student ElementType;

            struct Node
            {
                Node * next;
                ElementType * element;

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

            int elementCount;
            Node * head = NULL;
            Node * tail = NULL;

            void Create()
            {
                elementCount = 0;
            }

            void Destroy()
            {
                Node * elementToDelete = head;
                while (elementToDelete != NULL)
                {
                    Node * temp = elementToDelete;
                    elementToDelete = elementToDelete->next;
                    delete temp;
                }
                elementCount = 0;
            }

            void Add(ElementType * element)
            {
                Node * newElement = new Node;
                newElement->element = element;
                if (head == NULL)
                {
                    head = tail = newElement;
                }
                else
                {
                    tail->next = newElement;
                    tail = tail->next;
                }
                elementCount++;
            }

            void Remove(int index)
            {
                if (index + 1 > elementCount)
                {
                    return;
                }
                if (index == 0)
                {
                    Node * temp = head;
                    head = head->next;
                    delete temp;
                    elementCount--;
                    return;
                }
                if (index + 1 == elementCount)
                {
                    Node * element = head;
                    while (element->next != tail)
                    {
                        element = element->next;
                    }
                    tail = element;
                    Node * temp = element->next;
                    element->next = NULL;
                    delete temp;
                    elementCount--;
                    return;
                }
                int position = 0;
                Node * element = head;
                while (element != NULL)
                {
                    if (index == position)
                    {
                        Node * temp = element->next;
                        element->next = element->next->next;
                        delete temp;
                        elementCount--;
                        return;
                    }
                    element = element->next;
                    position++;
                }
            }

            int Size()
            {
                return elementCount;
            }

            bool IsEmpty()
            {
                return elementCount == 0;
            }

            void Sort( int (*CmpFunc)(ElementType, ElementType) )
            {

            }

            void Map( void (*CallbackFunc) (ElementType*) )
            {
                Node * node = head;
                while (node != NULL)
                {
                    CallbackFunc(node->element);
                    node = node->next;
                }
            }

            ElementType * Find( bool (*ConstraintFunc) (ElementType*) )
            {
                Node * node = head;
                while (node != NULL)
                {
                    if (ConstraintFunc(node->element))
                    {
                        return node->element;
                    }
                    node = node->next;
                }
                return NULL;
            }
        }
    }
}


using namespace scolarships::students;

using namespace scolarships::students::List;

using namespace utility::input;
using namespace utility::output;


void InitializeStudentList()
{
    Write("Please enter the number of students that are competing for scolarships : ");
    int numberOfStudents = ReadNumber(10, 500);

    ElementType * student;
    for (int i = 0; i < numberOfStudents; i++)
    {
        int number = i + 1;
        WriteLine("You are entering information for student #", cout, "i", number);
        student = new ElementType;

        student->number = number;

        Write("name : ");
        student->name = ReadString(10, 50);
        WriteEmptyLine();

        cout << GetStudentAbbreviatedName(student, 50) << endl;

        Write("average grade : ");
        student->averageGrade = ReadNumber(3.00, 6.00);
        WriteEmptyLine();

        Write("average family income : ");
        student->averageIncome = ReadNumber(1.00, 999.99);
        WriteEmptyLine();

        List::Add(student);
    }

}

void DisplayStudentList()
{

}

void DisplayStudentStanding()
{

}

void InitializeApp()
{
    List::Create();
}

void ExitApp()
{
    List::Destroy();
}

int main()
{
    InitializeApp();

    WriteLine("Welcome to the virtual scolarship list program!");
    WriteEmptyLine();

    InitializeStudentList();
    DisplayStudentList();
    DisplayStudentStanding();

    WriteLine("Bye bye!");

    ExitApp();

    return 0;
}
