QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 moc
# Include path for OpenCV
INCLUDEPATH += /opt/homebrew/opt/opencv/include/opencv4

# Link path for OpenCV
LIBS += -L/opt/homebrew/opt/opencv/lib

# Explicitly link to required OpenCV libraries
LIBS += -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc

ICON = MyIcon.icns

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camerWorker.cpp \
    discoveryWorker.cpp \
    imageWorker.cpp \
    insta-inet.cpp \
    main.cpp \
    inetcontroler.cpp \
    serverWorker.cpp \
    videoWorker.cpp

HEADERS += \
    camerWorker.h \
    discoveryWorker.h \
    imageWorker.h \
    inetcontroler.h \
    insta-inet.h \
    serverWorker.h \
    videoWorker.h

FORMS += \
    inetcontroler.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
