#include "BinaryWriter.h"

SW::BinaryWriter::BinaryWriter(const std::string & path) {
    this->open(path);
}

bool SW::BinaryWriter::open(const std::string & path) {
    this->stream.open(path, std::ios::out | std::ios::binary);
    return !this->stream.fail();
}

void SW::BinaryWriter::writeObject(const SW::Exportable * object) {
    object->writeToBinaryWriter(*this);
}

void SW::BinaryWriter::writeObject(const Exportable & object) {
    object.writeToBinaryWriter(*this);
}

void SW::BinaryWriter::writeString(const std::string & value) {
    this->stream.write(value.c_str(), value.length());
    this->stream << (unsigned char)'\0';
}

void SW::BinaryWriter::close() {
    this->stream.close();
}
