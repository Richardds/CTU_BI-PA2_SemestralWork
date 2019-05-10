#ifndef SEMESTRALWORK_BINARYWRITER_H
#define SEMESTRALWORK_BINARYWRITER_H

#include <string>
#include <fstream>
#include "../Game/Exportable.h"

namespace SW {
    class Exportable;
    /**
     * Binary stream writer
     */
    class BinaryWriter {
    public:
        /**
         * Default constructor
         */
        BinaryWriter() = default;
        /**
         * Constructor
         * @param path File path
         */
        explicit BinaryWriter(const std::string & path);
        /**
         * Opens file for writing.
         * @param path File path
         * @return true on success, otherwise false
         */
        bool open(const std::string & path);
        /**
         * Writes value by reference to file.
         * @tparam T
         * @param value Reference to value to be written
         */
        template<typename T> inline void write(const T & value) {
            this->stream.write((char *)&value, sizeof(value));
        }
        /**
         * Writes value to file.
         * @tparam T
         * @param value Value to be written
         */
        template<typename T> inline void writeDirect(T value) {
            this->stream.write((char *)&value, sizeof(value));
        }
        /**
         * Packs and writes exportable object to file.
         * @param object Exportable object
         */
        void writeObject(const Exportable * object);
        /**
         * Packs and writes exportable object to file.
         * @param object Exportable object
         */
        void writeObject(const Exportable & object);
        /**
         * Writes std::string to file.
         * @param object std::string to be written.
         */
        void writeString(const std::string & value);
        /**
         * Safely closes the stream.
         */
        void close();

    private:
        std::fstream stream;
    };
}

#endif
