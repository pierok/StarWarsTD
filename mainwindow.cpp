#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    connect(&maintimer, SIGNAL(timeout()), this, SLOT(MainClockTick()));

    arena=new Arena();

 // arena->setSceneRect(0, 0, 800, 600);

     arena->setItemIndexMethod(QGraphicsScene::NoIndex);

   // arena->setBackgroundBrush(QBrush(Qt::black));
    //arena->setBackgroundBrush(QPixmap(":/data/gw.jpg"));
   // arena->setSceneRect(-100, -100, 800, 600);
    //arena->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->gameView->setScene(arena);
    ui->gameView->show();
    processed=true;

    maintimer.start(30);
}


void MainWindow::MainClockTick()
{
    if(processed)
    {
        processed = false;

        arena->step();
        arena->update();
        processed=true;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
