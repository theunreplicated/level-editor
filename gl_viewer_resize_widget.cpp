#include "gl_viewer_resize_widget.h"
#include <QPushButton>
#include <QRect>
#include <QMouseEvent>
#include <QLayout>
#include "mainwindow.h"
gl_viewer_resize_widget::gl_viewer_resize_widget(QWidget *parent) :
    QWidget(parent)
{in_drag=false;

}//besser mit signals/slots
void gl_viewer_resize_widget::mouseMoveEvent(QMouseEvent *event){
    if(in_drag){
        int realchange_width=event->x()-width();//hinweis:
        int realchange_height=event->y()-height();
       QString str=QString::number(event->x())+'-'+QString::number(realchange_height);
        qDebug(str.toStdString().c_str());

            int estm_width=event->x()+parentWidget()->width();
            int estm_height=event->y()+parentWidget()->height();


QLayout *b=            parentWidget()->parentWidget()->layout();
QRect bc= b->itemAt(1)->geometry();
      // parentWidget()->resize(event->x()+parentWidget()->width(),event->y()+parentWidget()->height());
        //parentWidget()->setFixedSize(QSize(event->x()+parentWidget()->width(),event->y()+parentWidget()->height()));


        /*QSize former_minSize;
        former_minSize=parentWidget()->minimumSize();
        former_minSize.setWidth(former_minSize.width()+event->x());
        former_minSize.setHeight(former_minSize.height()+event->y());
        parentWidget()->setMinimumSize(former_minSize);
*/
       qDebug("[");
       qDebug(QString::number(get_own_gl_viewer_layout_item_key()).toStdString().c_str());
    qDebug("]");
    }


}
int gl_viewer_resize_widget::get_own_gl_viewer_layout_item_key(){//schlechter methodenname,schlechtes beispiel für viel zu lange

    //MainWindow*mw=qobject_cast<MainWindow*>(parent()->parent());
//QLayout *parent_layout = qobject_cast< QLayout* >( parent()->parent()->parent() );
    //return parent_layout->count();
    return 0;
};
void gl_viewer_resize_widget::mousePressEvent(QMouseEvent *){
qDebug ("message");
in_drag=true;


}
void gl_viewer_resize_widget::mouseReleaseEvent(QMouseEvent *){

qDebug ("message-release");
in_drag=false;

}

