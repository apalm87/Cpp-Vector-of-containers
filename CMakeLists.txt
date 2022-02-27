set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(TARGET_NAME main)      # program name
set(LIB_NAME mylib)      # lib name


# Create a Shared Library
add_library(${LIB_NAME}
  SHARED
    containers.h
    containers.cpp
  )
# If the library uses the 3rd party lib, you need to include it here
target_include_directories(${LIB_NAME} PUBLIC ../externals/csvstream/)
# 
# Note: In windows, the executable name will be: ca.exe
add_executable(${TARGET_NAME} main.cpp)
target_link_libraries(${TARGET_NAME} ${LIB_NAME}) # Link Library

# Include 3rd party libraries, if it is in main
target_include_directories(${TARGET_NAME} PUBLIC ../externals/csvstream/)