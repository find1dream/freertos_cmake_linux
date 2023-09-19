project(posix_demo)
cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(FREERTOS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/freertos")

include_directories(
    .
    ${FREERTOS_DIR}/include
    ${FREERTOS_DIR}/portable/ThirdParty/GCC/Posix
    ${FREERTOS_DIR}/portable/ThirdParty/GCC/Posix/utils
)

FILE(GLOB FREERTOS_SOURCES
    ${FREERTOS_DIR}/*.c
)

add_library(freertos STATIC 
    ${FREERTOS_SOURCES}
    ${FREERTOS_DIR}/portable/MemMang/heap_4.c
    ${FREERTOS_DIR}/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c
    ${FREERTOS_DIR}/portable/ThirdParty/GCC/Posix/port.c
)

target_compile_definitions(freertos PUBLIC projCOVERAGE_TEST=0)

# Create executable with demo code files
add_executable(${PROJECT_NAME}
    main.c
    #app.c
    FreeRTOSConfig.h
    console.h console.c
)

# Link FreeRTOS as a static library

target_link_libraries(${PROJECT_NAME} pthread freertos)
