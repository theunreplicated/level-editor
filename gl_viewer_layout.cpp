#include <QtGui>
#include <QStyle>
#include <QWidget>
#include <QSizePolicy>
#include "gl_viewer_layout.h"
gl_viewer_layout::gl_viewer_layout(QWidget *parent, int margin, int hSpacing, int vSpacing)
    : QLayout(parent), m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

gl_viewer_layout::gl_viewer_layout(int margin, int hSpacing, int vSpacing)
    : m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

gl_viewer_layout::~gl_viewer_layout()
{
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

void gl_viewer_layout::addItem(QLayoutItem *item)
{
    itemList.append(item);
}

int gl_viewer_layout::horizontalSpacing() const
{qDebug("horizontal_spacing");
    if (m_hSpace >= 0) {
        return m_hSpace;
    } else {
        return smartSpacing(QStyle::PM_LayoutHorizontalSpacing);
    }
}

int gl_viewer_layout::verticalSpacing() const
{qDebug("vertical_spacing");
    if (m_vSpace >= 0) {
        return m_vSpace;
    } else {
        return smartSpacing(QStyle::PM_LayoutVerticalSpacing);
    }
}

int gl_viewer_layout::count() const
{
    return itemList.size();
}

QLayoutItem *gl_viewer_layout::itemAt(int index) const
{
    return itemList.value(index);
}

QLayoutItem *gl_viewer_layout::takeAt(int index)
{
    if (index >= 0 && index < itemList.size())
        return itemList.takeAt(index);
    else
        return 0;
}

Qt::Orientations gl_viewer_layout::expandingDirections() const
{
    qDebug("exp_directions");
    return 0;
}

bool gl_viewer_layout::hasHeightForWidth() const
{
    return true;
}

int gl_viewer_layout::heightForWidth(int width) const
{qDebug("height_for_width");
    int height = doLayout(QRect(0, 0, width, 0), true);
    return height;
}

void gl_viewer_layout::setGeometry(const QRect &rect)
{qDebug("setgeometry");
    QLayout::setGeometry(rect);
    doLayout(rect, false);
}

QSize gl_viewer_layout::sizeHint() const
{qDebug("sizeHint");
    return minimumSize();
}

QSize gl_viewer_layout::minimumSize() const
{
    QSize size;qDebug("minimumSize");
    QLayoutItem *item;
    foreach (item, itemList)
        size = size.expandedTo(item->minimumSize());

    size += QSize(2*margin(), 2*margin());
    return size;
}

int gl_viewer_layout::doLayout(const QRect &rect, bool testOnly) const
{
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    QRect effectiveRect = rect.adjusted(+left, +top, -right, -bottom);
    int x = effectiveRect.x();
    int y = effectiveRect.y();
    int lineHeight = 0;

    QLayoutItem *item;
    foreach (item, itemList) {
        QWidget *wid = item->widget();
        int spaceX = horizontalSpacing();
        if (spaceX == -1)
            spaceX = wid->style()->layoutSpacing(
                QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Horizontal);
        int spaceY = verticalSpacing();
        if (spaceY == -1)
            spaceY = wid->style()->layoutSpacing(
                QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Vertical);
        int nextX = x + item->sizeHint().width() + spaceX;
        if (nextX - spaceX > effectiveRect.right() && lineHeight > 0) {
            x = effectiveRect.x();
            y = y + lineHeight + spaceY;
            nextX = x + item->sizeHint().width() + spaceX;
            lineHeight = 0;
        }

        if (!testOnly)
            item->setGeometry(QRect(QPoint(x, y), item->sizeHint()));

        x = nextX;
        lineHeight = qMax(lineHeight, item->sizeHint().height());
    }
    return y + lineHeight - rect.y() + bottom;
}
int gl_viewer_layout::smartSpacing(QStyle::PixelMetric pm) const
{
    qDebug("smartspacing");
    QObject *parent = this->parent();
    if (!parent) {
        return -1;
    } else if (parent->isWidgetType()) {
        QWidget *pw = reinterpret_cast<QWidget *>(parent);//geändert von static_cast nach Compiler-Meldung
        return pw->style()->pixelMetric(pm, 0, pw);
    } else {
        return static_cast<QLayout *>(parent)->spacing();
    }
}
//http://qt-project.org/doc/qt-4.8/layouts-gl_viewer_layout-gl_viewer_layout-cpp.html
