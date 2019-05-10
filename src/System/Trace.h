#ifndef SEMESTRALWORK_TRACE_H
#define SEMESTRALWORK_TRACE_H

#include <string>

namespace SW {
    /**
     * Holds method calling trace.
     */
    class Trace {
    public:
        /**
         * Constructor
         */
        Trace();
        /**
         * Constructor
         * @param file Method source file
         * @param line Method source line number
         * @param function Method name
         */
        Trace(const std::string & file, unsigned int line, const std::string & function);
        /**
         * Converts trace to std::string
         * @param hide_fs Hides file system info if true
         * @return converted std::string
         */
        std::string toString(bool hide_fs = true) const;
    private:
        bool available;
        std::string _file;
        unsigned int _line;
        std::string _function;
    };
}

#endif
