#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QMap>
#include <QPixmap>
#include <QString>
#include "arena.h"
#include "agproperties.h"
#include "AI/includes/algorytmGenetyczny.h"
//#include "AI/includes/populacja.h"

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
    QString* infoOs2;
    QString* infoPokolenie2;
    bool processed;
    QPixmap* qp;
    Populacja* nowaPopulacja;
    PopulacjaOf* nowaPopulacjaOf;
    int speed;
    AgProperties* property;

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
    void on_testButton_clicked();
    void on_learn2Button_clicked();
    void on_prismTestButton_clicked();
    void on_plasmaTestButton_clicked();
    void on_hunterTestButton_clicked();
    void on_checkBox_clicked();
    void on_propertiesButton_clicked();
    void on_startTimerButton_clicked();
};

#endif // MAINWINDOW_H
