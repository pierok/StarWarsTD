#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // this->



    this->setWindowTitle("Star Wars TD");
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    connect(&maintimer, SIGNAL(timeout()), this, SLOT(MainClockTick()));

    info=new QString("");
    info->setNum(800);

    qp= new QPixmap(":/data/gw.jpg");
    arena=new Arena(qp);

    arena->setBackgroundBrush(Qt::black);
    arena->setSceneRect(0, 0, 2687 , 2683);
    arena->setItemIndexMethod(QGraphicsScene::NoIndex);
    arena->setInfo(info);

    ui->gameView->setScene(arena);
    ui->gameView->scale(0.5,0.5);
    ui->gameView->show();
    processed=true;

    actions.insert( Qt::Key_W, ZoomIn );
    actions.insert( Qt::Key_S, ZoomOut );
    actions.insert(Qt::Key_1, PRISM);
    actions.insert(Qt::Key_2, PLASMA);
    actions.insert(Qt::Key_0, None);

    maintimer.start(30);

    // Resize refer to desktop
    //this->resize( QApplication::desktop()->size() );
    //int x=QApplication::desktop()->size().width();
    //int y= QApplication::desktop()->size().height();
    //this->resize(x-10,y-68);

    // this->setFocusPolicy( Qt::StrongFocus );
    // this->setAttribute(Qt::WA_QuitOnClose, true);

    ui->plasmaButton->setIcon(QIcon(QPixmap(":/data/plazmaTower.png")));
    ui->plasmaButton->setIconSize(QSize(61,61));

    ui->prismButton->setIcon(QIcon(QPixmap(":/data/PrismTower.png")));
    ui->prismButton->setIconSize(QSize(61,61));

    ui->infoLabel->setBackgroundRole(QPalette::Base);
    //ui->infoLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    //ui->infoLabel->setScaledContents(true);

    ui->infoLabel->setPixmap(QPixmap(":/data/start2.png"));

}

void MainWindow::MainClockTick()
{
    if(processed)
    {
        processed = false;

        arena->step();
        arena->update();
        ui->lineEdit->setText(*(info));
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
    case PRISM:
        arena->setGun(A_PRISM);
        break;
    case PLASMA:
        arena->setGun(A_PLASMA);
        break;
    case None:
        arena->setGun(A_NONE);
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

void MainWindow::on_prismButton_clicked()
{
    arena->setGun(A_PRISM);
    ui->infoLabel->setPixmap(QPixmap(":/data/prismInfo.png"));
}

void MainWindow::on_plasmaButton_clicked()
{
    arena->setGun(A_PLASMA);
    ui->infoLabel->setPixmap(QPixmap(":/data/plasmaInfo.png"));
}

void MainWindow::on_startButton_clicked()
{
    arena->deploy1->start();
    arena->deploy2->start();
}
