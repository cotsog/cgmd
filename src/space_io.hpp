#ifndef __SPACE_IO_HPP
#define __SPACE_IO_HPP

#include "space.hpp"

class SpaceWriter {
public:
    virtual void save(const Space& space) const = 0;
};

class SpaceReader {
public:
    virtual void load(Space& space) const = 0;
};

#endif /* __SPACE_IO_HPP */
