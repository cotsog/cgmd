set(CPP_FILES
    vector3d.cpp lipid.cpp molecule.cpp cgspace.cpp
    )

set(HPP_FILES
    vector3d.hpp lipid.hpp molecule.hpp cgspace.hpp
    )

add_library(mylipid SHARED ${CPP_FILES} ${HPP_FILES})
