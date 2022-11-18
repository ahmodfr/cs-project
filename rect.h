#ifndef RECT_H
#define RECT_H

#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>



class rect: public QObject, public QGraphicsPixmapItem

{
    Q_OBJECT
public:
    int row, column;
    int data[12][12];
    rect(int boardData[12][12]);
public slots:
    void keyPressEvent(QKeyEvent* event);
};


#endif // RECT_H
