#pragma once

#include <QWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE

class Window : public QWindow
{
Q_OBJECT

public:
    Window();

    void init();

private:
    QWebEngineView *m_webView;
};

QT_END_NAMESPACE
