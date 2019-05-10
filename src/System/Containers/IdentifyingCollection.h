#ifndef SEMESTRALWORK_IDENTIFYINGCOLLECTION_H
#define SEMESTRALWORK_IDENTIFYINGCOLLECTION_H

#include "../../Core/core.h"
#include <map>

namespace SW {
    /**
     * Container which identifies objects by it's identifier.
     * @tparam T
     */
    template <typename T>
    class IdentifyingCollection : public std::map<uint32_t, T> {
    public:
        /**
         * Constructor
         */
        IdentifyingCollection() : _next_id(1) {}

        /**
         * Adds item to container. Increases next object identifier by one.
         * @param item Object to be stored
         * @return Identifier of stored object in container
         */
        uint32_t add(T item) {
            this->insert(std::pair<uint32_t, T>(this->_next_id, item));
            return this->_next_id++;
        }

        /**
         * Finds object by given identifier.
         * @param id Identifier of object
         * @return object if identifier exists, otherwise nullptr
         */
        T get(uint32_t id) {
            auto iterator = this->find(id);
            return iterator != end(*this) ? iterator->second : nullptr;
        }

        /**
         * Removes object from container by given identifier.
         * @param id Identifier of object
         */
        void remove(uint32_t id) {
            this->erase(id);
        }

    private:
        uint32_t _next_id;
    };
}

#endif
