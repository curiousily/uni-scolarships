#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

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

        char * GetAbbreviatedStudentName(Student * student, int length);

        int GetStudentScolarship(Student * student, int m, int k);

    }

}

#endif // STUDENT_H_INCLUDED
