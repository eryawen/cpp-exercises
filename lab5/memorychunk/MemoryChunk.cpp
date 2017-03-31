//
// Created by mk on 29.03.2017.
//
#include <iostream>
#include "MemoryChunk.h"

namespace memorychunk {

    MemoryChunk::MemoryChunk(const MemoryChunk &memoryChunk) {

        pointerLength = memoryChunk.pointerLength;
        pointer = new int8_t[pointerLength];
        memcpy(pointer, memoryChunk.pointer, pointerLength * sizeof(int8_t));
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&memoryChunk) : pointer{nullptr},
                                                          pointerLength{0} {
        std::swap(pointer, memoryChunk.pointer);
        std::swap(pointerLength, memoryChunk.pointerLength);
    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &memoryChunk) {
        if (this == &memoryChunk) {
            return *this;
        }
        delete pointer;
        pointerLength = memoryChunk.pointerLength;
        pointer = new int8_t[pointerLength];
    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&memoryChunk) {
        if (this == &memoryChunk) {
            return memoryChunk;
        }
        delete[] pointer;
        pointer = nullptr;
        std::swap(pointer, memoryChunk.pointer);
        std::swap(pointerLength, memoryChunk.pointerLength);
        return *this;
    }

    MemoryChunk::~MemoryChunk() {
        delete[] pointer;
        pointer = nullptr;
    }

    MemoryChunk::MemoryChunk(size_t sz) {
        pointerLength = sz;
        pointer = new int8_t[sz];
    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        return pointer + offset;
    }

    size_t MemoryChunk::ChunkSize() const {
        return pointerLength;
    }
}
