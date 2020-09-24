cmake_minimum_required(VERSION 3.10)

project(udptunnel VERSION 1.1)

set(udptunnel_src 
    "host2ip.h"
    "udptunnel.c")

if (WIN32)
    set(udptunnel_libs ${udptunnel_libs} ws2_32 IPHLPAPI)
    set(udptunnel_src ${udptunnel_src}
        "host2ip_win.c"
        "getopt_win.c"
        "getopt_win.h")
else()
    set(udptunnel_src ${udptunnel_src}
        "host2ip.c")
endif()


add_executable(udptunnel ${udptunnel_src})

if (MSVC)
    set_property(TARGET udptunnel PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
if (WIN32)
    target_compile_definitions(udptunnel PUBLIC NOMINMAX _WINSOCK_DEPRECATED_NO_WARNINGS _CRT_SECURE_NO_WARNINGS)
endif()

target_include_directories(udptunnel PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(udptunnel ${udptunnel_libs})
