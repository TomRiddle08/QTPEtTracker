cmake_minimum_required(VERSION 3.16)
project(kursovaya11 VERSION 0.1 LANGUAGES CXX)

# Включаем автоматическую обработку .ui, .qrc, MOC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем флаги для покрытия кода
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "--coverage")

# Ищем Qt5 или Qt6 с компонентом Widgets
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Определяем исходные файлы проекта
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    event.h
    event.cpp
)

# Создаём исполняемый файл
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(kursovaya11
        ${PROJECT_SOURCES}
        add_event_dialog.h add_event_dialog.cpp
        pet.h pet.cpp
        edit_pet_dialog.h edit_pet_dialog.cpp
        resources.qrc
        styles.qss
    )
else()
    if(ANDROID)
        add_library(kursovaya11 SHARED ${PROJECT_SOURCES})
    else()
        add_executable(kursovaya11 ${PROJECT_SOURCES})
    endif()
endif()

# Подключаем библиотеку Qt::Widgets
target_link_libraries(kursovaya11 PRIVATE Qt::Widgets)

# Настройки для macOS
if(${QT_VERSION_MAJOR} EQUAL 5 OR (${QT_VERSION_MAJOR} EQUAL 6 AND QT_VERSION_MINOR LESS 1))
    set_target_properties(kursovaya11 PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.kursovaya11
    )
endif()

set_target_properties(kursovaya11 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Включаем тестирование
enable_testing()
add_subdirectory(tests)

# Установка (для дистрибуции)
include(GNUInstallDirs)
install(TARGETS kursovaya11
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)