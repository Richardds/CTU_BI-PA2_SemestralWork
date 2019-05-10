#ifndef SEMESTRALWORK_BINARYREADER_H
#define SEMESTRALWORK_BINARYREADER_H

#include <string>
#include <fstream>
#include "../Game/Exportable.h"

namespace SW {
    /**
     * Binary stream reader
     */
    class BinaryReader {
    public:
        /**
         * Default constructor
         */
        BinaryReader() = default;
        /**
         * Constructor
         * @param path File path
         */
        explicit BinaryReader(const std::string & path);
        /**
         * Opens file for reading.
         * @param path File path
         * @return true on success, otherwise false
         */
        bool open(const std::string & path);
        /**
         * Reads value from file to reference.
         * @tparam T
         * @param value Reference to value
         */
        template<typename T> inline void read(T & value) {
            this->stream.read((char *)&value, sizeof(value));
        }
        /**
         * Reads std::string from file.
         * @param value Reference to std::string
         */
        void readString(std::string & value);
        /**
         * Safely closes the stream.
         */
        void close();

    private:
        std::fstream stream;
    };
}

#endif
