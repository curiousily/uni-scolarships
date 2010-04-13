#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include <iostream>

using namespace std;

namespace utility
{
    namespace output
    {
        void Write(const char * line, ostream & outputStream);

        void Write(const char * line);

        void WriteLine(const char * line, ostream & outputStream, const char * format = "", ...);

        void WriteLine(const char * line);

        void WriteEmptyLine(ostream & outputStream);

        void WriteEmptyLine();
    }
}


#endif // OUTPUT_H_INCLUDED
