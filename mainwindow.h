#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QMap>
#include "arena.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    enum Action {None ,ZoomIn, ZoomOut};
    QMap<int,Action> actions;
    Ui::MainWindow *ui;
    QTimer maintimer;
    Arena* arena;
    bool processed;

public slots:
    void keyPressEvent( QKeyEvent *event );
    void wheelEvent( QWheelEvent *event);


private slots:
    void MainClockTick();
};

#endif // MAINWINDOW_H
