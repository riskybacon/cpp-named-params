#
# Adds an executable. Takes a target name and a list of files
# to build the target
#
# Variables that should be set prior to calling this macro:
#
# PROJECT_INCLUDE_DIRS
#  Path to this project's header files
# CPP_LANG_FLAGS
#   C++ language flags, for example -std=c++14
macro(proj_add_executable TARGET)
  cmake_parse_arguments(
    PARSED_ARGS
    ""
    "OUTPUT_PATH"
    "SRC"
    ${ARGN}
  )

  include_directories(${PROJ_INCLUDE_DIRS})

  add_executable(${TARGET} ${PARSED_ARGS_SRC})

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_LANG_FLAGS}")

  target_link_libraries(${TARGET} ${PROJ_LIBRARIES})

  # Set target properties
  if(PARSED_ARGS_OUTPUT_PATH)
    set_target_properties(${TARGET} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY ${PARSED_ARGS_OUTPUT_PATH})
    set_target_properties(${TARGET} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PARSED_ARGS_OUTPUT_PATH})
    set_target_properties(${TARGET} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PARSED_ARGS_OUTPUT_PATH})
  endif()

endmacro()
