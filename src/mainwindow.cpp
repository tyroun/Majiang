#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>

class FitView : public QGraphicsView
{
public:
    FitView(QGraphicsScene *scene) : QGraphicsView(scene) {
        setSceneRect(Config.Rect);
        setRenderHints(QPainter::TextAntialiasing | QPainter::Antialiasing);
    }

    virtual void resizeEvent(QResizeEvent *event) {
        QGraphicsView::resizeEvent(event);
        MainWindow *main_window = qobject_cast<MainWindow *>(parentWidget());
        if(scene()->inherits("RoomScene")){
            RoomScene *room_scene = qobject_cast<RoomScene *>(scene());
            QRectF newSceneRect(0, 0, event->size().width(), event->size().height());
            room_scene->setSceneRect(newSceneRect);
            room_scene->adjustItems();
            setSceneRect(room_scene->sceneRect());
            if (newSceneRect != room_scene->sceneRect())
                fitInView(room_scene->sceneRect(), Qt::KeepAspectRatio);
            else
                this->resetTransform();
            main_window->setBackgroundBrush(false);
            return;
        }
        // @TODO: other Scene
        else if(scene()->inherits("StartScene"))
        {
//            StartScene *start_scene = qobject_cast<StartScene *>(scene());
//            QRectF newSceneRect(-event->size().width() / 2, -event->size().height() / 2,
//                                event->size().width(), event->size().height());
//            start_scene->setSceneRect(newSceneRect);
//            setSceneRect(start_scene->sceneRect());
//            if (newSceneRect != start_scene->sceneRect())
//                fitInView(start_scene->sceneRect(), Qt::KeepAspectRatio);
        }
        if(main_window)
            main_window->setBackgroundBrush(true);
    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
