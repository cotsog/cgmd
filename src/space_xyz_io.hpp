#ifndef __SPACE_XYZ_IO_HPP
#define __SPACE_XYZ_IO_HPP

#include "space_io.hpp"

class SpaceXYZWriter : public SpaceSaver {
public:
    SpaceXYZWriter(const std::string& fname);
    void save(const Space& space);

protected:
    const std::string _fname;
};

#endif /* __SPACE_XYZ_IO_HPP */
