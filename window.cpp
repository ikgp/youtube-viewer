#include "window.h"

#include <QWidget>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QStackedWidget>

Window::Window()
	:QWidget()
{
}

void Window::init() {
    QVBoxLayout *layout = new QVBoxLayout;
    QWebEngineView *webView = new QWebEngineView(this);
    this->m_webView = webView;
    this->m_webView->setUrl(QUrl("https://www.eff.org/deeplinks/2015/02/who-really-owns-your-drones"));
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(webView);
    setLayout(layout);
    this->setWindowTitle(QString("YouTube"));
}
