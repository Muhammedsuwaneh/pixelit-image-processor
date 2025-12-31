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
        NavigationButton.qml
        ImagePropertyNavigation.qml
        TitleBar.qml
        ControlButton.qml
        ImageController.qml
        ImageViewer.qml
        ImageControlButton.qml
        ZoomPage.qml
        PanPage.qml
        RotatePage.qml
        CropPage.qml
        ResizePage.qml
        FiltersPage.qml
        BrightnessPage.qml
        ContrastPage.qml
        SaturationPage.qml
        ExposurePage.qml
        GrayScalePage.qml
        SepiaPage.qml
        InvertPage.qml
        SharpenPage.qml

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

    SOURCES
        NavigationController.h
        NavigationController.cpp
        WindowController.h
        WindowController.cpp
        ImageController.h
        ImageController.cpp
        SOURCES ImageScaleController.h ImageScaleController.cpp
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

include(GNUInstallDirs)
install(TARGETS appPixelItApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
