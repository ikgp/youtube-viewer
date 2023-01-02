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
    this->m_webView->setUrl(QUrl("https://youtube.com"));
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(webView);
    setLayout(layout);
    this->setTitle(QString("Youtube"));
}
