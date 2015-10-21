set(CPP_FILES
    vector3d.cpp molecule.cpp cgspace.cpp model.cpp
    )

set(HPP_FILES
    vector3d.hpp molecule.hpp cgspace.hpp model.hpp
    )

add_library(mylipid SHARED ${CPP_FILES} ${HPP_FILES})
