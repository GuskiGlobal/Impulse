
cmake_minimum_required(VERSION 3.10)

project(ImpulseDAW)

# Configurações do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Encontra Qt6
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Inclui todos os headers dentro de include/
include_directories(include)

# Arquivos fonte e cabeçalhos
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")
file(GLOB_RECURSE GUI_SOURCES "src/gui/*.cpp")
file(GLOB_RECURSE GUI_HEADERS "include/gui/*.h")
file(GLOB_RECURSE CORE_SOURCES "src/core/*.cpp")
file(GLOB_RECURSE CORE_HEADERS "include/core/*.h")
file(GLOB_RECURSE GUI_SOURCES_PANELS "src/gui/panels/*.cpp")
file(GLOB_RECURSE GUI_HEADERS_PANELS "include/gui/panels/*.h")
file(GLOB_RECURSE GUI_SOURCES_TRACKS "src/gui/tracks/*.cpp")
file(GLOB_RECURSE GUI_HEADERS_TRACKS "include/gui/tracks/*.h")
file(GLOB_RECURSE CORE_SOURCES_TRACKS "src/core/tracks/*.cpp")
file(GLOB_RECURSE CORE_HEADERS_TRACKS "include/core/tracks/*.h")
file(GLOB_RECURSE GUI_SOURCES_BROWSER "src/gui/browser/*.cpp")
file(GLOB_RECURSE GUI_HEADERS_BROWSER "include/gui/browser/*.h")
file(GLOB_RECURSE GUI_SOURCES_MIXER "src/gui/mixer/*.cpp")
file(GLOB_RECURSE GUI_HEADERS_MIXER "include/gui/mixer/*.h")

# Adiciona todos os arquivos às listas finais
list(APPEND SOURCES
    ${GUI_SOURCES}
    ${CORE_SOURCES}
    ${GUI_SOURCES_PANELS}
    ${GUI_SOURCES_TRACKS}
    ${GUI_SOURCES_BROWSER}
    ${GUI_SOURCES_MIXER}
    ${CORE_SOURCES_TRACKS}
)

list(APPEND HEADERS
    ${GUI_HEADERS}
    ${CORE_HEADERS}
    ${GUI_HEADERS_PANELS}
    ${GUI_HEADERS_TRACKS}
    ${GUI_HEADERS_BROWSER}
    ${GUI_HEADERS_MIXER}
    ${CORE_HEADERS_TRACKS}
)

# Copia a pasta assets para o diretório de build
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)

# Executável principal
add_executable(Impulse ${SOURCES} ${HEADERS})

add_dependencies(Impulse copy_assets)

# Linka com o Qt
target_link_libraries(Impulse Qt6::Widgets)

