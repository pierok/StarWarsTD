#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setWindowState(Qt::WindowFullScreen);
    //this->setFocusPolicy( Qt::StrongFocus );
    // this->setAttribute(Qt::WA_QuitOnClose, true);

    this->setWindowTitle("Star Wars TD");
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    connect(&maintimer, SIGNAL(timeout()), this, SLOT(MainClockTick()));

    info=new QString("");
    info->setNum(800);
    infoOs=new QString("");
    infoOs->setNum(0);

    infoPokolenie=new QString("");
    infoPokolenie->setNum(0);

    infoOs2=new QString("");
    infoOs2->setNum(0);

    infoPokolenie2=new QString("");
    infoPokolenie2->setNum(0);

    qp= new QPixmap(":/data/gw.jpg");
    arena=new Arena(qp);

    //arena->setBackgroundBrush(Qt::black);
    //arena->setBackgroundBrush(QBrush(*qp));

    arena->setSceneRect(0, 0, 2687 , 2683);
    arena->setItemIndexMethod(QGraphicsScene::NoIndex);
    arena->setInfo(info);
    arena->setInfoOs(infoOs);
    arena->setInfoPokolenie(infoPokolenie);

    arena->setInfoOs2(infoOs2);
    arena->setInfoPokolenie2(infoPokolenie2);

    ui->gameView->setScene(arena);
    ui->gameView->scale(0.5,0.5);
    ui->gameView->show();
    processed=true;

    actions.insert( Qt::Key_W, ZoomIn );
    actions.insert( Qt::Key_S, ZoomOut );
    actions.insert(Qt::Key_1, PRISM);
    actions.insert(Qt::Key_2, PLASMA);
    actions.insert(Qt::Key_0, None);
    actions.insert(Qt::Key_Escape, Quit);

    maintimer.start(30);

    ui->plasmaButton->setIcon(QIcon(QPixmap(":/data/plazmaTower.png")));
    ui->plasmaButton->setIconSize(QSize(61,61));

    ui->prismButton->setIcon(QIcon(QPixmap(":/data/PrismTower.png")));
    ui->prismButton->setIconSize(QSize(61,61));

    ui->tieButton->setIcon(QIcon(QPixmap(":/data/TIE_fighter.png")));
    ui->tieButton->setIconSize(QSize(61,61));


    ui->plasmaTestButton->setIcon(QIcon(QPixmap(":/data/plazmaTower.png")));
    ui->plasmaTestButton->setIconSize(QSize(40,40));

    ui->prismTestButton->setIcon(QIcon(QPixmap(":/data/PrismTower.png")));
    ui->prismTestButton->setIconSize(QSize(40,40));

    ui->hunterTestButton->setIcon(QIcon(QPixmap(":/data/TIE_fighter.png")));
    ui->hunterTestButton->setIconSize(QSize(40,40));


    ui->infoLabel->setBackgroundRole(QPalette::Base);
    ui->infoLabel->setPixmap(QPixmap(":/data/start2.png"));

    ui->selectMode->setTabText(0,"Game mode");
    ui->selectMode->setTabText(1,"Learn mode");

}

void MainWindow::MainClockTick()
{
    if(processed)
    {
        processed = false;

        arena->step();
        arena->update();
        ui->lineEdit->setText(*(info));
        if(arena->mode==LEARN)
        {
            ui->osobnikLineEdit->setText(*(infoOs));
            ui->pokolenieLineEdit->setText(*(infoPokolenie));
        }else if(arena->mode==LEARN2)
        {
            ui->osobnik2lineEdit->setText(*(infoOs2));
            ui->pokolenie2lineEdit->setText(*(infoPokolenie2));
        }
        processed=true;
    }
}


void MainWindow::wheelEvent( QWheelEvent *event )
{

    float scale = 1.0 + event->delta()*0.001;
    ui->gameView->scale(scale,scale);
    //std::cout<<"Main window event wheel"<<std::endl;
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
    case Quit:
        this->close();
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
    //maintimer.start(1);
}

void MainWindow::on_plasmaButton_clicked()
{
    arena->setGun(A_PLASMA);
    ui->infoLabel->setPixmap(QPixmap(":/data/plasmaInfo.png"));
}

void MainWindow::on_tieButton_clicked()
{
    arena->setGun(A_HUNTER);
    ui->infoLabel->setPixmap(QPixmap(":/data/tieInfo.png"));
}

void MainWindow::on_startButton_clicked()
{
    arena->init();

    arena->deploy1->setRate(70);
    arena->deploy1->timer=0;
    arena->deploy1->deploySize(20);
    arena->deploy1->start();

    arena->deploy2->setRate(15);
    arena->deploy2->timer=0;
    arena->deploy2->deploySize(30);
    arena->deploy2->start();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    speed=30-position/3;
    if(speed>30)
    {
        speed=30;
    }else if(speed<=0)
    {
        speed=1;
    }
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    maintimer.start(speed);
    std::cout<<"speed: "<<speed<<std::endl;
}


void MainWindow::on_testButton_clicked()
{
    arena->init();

    std::cout<<"read from file"<<std::endl;
    QFile file("out.txt");
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
        return;


    QTextStream in(&file);

    Osobnik o;

    QString line = in.readLine();
    for(int i=0; i<100; ++i)
    {
        line = in.readLine();
        Gen* g=new Gen();
        g->setGenom(line.toInt());
        o.chromosom.push_back(g);
    }

    file.close();


    std::cout<<"osobnik size: "<<o.chromosom.size()<<std::endl;

    foreach(Gen* gen, o.chromosom)
    {
        if(gen->getTowerType()==1)
        {
            arena->setGun(A_PRISM);
            arena->addTower(gen->getTowerX(),gen->getTowerY());
        }else if(gen->getTowerType()==2)
        {
            arena->setGun(A_PLASMA);
            arena->addTower(gen->getTowerX(),gen->getTowerY());
        }else if(gen->getTowerType()==3)
        {
            arena->setGun(A_HUNTER);
            arena->addTower(gen->getTowerX(),gen->getTowerY());
        }
    }

    on_startButton_clicked();


}

void MainWindow::on_learnButton_clicked()
{
    arena->init();

    Arena::mode=LEARN;

    QString size=ui->populatonSizeTextEdit->text();
    nowaPopulacja=new Populacja(size.toInt());

    arena->nPopulacja=nowaPopulacja;
    AlgorytmGenetyczny* ag=new AGDef(nowaPopulacja);
    arena->ag=ag;
    //ag->update();

    Osobnik* osobnik=nowaPopulacja->populacja[0];
    ui->osobnikLineEdit->setText(ui->osobnikLineEdit->text().setNum(0));

    foreach(Gen* gen, osobnik->chromosom)
    {
        if(gen->getTowerType()==1)
        {
            arena->setGun(A_PRISM);
            arena->addTower(gen->getTowerX(),gen->getTowerY());
        }else if(gen->getTowerType()==2)
        {
            arena->setGun(A_PLASMA);
            arena->addTower(gen->getTowerX(),gen->getTowerY());
        }else if(gen->getTowerType()==3)
        {
            arena->setGun(A_HUNTER);
            arena->addTower(gen->getTowerX(),gen->getTowerY());
        }
    }

    on_startButton_clicked();
}


void MainWindow::on_learn2Button_clicked()
{
     Arena::mode=LEARN2;

     QString size=ui->populationSize2lineEdit->text();

     nowaPopulacjaOf=new PopulacjaOf(size.toInt());

     arena->nPopulacjaOf=nowaPopulacjaOf;
     AlgorytmGenetyczny* ag=new AGOf(nowaPopulacjaOf);
     arena->ag=ag;
     //ag->update();

     OsobnikOf* osobnik=nowaPopulacjaOf->populacja[0];
     ui->osobnik2lineEdit->setText(ui->osobnik2lineEdit->text().setNum(0));


     foreach(GenOf* gen, osobnik->chromosom)
     {
         arena->addDeploy(gen->getDeployX(),gen->getDeployY(),gen->getEnemyType(),gen->getTarget());
     }




}

void MainWindow::on_prismTestButton_clicked()
{
    arena->setGun(A_PRISM);
}

void MainWindow::on_plasmaTestButton_clicked()
{
    arena->setGun(A_PLASMA);
}

void MainWindow::on_hunterTestButton_clicked()
{
    arena->setGun(A_HUNTER);
}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        arena->hideElements();
    }else if(!ui->checkBox->isChecked())
    {
        arena->showElements();
    }
}
