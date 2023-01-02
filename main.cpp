#include <QApplication>
#include <QNetworkProxyFactory>

#include "window.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QNetworkProxyFactory::setUseSystemConfiguration(false);
    QApplication app(argc, argv);
    Window window;
    window.setWindowState(Qt::WindowMaximized | Qt::WindowActive);
    window.show();
    window.init();

    return app.exec();
}
