QT+=core gui console webkit network

SOURCES += \
    main.cpp \
    run.cpp \
    advancedconfig.cpp \
    filter.cpp \
    monitorstatus.cpp \
    information.cpp \
    portscan.cpp \
    about.cpp

FORMS +=\
    monitorstatus.ui \
    filter.ui \
    advancedconfig.ui \
    portscan.ui \
    fireconfig.ui \
    about.ui

HEADERS +=\
    test.h \
    monitorstatus.h ui_information.h \
    information.h \
    filter.h \
    advancedconfig.h \
    portscan.h \
    about.h

RESOURCES += \
    images.qrc




























