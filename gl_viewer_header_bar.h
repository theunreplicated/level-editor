#ifndef GL_VIEWER_HEADER_BAR_H
#define GL_VIEWER_HEADER_BAR_H

#include <QWidget>
#include <QPalette>
class gl_viewer_header_bar : public QWidget
{
    Q_OBJECT
public:

    explicit gl_viewer_header_bar(QWidget *parent = 0,QPalette palette=QColor(85, 170, 255));

signals:

public slots:

};

#endif // GL_VIEWER_HEADER_BAR_H
