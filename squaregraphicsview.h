#ifndef SQUAREGRAPHICSVIEW_H
#define SQUAREGRAPHICSVIEW_H

#include <QGraphicsView>

class SquareGraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    explicit SquareGraphicsView(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;
    QSize sizeHint() const override;
};

#endif // SQUAREGRAPHICSVIEW_H
