#ifndef SEMESTRALWORK_BINARYWRITER_H
#define SEMESTRALWORK_BINARYWRITER_H

#include <string>
#include <fstream>

namespace SW {
    class BinaryWriter {
    public:
        BinaryWriter() = default;
        explicit BinaryWriter(const std::string & path);
        bool open(const std::string & path);
        template<typename T> inline void write(T & value) {
            this->stream.write((char *)&value, sizeof(value));
        }
        void writeString(const std::string & value);
        void close();

    private:
        std::fstream stream;
    };
}

#endif
