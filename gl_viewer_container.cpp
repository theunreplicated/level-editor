#include "gl_viewer_container.h"
#include "gl_viewer_header_bar.h"
#include "glwindow.h"
#include <QWidget>
#include <QSize>
#include <QColor>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <qsurfaceformat.h>
#include "gl_viewer_resize_widget.h"

gl_viewer_container::gl_viewer_container(QWidget *parent) :
    QWidget(parent)
{
  //setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
   // setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    QHBoxLayout * cwin_h_layout= new QHBoxLayout(this);
    QVBoxLayout * cwin_v_layout= new QVBoxLayout(this);
    cwin_v_layout->setSpacing(0);
    cwin_h_layout->setSpacing(0);
    QColor gl_viewer_border_color ;
    gl_viewer_border_color=QColor(85, 170, 255);






    QWidget * border_line_left= new QWidget();

    border_line_left->setPalette(gl_viewer_border_color);
    border_line_left->setAutoFillBackground(true);


    QVBoxLayout * border_line_right_layout= new QVBoxLayout();
    QWidget * border_line_right= new QWidget();
    border_line_right->setPalette(gl_viewer_border_color);
    border_line_right->setAutoFillBackground(true);
    gl_viewer_resize_widget * border_line_right_hint= new gl_viewer_resize_widget(this);
    border_line_right_hint->setPalette(QColor(255,255,255));
    border_line_right_hint->setAutoFillBackground(true);
    border_line_right_layout->addWidget(border_line_right);
    border_line_right_layout->addWidget(border_line_right_hint);


    QWidget * border_line_bm= new QWidget();
    border_line_bm->setPalette(gl_viewer_border_color);
    border_line_bm->setAutoFillBackground(true);



gl_viewer_header_bar *glvh= new gl_viewer_header_bar(0,gl_viewer_border_color);


int border_line_side_width=10;



int border_line_bm_height=border_line_side_width;

//QSurfaceFormat format;
//format.setSamples(4);
GLWindow * glwindow= new GLWindow();
//glwindow->setAnimating(true);
//glwindow->setFormat(format);
QWidget* glwidget= QWidget::createWindowContainer(glwindow);



 glwidget->setMinimumSize(QSize(50,50));


 border_line_right->setMaximumWidth(border_line_side_width);
 border_line_right_hint->setMaximumHeight(10);
 border_line_right_hint->setMaximumWidth(border_line_side_width);
 border_line_left->setMaximumWidth(border_line_side_width);
 border_line_bm->setMaximumHeight(border_line_bm_height);


 border_line_right->setMinimumSize(QSize(5,10));
 border_line_left->setMinimumSize(QSize(5,10));
 border_line_bm->setMinimumSize(QSize(10,5));

cwin_v_layout->addWidget(glvh);

cwin_v_layout->addWidget(glwidget);
cwin_v_layout->addWidget(border_line_bm);

        cwin_h_layout->addWidget(border_line_left);
        cwin_h_layout->addLayout(cwin_v_layout);
        //cwin_h_layout->addWidget(border_line_right);
        cwin_h_layout->addLayout(border_line_right_layout);

        //TODO:vllt. abstraction mit thread

}
