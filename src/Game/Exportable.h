#ifndef SEMESTRALWORK_EXPORTABLE_H
#define SEMESTRALWORK_EXPORTABLE_H

#include "../System/BinaryReader.h"
#include "../System/BinaryWriter.h"

namespace SW {
    class BinaryWriter;
    class Exportable {
    public:
        /**
         * Writes current object attributes ot binary stream.
         * @param writer
         */
        virtual void writeToBinaryWriter(BinaryWriter & writer) const = 0;
    };
}

#endif
