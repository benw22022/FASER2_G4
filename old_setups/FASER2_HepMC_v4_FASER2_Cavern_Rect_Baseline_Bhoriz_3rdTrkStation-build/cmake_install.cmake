# Install script for directory: /Users/mcfayden/Work/FASER/FASER2/G4_test/FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_3rdTrkStation

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/mcfayden/Work/FASER/FASER2/G4_test/FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_3rdTrkStation-build/FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_3rdTrkStation")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_3rdTrkStation" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_3rdTrkStation")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/mcfayden/Work/FASER/FASER2/G4_test/geant4.10.07.p02-install/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_3rdTrkStation")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_3rdTrkStation")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/mcfayden/Work/FASER/FASER2/G4_test/FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_3rdTrkStation-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
