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
    void ShowMainUI(bool ok);

private:
    QWebEngineView *m_loadingView;
    QWebEngineView *m_realView;
    QStackedWidget *m_stackedWidget;
};

QT_END_NAMESPACE
