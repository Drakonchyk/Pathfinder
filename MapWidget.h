#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <vector>

struct Point {
    int x, y;
    bool operator==(const Point& other) const { return x == other.x && y == other.y; }
    bool operator<(const Point& other) const { return std::tie(x, y) < std::tie(other.x, other.y); }
};

class MapWidget : public QWidget {
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = nullptr);
    ~MapWidget() override;

    void confirmPath();
    void resetMap();
    void addDestinationFromInput(int x, int y);

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *event) override;
    
private:
    std::vector<Point> destinations;
    std::vector<Point> path;
    bool pathConfirmed = false;
};

#endif // MAPWIDGET_H
