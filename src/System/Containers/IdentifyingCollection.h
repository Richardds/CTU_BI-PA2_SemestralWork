#ifndef SEMESTRALWORK_IDENTIFYINGCOLLECTION_H
#define SEMESTRALWORK_IDENTIFYINGCOLLECTION_H

#include "../../Core/core.h"
#include <map>

namespace SW {
    template <typename T>
    class IdentifyingCollection : public std::map<uint32_t, T> {
    public:
        IdentifyingCollection() : _next_id(1) {}

        uint32_t add(T item) {
            this->insert(std::pair<uint32_t, T>(this->_next_id, item));
            return this->_next_id++;
        }

        T get(uint32_t id) {
            auto iterator = this->find(id);
            return iterator != end(*this) ? iterator->second : nullptr;
        }

        void remove(uint32_t id) {
            this->erase(id);
        }

    private:
        uint32_t _next_id;
    };
}

#endif
