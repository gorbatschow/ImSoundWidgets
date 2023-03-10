cmake_minimum_required(VERSION 3.16.0)

project(ImSoundWidgets)

set(CXX_CMAKE_STANDARD 20)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMSOUNDWIDGETS_SOURCES
    SoundControlWidget.cpp
    SoundSetupDisplayWidget.cpp
    SoundClientInfoWidget.cpp
    WaveformScopeWidget.cpp
    WaveformPlotWidget.cpp
    ToneGeneratorWidget.cpp
)

add_library(${PROJECT_NAME} ${IMSOUNDWIDGETS_SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PUBLIC RtSoundIO)
target_link_libraries(${PROJECT_NAME} PUBLIC ImApplication)
target_link_libraries(${PROJECT_NAME} PUBLIC ImWrapper)
target_link_libraries(${PROJECT_NAME} PUBLIC DownPlot)
