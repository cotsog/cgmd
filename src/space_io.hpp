#ifndef __SPACE_IO_HPP
#define __SPACE_IO_HPP

#include <string>
#include "space.hpp"

class SpaceSaver {
public:
    virtual void save(const Space& space) = 0;
};

#endif /* __SPACE_IO_HPP */
