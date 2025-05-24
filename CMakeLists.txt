
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
file(GLOB_RECURSE GUI_SOURCES_PANELS "src/gui/panels/*.cpp")
file(GLOB_RECURSE GUI_HEADERS_PANELS "include/gui/panels/*.h")

# Adiciona todos os arquivos às listas finais
list(APPEND SOURCES ${GUI_SOURCES} ${GUI_SOURCES_PANELS})
list(APPEND HEADERS ${GUI_HEADERS} ${GUI_HEADERS_PANELS})

# Copia a pasta assets para o diretório de build
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

# Executável principal
add_executable(Impulse ${SOURCES} ${HEADERS})

# Linka com o Qt
target_link_libraries(Impulse Qt6::Widgets)

