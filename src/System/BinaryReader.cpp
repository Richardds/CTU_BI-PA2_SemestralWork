#include "BinaryReader.h"

SW::BinaryReader::BinaryReader(const std::string & path) {
    this->open(path);
}

bool SW::BinaryReader::open(const std::string & path) {
    this->stream.open(path, std::ios::in | std::ios::binary);
    return !this->stream.fail();
}

void SW::BinaryReader::readString(std::string & value) {
    std::getline(this->stream, value, '\0');
}

void SW::BinaryReader::close() {
    this->stream.close();
}
