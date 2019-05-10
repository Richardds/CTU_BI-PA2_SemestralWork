#include "Trace.h"

SW::Trace::Trace() : available(false), _line(0){
    //
}

SW::Trace::Trace(const std::string & file,
                 unsigned int line,
                 const std::string & function) : available(true), _line(line) {
    this->_file = file;
    this->_function = function;
}

std::string SW::Trace::toString(bool hide_fs) const {
    std::string output;
    if (!hide_fs) {
        output += this->_file + ":" + std::to_string(this->_line) + " ";
    }
    return output + this->_function;
}
