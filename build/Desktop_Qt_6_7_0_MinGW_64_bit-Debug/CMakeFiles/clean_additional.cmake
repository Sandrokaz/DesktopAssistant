# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DesktopAssistant_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DesktopAssistant_autogen.dir\\ParseCache.txt"
  "DesktopAssistant_autogen"
  )
endif()
