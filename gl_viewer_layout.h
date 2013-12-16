#ifndef GL_VIEWER_LAYOUT_H
#define GL_VIEWER_LAYOUT_H
#include <QStyle>
#include <QLayout>
#include <QRect>
#include <QWidgetItem>
class gl_viewer_layout : public QLayout
{
public:
    gl_viewer_layout(QWidget *parent, int margin = -1, int hSpacing = -1, int vSpacing = -1);
    gl_viewer_layout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
    ~gl_viewer_layout();

    void addItem(QLayoutItem *item);
    int horizontalSpacing() const;
    int verticalSpacing() const;
    Qt::Orientations expandingDirections() const;
    bool hasHeightForWidth() const;
    int heightForWidth(int) const;
    int count() const;
    QLayoutItem *itemAt(int index) const;
    QSize minimumSize() const;
    void setGeometry(const QRect &rect);
    QSize sizeHint() const;
    QLayoutItem *takeAt(int index);

private:
    int doLayout(const QRect &rect, bool testOnly) const;
    int smartSpacing(QStyle::PixelMetric pm) const;

    QList<QLayoutItem *> itemList;
    int m_hSpace;
    int m_vSpace;
};
#endif // GL_VIEWER_LAYOUT_H
