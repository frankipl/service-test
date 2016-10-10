QT += core gui widgets
QT += androidextras
QT += remoteobjects
CONFIG += c++11

TARGET=serviceapp

SOURCES += main.cpp \
    service-app.cpp

REPC_REPLICA += ../service.rep

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/src/com/kdab/training/MyService.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

HEADERS += \
    service-app.h

FORMS += \
    forms/mainwindow.ui \

