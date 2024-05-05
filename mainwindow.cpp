#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFocusPolicy(Qt::StrongFocus);

    scene = new QGraphicsScene(this);

    QTimer::singleShot(100, [=]() { this->resizeTable(); });
    QTimer::singleShot(100, [=]() { this->renderTable(); });

    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGame() {
    this->game.step();
    if (!this->game.getSnake().isAlive()) {
        QMessageBox::information(this, "Игра окончена", "Вы проиграли");
    }
    this->renderTable();
}

void MainWindow::renderTable() {
    this->scene->clear();

    std::vector<Coord> snakeCoords = this->game.getSnake().getSnakeCoords();
    Coord appleCoord = this->game.getApple().getCors();
    int cellWidth = ui->graphicsView->width() / this->game.getField().getSize().width;
    int cellHeight = ui->graphicsView->height() / this->game.getField().getSize().height;

    for (int i = 0; i < snakeCoords.size();i++) {
        QGraphicsRectItem *snakePart = new QGraphicsRectItem();
        snakePart->setRect(snakeCoords[i].x * cellWidth, snakeCoords[i].y * cellHeight, cellWidth, cellHeight);
        snakePart->setBrush(QBrush(Qt::green));
        scene->addItem(snakePart);
    }

    QGraphicsRectItem *apple = new QGraphicsRectItem();
    apple->setRect(appleCoord.x * cellWidth, appleCoord.y * cellHeight, cellWidth, cellHeight);
    apple->setBrush(QBrush(Qt::red));
    this->scene->addItem(apple);

    ui->graphicsView->setScene(this->scene);
}

void MainWindow::resizeTable() {
    int tableSize = std::min(this->width(), this->height()) - 20;
        QSize newSize(tableSize, tableSize);

    ui->graphicsView->resize(newSize);

    int newX = (this->width() - tableSize) / 2;
    int newY = (this->height() - tableSize) / 2;

    ui->graphicsView->move(newX, newY);

    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W) {
        this->game.getSnake().setDirection(Direction::UP);
    } else if (event->key() == Qt::Key_A) {
        this->game.getSnake().setDirection(Direction::LEFT);
    } else if (event->key() == Qt::Key_S) {
        this->game.getSnake().setDirection(Direction::DOWN);
    } else if (event->key() == Qt::Key_D) {
        this->game.getSnake().setDirection(Direction::RIGHT);
    }
    QMainWindow::keyPressEvent(event);
}


void MainWindow::resizeEvent(QResizeEvent *event) {
    this->resizeTable();
}
