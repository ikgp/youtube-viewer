#include <QApplication>

#include "window.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QApplication app(argc, argv);
    Window window;
    window.setWindowState(Qt::WindowFullScreen);
    window.show();
    window.init();

    return app.exec();
}
