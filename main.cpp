#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include "MapWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);
    MapWidget *mapWidget = new MapWidget;

    QLineEdit *xInput = new QLineEdit;
    QLineEdit *yInput = new QLineEdit;
    QPushButton *addButton = new QPushButton("Add Destination");
    QPushButton *confirmButton = new QPushButton("Confirm Path");
    QPushButton *resetButton = new QPushButton("Restart");

    xInput->setPlaceholderText("X Coordinate");
    yInput->setPlaceholderText("Y Coordinate");

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(xInput);
    inputLayout->addWidget(yInput);
    inputLayout->addWidget(addButton);

    layout->addWidget(mapWidget);
    layout->addLayout(inputLayout);
    layout->addWidget(confirmButton);
    layout->addWidget(resetButton);

    QObject::connect(addButton, &QPushButton::clicked, [&]() {
        int x = xInput->text().toInt();
        int y = yInput->text().toInt();
        mapWidget->addDestinationFromInput(x, y);
    });

    QObject::connect(confirmButton, &QPushButton::clicked, mapWidget, &MapWidget::confirmPath);
    QObject::connect(resetButton, &QPushButton::clicked, mapWidget, &MapWidget::resetMap);

    window.setLayout(layout);
    window.setWindowTitle("Map Navigation");
    window.show();

    return app.exec();
}
