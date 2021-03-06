#-------------------------------------------------
#
#    Project created by QtCreator 2016-12-19T11:03:34
#
#-------------------------------------------------
#    Copyright (C) 2016 Olaf Japp
#    https://facebook.com/artanidos
#
#    This file is part of AnimationMaker.
#
#    AnimationMaker is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    AnimationMaker is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.

QT += core gui svg
QT += testlib xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

debug {
    DEFINES += DEBUG
}

TARGET = AnimationMaker
TEMPLATE = app
target.path += /bin
INSTALLS += target

SOURCES += main.cpp\
    mainwindow.cpp \
    itempropertyeditor.cpp \
    scenepropertyeditor.cpp \
    transitioneditor.cpp \
    svgattributeeditor.cpp \
    licensedialog.cpp \
    sceneview.cpp \
    ruler.cpp

HEADERS  += mainwindow.h \
    itempropertyeditor.h \
    scenepropertyeditor.h \
    transitioneditor.h \
    interfaces.h \
    svgattributeeditor.h \
    licensedialog.h \
    sceneview.h \
    ruler.h

linux-g++ {
    LIBS += -L$$PWD/lib/
    LIBS += -lm
    LIBS += -ldl
    DEFINES += LINUX
}

RESOURCES += \
    images.qrc

DISTFILES += \
    todo.txt \
    Deploy/AppImage/default.desktop \
    Deploy/AppImage/default.png \
    Deploy/snapcraft/snap/snapcraft.yaml \
    Deploy/snapcraft/snap/gui/animationmaker.desktop \
    Deploy/snapcraft/snap/gui/icon.png \
    changelog.txt \
    build.txt \
    Deploy/snapcraft/bin/xdg-open \
    news.xml \
    Deploy/snapcraft/bin/launcher \
    docs/news.xml \
    docs/news.html \
    buildAppImage.sh \
    default.desktop \
    default.svg \
    AppRun \
    README.md \
    docs/README.md


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Widgets/release/ -lWidgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Widgets/debug/ -lWidgets
else:linux-g++: LIBS += -L$$OUT_PWD/Widgets/ -lWidgets
INCLUDEPATH += $$PWD/Widgets
DEPENDPATH += $$PWD/Widgets

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/License/release/ -lLicense
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/License/debug/ -lLicense
else:linux-g++: LIBS += -L$$OUT_PWD/License/ -lLicense
INCLUDEPATH += $$PWD/License
DEPENDPATH += $$PWD/License

