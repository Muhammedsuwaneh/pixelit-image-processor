cmake_minimum_required(VERSION 3.16)

project(PixelItApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appPixelItApp
    main.cpp
    app.rc
)

qt_add_qml_module(appPixelItApp
    URI PixelItApp
    QML_FILES
        views/Main.qml
        views/NavigationButton.qml
        views/ImagePropertyNavigation.qml
        views/TitleBar.qml
        views/ControlButton.qml
        views/ImageController.qml
        views/ImageViewer.qml
        views/ImageControlButton.qml
        views/ZoomPage.qml
        views/PanPage.qml
        views/RotatePage.qml
        views/CropPage.qml
        views/ResizePage.qml
        views/FiltersPage.qml
        views/BrightnessPage.qml
        views/ContrastPage.qml
        views/SaturationPage.qml
        views/ExposurePage.qml
        views/GrayScalePage.qml
        views/SepiaPage.qml
        views/InvertPage.qml
        views/SharpenPage.qml

    RESOURCES
        assets/logo.png
        assets/logo.ico
        assets/brightness.png
        assets/contrast.png
        assets/crop.png
        assets/exposure.png
        assets/gray.png
        assets/invert.png
        assets/pan.png
        assets/resize.png
        assets/rotate.png
        assets/saturation.png
        assets/sepia.png
        assets/sharpen.png
        assets/zoom.png
        assets/undo.png
        assets/redo.png
        assets/testImage.png
        assets/load.png
        assets/save.png
        assets/filters.png
        assets/adjust.png
        assets/rotate_right.png
        assets/rotate_left.png

    SOURCES
        controllers/NavigationController.h
        controllers/NavigationController.cpp
        controllers/WindowController.h
        controllers/WindowController.cpp
        controllers/ImageController.h
        controllers/ImageController.cpp
        SOURCES controllers/ImageScaleController.h controllers/ImageScaleController.cpp
        SOURCES utilities/ImageProvider.h utilities/ImageProvider.cpp
        SOURCES controllers/ImageRotationController.h controllers/ImageRotationController.cpp
        SOURCES controllers/ImageTextureController.h controllers/ImageTextureController.cpp
        SOURCES controllers/FiltersController.h controllers/FiltersController.cpp
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
target_link_libraries(appPixelItApp PRIVATE Qt6::Core)
target_link_libraries(appPixelItApp PRIVATE Qt6::Widgets)
target_link_libraries(appPixelItApp PRIVATE Qt6::Core)
target_link_libraries(appPixelItApp PRIVATE Qt6::Core)
target_link_libraries(appPixelItApp PRIVATE Qt6::Core)
target_link_libraries(appPixelItApp PRIVATE Qt6::Core)
target_link_libraries(appPixelItApp PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appPixelItApp BUNDLE DESTINATION . LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} )

set_target_properties(appPixelItApp PROPERTIES
    WIN32_EXECUTABLE TRUE
)
