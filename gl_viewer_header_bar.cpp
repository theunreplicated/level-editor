#include "gl_viewer_header_bar.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIcon>


/*
header bar vom gl viewer(kiene INfos aus deiesem Satz),
//TODO:inkonsistent,GL grisschreiben
*/
gl_viewer_header_bar::gl_viewer_header_bar(QWidget *parent,QPalette palette) :
    QWidget(parent)
{
    QHBoxLayout * std_layout= new QHBoxLayout(this);//http://stackoverflow.com/questions/3706285/why-dont-my-widgets-get-displayed/3706458#3706458


    QLabel* std_line = new QLabel("Perspektive X",this);

    //QPushButton *button = new QPushButton();
    //button->setIcon(QIcon(QPixmap("/close_icon.png")));
    //button->setIconSize(QSize(165,165));
    QLabel * closelabel= new QLabel("Schließen",this);
	QPushButton * temp_test_links= new QPushButton("Links",this);temp_test_links->setMinimumSize(QSize(20,20));
	QPushButton * temp_test_rechts= new QPushButton("Rechts",this);temp_test_rechts->setMinimumSize(QSize(20,20));

    //QHBoxLayout * buttongroup= new QHBoxLayout();

    std_layout->addWidget(std_line,0,Qt::AlignLeft);
	std_layout->addWidget(temp_test_links,0,Qt::AlignRight);
	std_layout->addWidget(temp_test_rechts,0,Qt::AlignRight);
   std_layout->addWidget(closelabel,0,Qt::AlignRight);
    //buttongroup->SetMaximumSize(30,30);


int comp_height=std_line->height();
   setMaximumHeight(comp_height);
   //setMaximumWidth(comp_width);
    std_layout->setSpacing(0);

setPalette(palette);

setAutoFillBackground(true);
}

//TODO:vllt. Farb-Zuweisun gmit painterEvent
