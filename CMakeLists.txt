cmake_minimum_required(VERSION 3.16)

project(PixelItApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appPixelItApp
    main.cpp
)

qt_add_qml_module(appPixelItApp
    URI PixelItApp
    QML_FILES
        Main.qml
        QML_FILES TitleBar.qml
        SOURCES WindowController.h WindowController.cpp
        QML_FILES ControlButton.qml

    RESOURCES
        assets/logo.png
        assets/logo.ico
        QML_FILES NavigationButton.qml
        SOURCES NavigationController.h NavigationController.cpp
        QML_FILES ImagePropertyNavigation.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPixelItApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPixelItApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPixelItApp
    PRIVATE Qt6::Quick ${OPEN}
)
target_link_libraries(appPixelItApp PRIVATE Qt6::Core ${OpenCV_LIBS})
target_link_libraries(appPixelItApp PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appPixelItApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
