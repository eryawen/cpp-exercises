//
// Created by mk on 09.05.2017.
//

#include <functional>
#include "Data.h"


namespace academia {
    void Room::Serialize(academia::Serializer *serializer) const {
        serializer->Header("Room");
        serializer->IntegerField("id", id);
        serializer->StringField("name", name);
        serializer->StringField("type", roomTypeAsString(type), true);
        serializer->Footer("Room");
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("Building");
        serializer->IntegerField("id", id);
        serializer->StringField("name", name);
        std::vector<std::reference_wrapper<const Serializable>> wrapper;
        for (const Serializable &room : rooms) {
            wrapper.emplace_back(room);
        }
        serializer->ArrayField("rooms", wrapper, true);
        serializer->Footer("Building");
    }
}

//todo reference_wrapper