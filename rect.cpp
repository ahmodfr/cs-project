#include "rect.h"
#include <QDebug>


rect::rect(int boardData[12][12])
{
       QPixmap image("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\Tweety.png");
       image = image.scaledToWidth(50);
       image = image.scaledToHeight(50);
       setPixmap(image);


       row = 6;
       column = 7;
       setPos(50 + column * 50, 50 + row * 50);

       for (int i = 0; i < 12; i++)
           for (int j = 0; j < 12; j++)
              data[i][j] = boardData[i][j];

}


void rect::keyPressEvent(QKeyEvent* event)
{

    if (event->key() == Qt::Key_Up && data[row - 1][column] >= 0)
       {
           row--;
       }
       else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
       {
           row++;
       }
       else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
       {
           column++;
       }
       else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
       {
           column--;
       }
       setPos(50 + column * 50, 50 + row * 50);


}
