CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
CMAKE_POLICY(SET CMP0054 NEW)

# Project name
project(Combattant C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

#basic conf
IF( WIN32 )
    SET( WINDOWS 1 )
ELSEIF( APPLE )
    SET(MACOSX 1)
ELSEIF( UNIX )
    SET(LINUX 1)
ELSEIF( MINGW )
    SET(WINDOWS 1)
ELSEIF( CYGWIN )
    SET(WINDOWS 1)
ELSE()
    MESSAGE("WHAT IS THIS PLATFORM ?")
    RETURN()
ENDIF()

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(INCLUDE_DIRECTORIES "")
set(LINK_LIBS "")

if( LINUX )
set(Combattant_DEFINITIONS LINUX)
elseif(WINDOWS)
set(Combattant_DEFINITIONS WINDOWS)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets 5.10)
find_package(Qt5Core 5.10)

##################################################

function(extract_include_dirs header_files result_varname)
set(header_directories "")
foreach(header in ${header_files})
get_filename_component(tmp ${header} DIRECTORY)
list( APPEND header_directories ${tmp})
endforeach(header in ${header_files})
list(REMOVE_DUPLICATES header_directories)

set(${result_varname} ${header_directories} PARENT_SCOPE)
endfunction(extract_include_dirs)

# =====================================================================================================
# =====================================================================================================
# =====================================================================================================
# =====================================================================================================

file(GLOB_RECURSE COMBATTANTSQT_SRC_FILES RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/CombattantsQT/*.cpp")
file(GLOB_RECURSE COMBATTANTSQT_HEADER_FILES RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/CombattantsQT/*.h*")

extract_include_dirs("${COMBATTANTSQT_HEADER_FILES}" COMBATTANTSQT_INCLUDE_DIRECTORIES)

set( COMBATTANTSQT_INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} ${COMBATTANTSQT_INCLUDE_DIRECTORIES})

set_source_files_properties(COMBATTANTSQT_HEADER_FILES PROPERTIES HEADER_FILE_ONLY TRUE)
add_executable(${PROJECT_NAME}sQT ${COMBATTANTSQT_SRC_FILES} ${COMBATTANTSQT_HEADER_FILES})
target_compile_definitions(${PROJECT_NAME}sQT PUBLIC ${Combattant_DEFINITIONS})
target_include_directories(${PROJECT_NAME}sQT PUBLIC ${COMBATTANTSQT_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME}sQT Qt5::Core Qt5::Widgets)

# =====================================================================================================
# =====================================================================================================
# =====================================================================================================
# =====================================================================================================

file(GLOB_RECURSE COMBATTANTMODEL_SRC_FILES RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/CombattantModelsInModels/*.cpp")
file(GLOB_RECURSE COMBATTANTMODEL_HEADER_FILES RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/CombattantModelsInModels/*.h*")

extract_include_dirs("${COMBATTANTMODEL_HEADER_FILES}" COMBATTANTMODEL_INCLUDE_DIRECTORIES)

set( COMBATTANTMODEL_INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} ${COMBATTANTMODEL_INCLUDE_DIRECTORIES})

set_source_files_properties(COMBATTANTMODEL_HEADER_FILES PROPERTIES HEADER_FILE_ONLY TRUE)
add_executable(${PROJECT_NAME}WithModelsInModels ${COMBATTANTMODEL_SRC_FILES} ${COMBATTANTMODEL_HEADER_FILES})
target_compile_definitions(${PROJECT_NAME}WithModelsInModels PUBLIC ${Combattant_DEFINITIONS})
target_include_directories(${PROJECT_NAME}WithModelsInModels PUBLIC ${COMBATTANTMODEL_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME}WithModelsInModels Qt5::Core Qt5::Widgets)

# =====================================================================================================
# =====================================================================================================
# =====================================================================================================
# =====================================================================================================

file(GLOB_RECURSE COMBATTANTProxy_SRC_FILES RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/CombattantProxy/*.cpp")
file(GLOB_RECURSE COMBATTANTProxy_HEADER_FILES RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/CombattantProxy/*.h*")

extract_include_dirs("${COMBATTANTProxy_HEADER_FILES}" COMBATTANTProxy_INCLUDE_DIRECTORIES)

set( COMBATTANTProxy_INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} ${COMBATTANTProxy_INCLUDE_DIRECTORIES})

set_source_files_properties(COMBATTANTProxy_HEADER_FILES PROPERTIES HEADER_FILE_ONLY TRUE)
add_executable(${PROJECT_NAME}Proxy ${COMBATTANTProxy_SRC_FILES} ${COMBATTANTProxy_HEADER_FILES})
target_compile_definitions(${PROJECT_NAME}Proxy PUBLIC ${Combattant_DEFINITIONS})
target_include_directories(${PROJECT_NAME}Proxy PUBLIC ${COMBATTANTProxy_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME}Proxy Qt5::Core Qt5::Widgets)

# =====================================================================================================
# =====================================================================================================
# =====================================================================================================
# =====================================================================================================

file(GLOB_RECURSE COMBATTANTTreeFlatter_SRC_FILES RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/CombattantTreeFlatter/*.cpp")
file(GLOB_RECURSE COMBATTANTTreeFlatter_HEADER_FILES RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/CombattantTreeFlatter/*.h*")

extract_include_dirs("${COMBATTANTTreeFlatter_HEADER_FILES}" COMBATTANTTreeFlatter_INCLUDE_DIRECTORIES)

set( COMBATTANTTreeFlatter_INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} ${COMBATTANTTreeFlatter_INCLUDE_DIRECTORIES})

set_source_files_properties(COMBATTANTTreeFlatter_HEADER_FILES PROPERTIES HEADER_FILE_ONLY TRUE)
add_executable(${PROJECT_NAME}TreeFlatter ${COMBATTANTTreeFlatter_SRC_FILES} ${COMBATTANTTreeFlatter_HEADER_FILES})
target_compile_definitions(${PROJECT_NAME}TreeFlatter PUBLIC ${Combattant_DEFINITIONS})
target_include_directories(${PROJECT_NAME}TreeFlatter PUBLIC ${COMBATTANTTreeFlatter_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME}TreeFlatter Qt5::Core Qt5::Widgets)
