file(GLOB CPP_FILES *.cpp)
file(GLOB HPP_FILES *.hpp)

add_library(mylipid SHARED ${CPP_FILES} ${HPP_FILES})
