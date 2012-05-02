#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QMap>
#include <QPixmap>
#include <QString>
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
    enum Action {None ,ZoomIn, ZoomOut, PRISM, PLASMA};
    QMap<int,Action> actions;
    Ui::MainWindow *ui;
    QTimer maintimer;
    Arena* arena;
    QString* info;
    bool processed;
    QPixmap* qp;

public slots:
    void keyPressEvent( QKeyEvent *event );
    void wheelEvent( QWheelEvent *event);

private slots:
    void MainClockTick();
    void on_prismButton_clicked();
    void on_plasmaButton_clicked();
    void on_startButton_clicked();
};

#endif // MAINWINDOW_H
