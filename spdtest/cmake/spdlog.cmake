include(ExternalProject)

set(spdlog_DIR "${CMAKE_SOURCE_DIR}/vendor/spdlog")

ExternalProject_Add(
    spdlog

    GIT_REPOSITORY "https://github.com/gabime/spdlog"
    GIT_TAG "master"

    INSTALL_DIR "${spdlog_DIR}"
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release
               -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
               -DSPDLOG_BUILD_TESTING=OFF
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(spdlog_INCLUDE_DIRS "${spdlog_DIR}/include")
set(spdlog_LIBS Threads::Threads)
