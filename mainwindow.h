#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QMap>
#include <QPixmap>
#include <QString>
#include "arena.h"
#include "AI/includes/populacja.h"

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
    enum Action {None ,ZoomIn, ZoomOut, PRISM, PLASMA, Quit};
    Mode mode;
    QMap<int,Action> actions;
    Ui::MainWindow *ui;
    QTimer maintimer;
    Arena* arena;
    QString* info;
    QString* infoOs;
    QString* infoPokolenie;
    bool processed;
    QPixmap* qp;
    Populacja* nowaPopulacja;
    int speed;

public slots:
    void keyPressEvent( QKeyEvent *event );
    void wheelEvent( QWheelEvent *event);

private slots:
    void MainClockTick();
    void on_prismButton_clicked();
    void on_plasmaButton_clicked();
    void on_startButton_clicked();
    void on_learnButton_clicked();
    void on_horizontalSlider_sliderMoved(int position);
    void on_horizontalSlider_sliderReleased();
    void on_tieButton_clicked();
};

#endif // MAINWINDOW_H
