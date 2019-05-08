#ifndef SEMESTRALWORK_BINARYREADER_H
#define SEMESTRALWORK_BINARYREADER_H

#include <string>
#include <fstream>
#include "../Game/Exportable.h"

namespace SW {
    class BinaryReader {
    public:
        BinaryReader() = default;
        explicit BinaryReader(const std::string & path);
        bool open(const std::string & path);
        template<typename T> inline void read(T & value) {
            this->stream.read((char *)&value, sizeof(value));
        }
        void readString(std::string & value);
        void close();

    private:
        std::fstream stream;
    };
}

#endif
