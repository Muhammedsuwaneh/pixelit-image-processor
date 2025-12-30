# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appPixelItApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appPixelItApp_autogen.dir\\ParseCache.txt"
  "appPixelItApp_autogen"
  )
endif()
