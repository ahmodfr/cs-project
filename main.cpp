#include <QApplication>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);






    //create a scene
    QGraphicsScene *scene=new QGraphicsScene;
    //creating a view to visualizse the scene
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(650,650);
    view->setWindowTitle("GTA");
    QBrush brush(Qt::white);
    view->setBackgroundBrush(brush);
    // reading from a file to establish the map
    QFile file("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\Board.txt");
    file.open(QIODevice::ReadOnly);
    //putting the file data into stream and intizlaizing the 2d arrady
    QTextStream stream(&file);
    int boardData[12][12];
    QString temp;
    for (int i = 0; i < 12; i++){

            for (int j = 0; j < 12; j++)
            {
                stream >> temp;
                boardData[i][j] = temp.toInt();
            }
    }



    QPixmap walk("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\lilbush.png");
    walk = walk.scaledToWidth(40);
    walk = walk.scaledToHeight(45);

    QPixmap obstacle1("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\grass.png");
    obstacle1 = obstacle1.scaledToWidth(50);
    obstacle1 = obstacle1.scaledToHeight(50);

    QPixmap road_h("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\straight-b.png");
    road_h=road_h.scaledToWidth(50);
    road_h=road_h.scaledToHeight(50);

    QPixmap border("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\Bricks.png");
    border=border.scaledToWidth(50);
    border=border.scaledToHeight(50);

    QPixmap road_right_up("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\rightup.png");
    road_right_up=road_right_up.scaledToWidth(75);
    road_right_up=road_right_up.scaledToHeight(75);

    QPixmap road_left_up ("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\leftup.png");
    road_left_up=road_left_up.scaledToWidth(75);
    road_left_up=road_left_up.scaledToHeight(75);

    QPixmap rightdown ("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\rightdown.png");
    rightdown=rightdown.scaledToWidth(52);
    rightdown=rightdown.scaledToHeight(49);

    QPixmap leftdown ("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\leftdown.png");
    leftdown=leftdown.scaledToWidth(53);
    leftdown=leftdown.scaledToHeight(50);

    QPixmap vertical("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\vertical.png");
    vertical=vertical.scaledToWidth(52);
    vertical=vertical.scaledToHeight(52);

    QPixmap vertical_noborder("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\vert-noside.png");
    vertical_noborder=vertical_noborder.scaledToWidth(51);
    vertical_noborder=vertical_noborder.scaledToHeight((double)50.2);

    QPixmap vertical_noborder_right("A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\vert-noside -right.png");
    vertical_noborder_right=vertical_noborder_right.scaledToWidth(30);
    vertical_noborder_right=vertical_noborder_right.scaledToHeight(50);












    QGraphicsPixmapItem boardItems[12][12];

    for (int i = 0; i < 12; i++)
           for (int j = 0; j < 12; j++)
           {
               // Set Image
               if (boardData[i][j] == -2)
                   boardItems[i][j].setPixmap(border);
               else if (boardData[i][j] == -1)
                   boardItems[i][j].setPixmap(obstacle1);

               else if (boardData [i][j]>0 && boardData[i][j]<9)
                   boardItems[i][j].setPixmap(road_h);
               else if (boardData [i][j]>26 && boardData[i][j]<35)
                   boardItems[i][j].setPixmap(road_h);
               else if (boardData [i][j]>48 && boardData[i][j]<57)
                   boardItems[i][j].setPixmap(road_h);

               else
                   boardItems[i][j].setPixmap(walk);

               // Set Position
               boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

               // Add to the Scene
               scene->addItem(&boardItems[i][j]);
           }
    for (int i=2; i<10; i++){
        boardItems[i][1].setPixmap(vertical);
    }
    for (int i=2; i<10; i++){
        boardItems[i][4].setPixmap(vertical);
    }
    for (int i=2; i<10; i++){
        boardItems[i][7].setPixmap(vertical);
    }
    for (int i=2; i<10; i++){
        boardItems[i][10].setPixmap(vertical);
    }

    boardItems[1][10].setPixmap(road_right_up);
    boardItems[1][1].setPixmap(road_left_up);
    boardItems[10][10].setPixmap(rightdown);
    boardItems[10][1].setPixmap(leftdown);
    boardItems[6][1].setPixmap(vertical_noborder);
    boardItems[6][10].setPixmap(vertical_noborder_right);

    //Enemy e(boardData);

    //boardItems[10][1].setPixmap(e.image);








    view->setScene(scene);
    view->show();



    return a.exec();
}
