#ifndef SEMESTRALWORK_BINARYWRITER_H
#define SEMESTRALWORK_BINARYWRITER_H

#include <string>
#include <fstream>
#include "../Game/Exportable.h"

namespace SW {
    class Exportable;
    class BinaryWriter {
    public:
        BinaryWriter() = default;
        explicit BinaryWriter(const std::string & path);
        bool open(const std::string & path);
        template<typename T> inline void write(const T & value) {
            this->stream.write((char *)&value, sizeof(value));
        }
        template<typename T> inline void writeDirect(T value) {
            this->stream.write((char *)&value, sizeof(value));
        }
        void writeObject(const Exportable * object);
        void writeObject(const Exportable & object);
        void writeString(const std::string & value);
        void close();

    private:
        std::fstream stream;
    };
}

#endif
