cmake_minimum_required(VERSION 2.8.3)
project(rqt_openday_gui)

set(LIB_NAME rqt_openday_gui)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp rospy rqt_gui rqt_gui_cpp)

## Include Qt
find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui QtWebKit)
include(${QT_USE_FILE})

## Set sources and headers
set(openday_gui_SRCS
  src/rqt_openday_gui/openday_gui.cpp
)

set(openday_gui_HDRS
  include/rqt_openday_gui/openday_gui.h
)

set(openday_gui_UIS
  src/rqt_openday_gui/openday_gui.ui
)

set(openday_gui_RES
  src/rqt_openday_gui/Images.qrc
)

## Set include directories
set(openday_gui_INCLUDE_DIRECTORIES
  include
  ${CMAKE_CURRENT_BINARY_DIR} #Needed for genrated moc headers
)

## Specify everything important for the catkin package
catkin_package(
   INCLUDE_DIRS ${openday_gui_INCLUDE_DIRECTORIES}
   LIBRARIES rqt_openday_gui
   CATKIN_DEPENDS roscpp rospy rqt_gui rqt_gui_cpp
)

## Specify include directories
include_directories(
  ${openday_gui_INCLUDE_DIRECTORIES}
  ${catkin_INCLUDE_DIRS}
)

## Activate python setup to be able to install rqt plugin with setup.py
catkin_python_setup()

## Wrap Qt cpp and ui files
QT4_WRAP_CPP(QT_MOC_HPP ${openday_gui_HDRS})
QT4_WRAP_UI(QT_FORMS_HPP ${openday_gui_UIS})
QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${openday_gui_RES})

## Create a library and not an executable because this is going to be a plugin
add_library(${LIB_NAME} ${openday_gui_SRCS} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
#add_dependencies(${LIB_NAME})

## Specify libraries to link a library or executable target against
target_link_libraries(${LIB_NAME}
  ${catkin_LIBRARIES}
  ${QT_LIBRARIES}
  ${QT_QTCORE_LIBRARY} 
  ${QT_QTGUI_LIBRARY}
  ${QT_QTWEBKIT_LIBRARY}
  ${ROS_LIBRARIES}
)


## Install files to right locations
find_package(class_loader)
class_loader_hide_library_symbols(${LIB_NAME})

install(FILES plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(TARGETS ${LIB_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})
 
install(PROGRAMS scripts/rqt_openday_gui #Script to run it standalone
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${LIB_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
