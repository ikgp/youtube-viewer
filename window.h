#pragma once

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE

class Window : public QWidget
{
Q_OBJECT

public:
    Window();

    void init();

public slots:
    void OpenMainUI();

private:
    QWebEngineView *m_webView;
};

QT_END_NAMESPACE
