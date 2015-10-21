set(CPP_FILES
    bead_type.cpp vector3d.cpp molecule.cpp cgspace.cpp model.cpp
    force_field.cpp
    )

set(HPP_FILES
    bead_type.hpp vector3d.hpp molecule.hpp cgspace.hpp model.hpp
    force_field.hpp
    )

add_library(mylipid SHARED ${CPP_FILES} ${HPP_FILES})
