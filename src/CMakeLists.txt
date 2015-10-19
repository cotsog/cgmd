set(CPP_FILES
    vector3d.cpp
    )

set(HPP_FILES
    vector3d.hpp)

add_library(mylipid SHARED ${CPP_FILES} ${HPP_FILES})
