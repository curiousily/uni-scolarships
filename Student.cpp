#include <string.h>

#include "Student.h"

char * scolarships::students::GetAbbreviatedStudentName(Student * student, int length)
{
    char * result = new char[length];
    char * temp = strtok(student->name , " ");
    char * firstAndSurName = new char[5];

    int spaceCount = 0;
    while (temp != NULL)
    {
        if (spaceCount < 2)
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

int scolarships::students::GetStudentScolarship(Student * student, int m, int k)
{
    if (student->averageGrade >= 5.50)
    {
        return 100;
    }
    else if (student->averageGrade >= m && student->averageIncome < k)
    {
        return 60;
    }
    else
    {
        return 0;
    }
}
