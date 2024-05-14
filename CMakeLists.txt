cmake_minimum_required (VERSION 2.6)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_SYSROOT $ENV{CMAKE_SYSROOT})
set(CMAKE_C_STANDARD 99)
# set(CMAKE_BUILD_TYPE MinsizeRel)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)

set(pkgName "oort_agent_sdk_interface")

# local change: libcurl 7.40 is what's available on board
find_package(CURL 7.40.0 REQUIRED)
if(CURL_FOUND)
	include_directories(${CURL_INCLUDE_DIR})
	set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else(CURL_FOUND)
	message(FATAL_ERROR "Could not find the CURL library and development files.")
endif()

set(SRCS
    src/list.c
    src/apiKey.c
    src/apiClient.c
    external/cJSON.c
    model/object.c
    model/adcs_command_request.c
    model/adcs_command_response.c
    model/adcs_euler_t.c
    model/adcs_hk.c
    model/adcs_quat_t.c
    model/adcs_response.c
    model/adcs_target.c
    model/adcs_xyz_float_t.c
    model/available_files_response.c
    model/error_response.c
    model/file_info.c
    model/retrieve_file_request.c
    model/send_file_request.c
    model/send_file_response.c
    model/send_options.c
    model/tags.c
    model/tfrs_response.c
    model/ttl_params.c
    api/SdkAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/keyValuePair.h
    external/cJSON.h
    model/object.h
    model/adcs_command_request.h
    model/adcs_command_response.h
    model/adcs_euler_t.h
    model/adcs_hk.h
    model/adcs_quat_t.h
    model/adcs_response.h
    model/adcs_target.h
    model/adcs_xyz_float_t.h
    model/available_files_response.h
    model/error_response.h
    model/file_info.h
    model/retrieve_file_request.h
    model/send_file_request.h
    model/send_file_response.h
    model/send_options.h
    model/tags.h
    model/tfrs_response.h
    model/ttl_params.h
    api/SdkAPI.h

)

# Add library with project file with projectname as library name
add_library(${pkgName} SHARED ${SRCS} ${HDRS})
add_library(${pkgName}_static STATIC ${SRCS} ${HDRS})
# Link dependent libraries
target_link_libraries(${pkgName} ${CURL_LIBRARIES} )
#install library to destination
install(TARGETS ${pkgName} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(TARGETS ${pkgName}_static DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

install(DIRECTORY api model external include DESTINATION ${CMAKE_INSTALL_PREFIX}/include/oort)

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled libary to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-SdkAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable doesnot support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created libary to executable and dependent libary curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
