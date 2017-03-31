//
// Created by mk on 29.03.2017.
//
#include <string>
#include <cstring>
#include <algorithm>

namespace memorychunk {
#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H


    class MemoryChunk {
    public:
        MemoryChunk(const MemoryChunk &memoryChunk);

        MemoryChunk(MemoryChunk &&memoryChunk);

        MemoryChunk &operator=(const MemoryChunk &memoryChunk);

        MemoryChunk &operator=(MemoryChunk &&memoryChunk);

        ~MemoryChunk();

        MemoryChunk(size_t sz);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;

    private:
        int8_t *pointer;
        size_t pointerLength;
    };


#endif //JIMP_EXERCISES_MEMORYCHUNK_H
}

