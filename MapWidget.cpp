#include "MapWidget.h"
#include <QPainter>
#include <QPen>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include <iostream>

MapWidget::MapWidget(QWidget *parent) : QWidget(parent) {
    setFixedSize(600, 400);
}

MapWidget::~MapWidget() = default;

void MapWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(0, 0, width(), height(), Qt::lightGray);

    painter.setPen(QPen(Qt::blue, 2));
    for (size_t i = 1; i < path.size(); ++i) {
        painter.drawLine(path[i - 1].x, path[i - 1].y,
                         path[i].x, path[i].y);
    }

    for (size_t i = 0; i < destinations.size(); ++i) {
        painter.setBrush(i == 0 ? Qt::green : Qt::red);
        painter.drawEllipse(destinations[i].x - 5, destinations[i].y - 5, 10, 10);
        painter.setPen(Qt::black);
        painter.drawText(destinations[i].x + 5, destinations[i].y - 5, QString::number(i));
    }
}

void MapWidget::mousePressEvent(QMouseEvent *event) {
    if (!pathConfirmed) {
        Point clicked = {static_cast<int>(event->position().x()), static_cast<int>(event->position().y())};
        auto it = std::find(destinations.begin(), destinations.end(), clicked);
        if (it != destinations.end()) {
            destinations.erase(it);
        } else {
            destinations.push_back(clicked);
        }
        update();
    }
}

void MapWidget::confirmPath() {
    if (destinations.size() < 2 || pathConfirmed) return;

    path.clear();
    for (size_t i = 0; i < destinations.size(); i++) {
        path.push_back(destinations[i]);
    }
    pathConfirmed = true;
    update();
}

void MapWidget::resetMap() {
    destinations.clear();
    path.clear();
    pathConfirmed = false;
    update();
}

void MapWidget::addDestinationFromInput(int x, int y) {
    if (x >= 0 && x < width() && y >= 0 && y < height()) {
        destinations.push_back({x, y});
        update();
    }
}