# Install script for directory: C:/dev/engine/csc3204/lib/assimp/code

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0.1")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/engine/csc3204/lib/assimp/build/code/Debug/assimpD.lib")
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/engine/csc3204/lib/assimp/build/code/Release/assimp.lib")
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/engine/csc3204/lib/assimp/build/code/MinSizeRel/assimp.lib")
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/engine/csc3204/lib/assimp/build/code/RelWithDebInfo/assimp.lib")
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0.1")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0.1")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "C:/dev/engine/csc3204/lib/assimp/build/code/Debug/assimpD.dll")
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "C:/dev/engine/csc3204/lib/assimp/build/code/Release/assimp.dll")
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "C:/dev/engine/csc3204/lib/assimp/build/code/MinSizeRel/assimp.dll")
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "C:/dev/engine/csc3204/lib/assimp/build/code/RelWithDebInfo/assimp.dll")
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0.1")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/anim.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/ai_assert.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/camera.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/color4.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/color4.inl"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/config.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/defs.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/cfileio.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/light.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/material.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/material.inl"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/matrix3x3.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/matrix3x3.inl"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/matrix4x4.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/matrix4x4.inl"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/mesh.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/postprocess.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/quaternion.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/quaternion.inl"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/scene.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/metadata.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/texture.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/types.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/vector2.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/vector2.inl"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/vector3.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/vector3.inl"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/version.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/cimport.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/importerdesc.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/Importer.hpp"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/DefaultLogger.hpp"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/ProgressHandler.hpp"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/IOStream.hpp"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/IOSystem.hpp"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/Logger.hpp"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/LogStream.hpp"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/NullLogger.hpp"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/cexport.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/Exporter.hpp"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "C:/dev/engine/csc3204/lib/assimp/code/../include/assimp/Compiler/poppack1.h"
    "C:/dev/engine/csc3204/lib/assimp/code/pstdint.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")

