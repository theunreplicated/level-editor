#ifndef GL_VIEWER_RESIZE_WIDGET_H
#define GL_VIEWER_RESIZE_WIDGET_H

#include <QWidget>

class gl_viewer_resize_widget : public QWidget
{
    Q_OBJECT
public:
    explicit gl_viewer_resize_widget(QWidget *parent = 0);

signals:
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);


public slots:
private:
    int get_own_gl_viewer_layout_item_key();
    bool in_drag;
};

#endif // GL_VIEWER_RESIZE_WIDGET_H
