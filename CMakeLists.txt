cmake_minimum_required(VERSION 3.10)
project(RacingSimulator)

include_directories(${CMAKE_SOURCE_DIR}/MainProject)
include_directories(${CMAKE_SOURCE_DIR}/ImplementingClasses)

add_library(ImplementingClasses ImplementingClasses/TransportVehicle.cpp ImplementingClasses/AllTerrainBoots.cpp ImplementingClasses/Camel.cpp ImplementingClasses/Centaur.cpp ImplementingClasses/FastCamel.cpp ImplementingClasses/Eagle.cpp ImplementingClasses/FlyingCarpet.cpp ImplementingClasses/Broomstick.cpp ImplementingClasses/AirTransport.cpp ImplementingClasses/GroundTransportation.cpp)

add_executable(MainProject MainProject/MainProject.cpp MainProject/Generator.cpp)

target_link_libraries(MainProject PRIVATE ImplementingClasses)

add_custom_target(run COMMAND ${CMAKE_CURRENT_BINARY_DIR}/MainProject DEPENDS MainProject WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})