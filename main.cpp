#include <QtGui/QApplication>
#include <iostream>
#include "mainwindow.h"
#include "AI/includes/gen.h"

int main(int argc, char *argv[])
{

    Gen gen;

    gen.setTowerType(3);
    gen.setTowerX(4095);
    gen.setTowerY(4095);

    std::cout<<"Start"<<std::endl;
    std::cout<<"\nstop: "<<gen.getGenom()<<std::endl;
    std::cout<<"tower type: "<<gen.getTowerType()<<std::endl;
    std::cout<<"tower X: "<<gen.getTowerX()<<std::endl;
    std::cout<<"tower Y: "<<gen.getTowerY()<<std::endl;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
