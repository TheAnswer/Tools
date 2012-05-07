# Copyright (C) 2007 <SWGEmu>. All rights reserved.
# Distribution of this file for usage outside of Core3 is prohibited.

cmake_minimum_required(VERSION 2.8)

PROJECT(AppearanceTemplates)

# set cmake find moudles path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

# find mysql includes and libraries
find_package(MySql REQUIRED)
INCLUDE_DIRECTORIES(${MYSQL_INCLUDE_DIR})
set(LIBS ${LIBS} ${MYSQL_LIBRARY})

# find berkeley includes and libraries
find_package(Berkeley REQUIRED)
INCLUDE_DIRECTORIES(${DB_INCLUDE_DIR})
set(LIBS ${LIBS} ${DB_LIBRARIES})

# add appearancetemplates sources
FILE(GLOB_RECURSE appearancetemplates_sources "*.cpp") 

# add appearancetemplates includes
INCLUDE_DIRECTORIES(.)

# create appearancetemplates library
ADD_LIBRARY(appearancetemplates ${appearancetemplates_sources})