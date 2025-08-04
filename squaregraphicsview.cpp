#include "squaregraphicsview.h"
#include <QResizeEvent>
#include <QSize>

SquareGraphicsView::SquareGraphicsView(QWidget *parent)
    : QGraphicsView(parent) {}

// Always keep the view square using the smaller side
void SquareGraphicsView::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);

    int side = qMin(width(), height());
    setFixedSize(side, side);  // Enforce square size

    QGraphicsView::resizeEvent(event);
}

QSize SquareGraphicsView::sizeHint() const {
    return QSize(200, 200);  // Default square size
}
