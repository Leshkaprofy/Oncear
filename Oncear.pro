TARGET = Oncear

INCLUDEPATH += \
    '$$(OPENROBOTINOAPI_DIR)/1/include' \
    '$$(OPENROBOTINOAPI_DIR)/share/include' \
    '$$(OPENCV_DIR)/include' \
    '$$(OPENCV_DIR)/include/opencv' \
    '$$(OPENCV_DIR)/3rdparty/include'

LIBS += \
    /NODEFAULTLIB:atlthunk /NODEFAULTLIB:LIBCMT \
    -l'$$(OPENCV_DIR)/lib/opencv_core220d' \
    -l'$$(OPENCV_DIR)/lib/opencv_highgui220d' \
    -l'$$(OPENCV_DIR)/lib/opencv_video220d' \
    -l'$$(OPENCV_DIR)/lib/opencv_ml220d' \
    -l'$$(OPENCV_DIR)/lib/opencv_legacy220d' \
    -l'$$(OPENCV_DIR)/lib/opencv_imgproc220d' \
    -l'$$(OPENCV_DIR)/3rdparty/lib/videoInput' \
    -l'$$(OPENCV_DIR)/lib/opencv_objdetect220d' \
    -l'$$(OPENROBOTINOAPI_DIR)/1/lib/win32/rec_robotino_com' \
    -l'$$(OPENROBOTINOAPI_DIR)/1/lib/win32/rec_core_lt'

OTHER_FILES += \
    README

SOURCES += \
    main.cpp \
    hardware/rcom.cpp \
    hardware/devices/rcameradevice.cpp \
    hardware/rcamera.cpp \
    GUI/rcamerawidget.cpp


HEADERS += \
    hardware/rcom.h \
    hardware/devices/rcameradevice.h \
    namespaces.h \
    hardware/rcamera.h \
    GUI/rcamerawidget.h
