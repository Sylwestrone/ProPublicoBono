#ifndef DISK_H
#define DISK_H

#include <string>

#include "../Morse.h"


class Disk : public Morse
{
    public:
        Disk();
        virtual ~Disk();
        virtual void setExternalInfo(std::string info) {}
        virtual void convert(std::string text) {}
        virtual void convert(int number) {}

    private:
};

#endif // DISK_H
