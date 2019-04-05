#ifndef SEMESTRALWORK_TRACE_H
#define SEMESTRALWORK_TRACE_H

#include <string>

namespace SW {
    class Trace {
    public:
        Trace();
        Trace(const std::string & file, unsigned int line, const std::string & function);
        std::string toString(bool hide_system_info = true) const;
    private:
        bool available;
        std::string _file;
        unsigned int _line;
        std::string _function;
    };
}

#endif
