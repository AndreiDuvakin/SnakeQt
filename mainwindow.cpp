#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    this->renderTable();
}

void MainWindow::renderTable() {
    ui->tableWidget->clear();

    std::vector<Coord> snakeCoords = this->game.getSnake().getSnakeCoords();
    Coord appleCoord = this->game.getApple().getCors();

    for (int column = 0;column < ui->tableWidget->columnCount();column++) {
        for (int row = 0;row < ui->tableWidget->rowCount();row++) {
            QLabel *label = new QLabel();

            Coord currentCoord(column, row);
            bool isSnakeCell = std::find(snakeCoords.begin(), snakeCoords.end(), currentCoord) != snakeCoords.end();

            if (isSnakeCell) {
                label->setStyleSheet("background-color: green;");
            }

            if (column == appleCoord.x && row == appleCoord.y) {
                label->setStyleSheet("background-color: red");
            }

            ui->tableWidget->setCellWidget(row, column, label);
        }
    }
}

void MainWindow::resizeTable() {
    int tableSize = std::min(this->width(), this->height()) - 20;
    QSize newSize(tableSize, tableSize);

    ui->tableWidget->resize(newSize);

    int newX = (this->width() - tableSize) / 2;
    int newY = (this->height() - tableSize) / 2;

    ui->tableWidget->move(newX, newY);

    int columnCount = this->game.getField().getSize().width,
            rowCount = this->game.getField().getSize().height;

    ui->tableWidget->setColumnCount(columnCount);
    ui->tableWidget->setRowCount(rowCount);

    int columnWidht = ui->tableWidget->width()  / columnCount,
            rowHeight = ui->tableWidget->height() / rowCount;

    for (int i = 0;i < columnCount; i++) {
        ui->tableWidget->setColumnWidth(i, columnWidht);
    }

    for (int i = 0;i < rowCount; i++) {
        ui->tableWidget->setRowHeight(i, rowHeight);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    this->resizeTable();
}
