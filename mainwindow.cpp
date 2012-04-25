#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Star Wars TD");
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    connect(&maintimer, SIGNAL(timeout()), this, SLOT(MainClockTick()));

    qp= new QPixmap(":/data/gw.jpg");
    arena=new Arena(qp);

    arena->setBackgroundBrush(Qt::black);
    arena->setSceneRect(0, 0, 2687 , 2683);
    arena->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->gameView->setScene(arena);
    ui->gameView->scale(0.5,0.5);
    ui->gameView->show();
    processed=true;

    actions.insert( Qt::Key_W, ZoomIn );
    actions.insert( Qt::Key_S, ZoomOut );

    maintimer.start(30);

       // Resize refer to desktop
       //this->resize( QApplication::desktop()->size() );
        int x=QApplication::desktop()->size().width();
         int y= QApplication::desktop()->size().height();
        this->resize(x-10,y-68);

         std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
      // this->setFocusPolicy( Qt::StrongFocus );
      // this->setAttribute(Qt::WA_QuitOnClose, true);


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


void MainWindow::wheelEvent( QWheelEvent *event )
{
    float scale = 1.0 + event->delta()*0.001;
    ui->gameView->scale(scale,scale);

    std::cout<<"Main window event wheel"<<std::endl;
    event->accept();
}

void MainWindow::keyPressEvent( QKeyEvent *event )
{
    if ( event->isAutoRepeat() || !actions.contains( event->key() ) )
    {   // autorepeat to wirtualne przycisniecia kiedy trzymamy klawisz
        //event->ignore();
        //return;
    }
    float scale;
    Action action = actions[event->key()];
    switch ( action )
    {
    case ZoomIn:
        scale= 1.0 + 0.01;
        ui->gameView->scale(scale,scale);
        break;
    case ZoomOut:
        scale = 1.0 - 0.01;
        ui->gameView->scale(scale,scale);
        break;
    default:
        event->ignore();
        return;
    }
    event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    arena->deploy1->start();
    arena->deploy2->start();
}
