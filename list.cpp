#include <stdio.h>
#include "list.h"

const int MAX_STUDENTS_ALLOWED = 500;

int studentCount = 0;
int maxStudents = 9999;
scolarships::students::Student * studentList[MAX_STUDENTS_ALLOWED];

void scolarships::students::List::Create(int maxSize)
{
    studentCount = 0;
    maxStudents = maxSize;
}

void scolarships::students::List::Destroy()
{
    studentCount = 0;
    maxStudents = 9999;
}

int scolarships::students::List::Size()
{
    return studentCount;
}

void scolarships::students::List::Add(Student * student)
{
    if(studentCount > maxStudents)
    {
        return;
    }
    studentList[studentCount++] = student;
}

scolarships::students::Student * scolarships::students::List::Get(const int & index)
{
    return studentList[index];
}

void scolarships::students::List::Sort( int (*CmpFunc)(Student *, Student *) )
{
    for(int i = 1; i < studentCount ; i++)
    {
        Student * student = studentList[i];
        int j = i - 1;
        while (j >= 0 && CmpFunc(studentList[j], student) > 0)
        {
            studentList[j + 1] = studentList[j];
            j--;
        }
        studentList[j + 1] = student;
    }
}

void scolarships::students::List::Map( void (*CallbackFunc) (Student*) )
{
    for(int i = 0; i < Size(); i++)
    {
        CallbackFunc(studentList[i]);
    }
}
