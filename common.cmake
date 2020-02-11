
macro(vardump)
    message(STATUS "variables------------------------------------------{")
    get_cmake_property(_vars VARIABLES)
    foreach (_var ${_vars})
        message(STATUS "${_var}=${${_var}}")
    endforeach()
    message(STATUS "variables------------------------------------------}")
endmacro()

if (APPLE)
    list(APPEND CMAKE_PREFIX_PATH /opt/local/ /opt/local/lib)
    set(ENV{PATH} "$ENV{PATH}:/opt/local/bin")
endif()

message(STATUS ${PROJECT_NAME})
