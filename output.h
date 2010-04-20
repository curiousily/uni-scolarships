#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include <iostream>

namespace utility
{
    namespace output
    {
        void Write(const char * line, std::ostream & outputStream);

        void Write(const char * line);

        void WriteLine(const char * line, std::ostream & outputStream, const char * format = "", ...);

        void WriteLine(const char * line);

        void WriteEmptyLine(std::ostream & outputStream);

        void WriteEmptyLine();
    }
}


#endif // OUTPUT_H_INCLUDED
