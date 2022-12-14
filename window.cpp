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
    QWebEngineView *loadingView = new QWebEngineView(this);
    this->m_loadingView = loadingView;
    this->m_loadingView->setUrl(QUrl("qrc:/loader.html"));
    QWebEngineView *realView = new QWebEngineView(this);
    this->m_realView = realView;
    QStackedWidget *stackedWidget = new QStackedWidget;
    this->m_stackedWidget = stackedWidget;
    this->m_stackedWidget->addWidget(this->m_loadingView);
    this->m_stackedWidget->addWidget(this->m_realView);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(this->m_stackedWidget);
    setLayout(layout);
    // Load the actual page
    connect(this->m_realView, &QWebEngineView::loadFinished, this, &Window::ShowMainUI);
    this->m_realView->setUrl(QUrl("http://localhost:3000"));
}

void Window::ShowMainUI(bool ok) {
    qDebug() << "ShowMainUI: " << ok;
    if (ok) {
        disconnect(this->m_realView, &QWebEngineView::loadFinished, this, &Window::ShowMainUI);
        this->m_stackedWidget->setCurrentWidget(this->m_realView);
        delete this->m_loadingView;
    } else {
        this->m_realView->setUrl(QUrl("http://localhost:3000"));
    }
}
