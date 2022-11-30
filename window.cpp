#include "window.h"

#include <QWidget>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QPushButton>
#include <QTimer>

Window::Window()
	:QWidget()
{
}


void Window::init() {
    QVBoxLayout *layout = new QVBoxLayout;
    QWebEngineView *webView = new QWebEngineView(this);
    this->m_webView = webView;
    this->m_webView->setUrl(QUrl("qrc:/loader.html"));
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(webView);
    setLayout(layout);
    // After 20s, redirect to localhost:3000
    QTimer::singleShot(20000, this, SLOT(OpenMainUI()));
}

void Window::OpenMainUI() {
    this->m_webView->setUrl(QUrl("http://localhost:3000"));
}
