#include "mainwindow.h"
#include "glwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QVariant>
#include "gl_viewer_layout.h"
#include "gl_viewer_header_bar.h"
#include "gl_viewer_container.h"
#include <QMenuBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //GLWidget *glwidget = new GLWidget();
    //glwidget->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding );
    QGroupBox * groupBox = new QGroupBox(this);


    groupBox->setTitle("Level Editor");

//TODO:local setzen
    //QGridLayout *layout = new QGridLayout(groupBox);//setspacing abstand elemente,setmargin abstand äußere
   // gl_viewer_layout_grid*layout= new gl_viewer_layout_grid();
QVBoxLayout*mainlayout= new QVBoxLayout(groupBox);

QGridLayout*gl_viewer_layout = new QGridLayout(groupBox);

 QMenuBar *main_menubar= new QMenuBar(groupBox);
 QMenu* main_menubar_file = new QMenu("Map");
 QAction*action_new_file=new QAction( "&Neu", this);
 QAction*action_open_file=new QAction( "&Laden", this);
main_menubar_file->addAction(action_new_file);
 main_menubar_file->addAction(action_open_file);
 main_menubar->addMenu(main_menubar_file);
 QMenu *main_menubar_info=new QMenu("Info");
 QAction*action_info= new QAction("&Über",this);
 main_menubar_info->addAction(action_info);
 main_menubar->addMenu(main_menubar_info);
 main_menubar->setMaximumHeight(20);
 mainlayout->addWidget(main_menubar);

    gl_viewer_container*b= new gl_viewer_container(this);
   // gl_viewer_container*b2= new gl_viewer_container(this);

    //gl_viewer_container*b3= new gl_viewer_container(this);
    //gl_viewer_container*b4= new gl_viewer_container(this);


    gl_viewer_layout->addWidget(b,0,0);

   //layout->addWidget(b2,0,1);


   // layout->addWidget(b3,1,0);
   // layout->addWidget(b4,1,1);




    mainlayout->addLayout(gl_viewer_layout);
    groupBox->setLayout(mainlayout);
setCentralWidget(groupBox);
}

MainWindow::~MainWindow()
{

}
