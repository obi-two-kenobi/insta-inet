QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 moc
# Include path for OpenCV
INCLUDEPATH += /opt/homebrew/Cellar/opencv/4.11.0_1/include/opencv4

# Link path for OpenCV
LIBS += -L/opt/homebrew/Cellar/opencv/4.11.0_1/lib

# Explicitly link to required OpenCV libraries
LIBS += -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camerWorkerClass.cpp \
    discovery.cpp \
    imageWorker.cpp \
    insta-inet.cpp \
    main.cpp \
    inetcontroler.cpp \
    serverClass.cpp \
    squaregraphicsview.cpp \
    videoworker.cpp

HEADERS += \
    camerWorkerClass.h \
    discovery.h \
    imageWorker.h \
    inetcontroler.h \
    insta-inet.h \
    serverClass.h \
    squaregraphicsview.h \
    videoworker.h

FORMS += \
    inetcontroler.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
