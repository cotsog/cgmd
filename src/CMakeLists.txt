set(CPP_FILES
    vector3d.cpp lipid.cpp
    )

set(HPP_FILES
    vector3d.hpp lipid.hpp
    )

add_library(mylipid SHARED ${CPP_FILES} ${HPP_FILES})
