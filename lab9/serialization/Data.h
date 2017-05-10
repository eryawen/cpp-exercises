//
// Created by mk on 09.05.2017.
//

#ifndef JIMP_EXERCISES_DATA_H
#define JIMP_EXERCISES_DATA_H


#include "Serialization.h"

namespace academia {
    class Serializer;

    class Serializable {
    public:
        virtual void Serialize(academia::Serializer *serializer) const = 0;

        virtual ~Serializable() {}
    };

    class Room : public Serializable {

    public:
        enum RoomType {
            LECTURE_HALL,
            CLASSROOM,
            COMPUTER_LAB
        };

        std::string roomTypeAsString(RoomType type) const {
            switch (type) {
                case RoomType::LECTURE_HALL:
                    return "LECTURE_HALL";
                case RoomType::CLASSROOM:
                    return "CLASSROOM";
                case RoomType::COMPUTER_LAB:
                    return "COMPUTER_LAB";
            }
        }

        Room(int id, const std::string &name, Room::RoomType type) : id(id), name(name), type(type) {}

        ~Room() {};

        virtual void Serialize(Serializer *serializer) const override;

    private:
        int id;
        std::string name;
        RoomType type;
    };

    class Building : public Serializable {
    public:

        Building(int id, const std::string &name, std::vector<Room> rooms) : id(id), name(name),
                                                                             rooms(rooms) {};

        virtual void Serialize(Serializer *serializer) const override;

        ~Building() {}

    private:
        int id;
        std::string name;
        std::vector<Room> rooms; //(?) with const doesn't work
    };
}

#endif //JIMP_EXERCISES_DATA_H


//todo ref/obj, const