set(CPP_FILES
    vector3d.cpp lipid.cpp molecule.cpp
    )

set(HPP_FILES
    vector3d.hpp lipid.hpp molecule.hpp
    )

add_library(mylipid SHARED ${CPP_FILES} ${HPP_FILES})
