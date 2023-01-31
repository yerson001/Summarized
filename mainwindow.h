#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QImage>
#include <QPixmap>
#include <opencv2/opencv.hpp>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <videoopencv.h>

using namespace cv;
using namespace std;
#define ORANGE QColor(255, 191, 0)


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  bool RUNNING            = false;
  int width;
  int height;
  int camPort = 0;
  string path;
  int no_movement;

  int *arr;
  size_t size;
  QGraphicsScene *scene;
  int it,count,count_movi;

  QGraphicsScene* m_scene;
  VideoOpencv vo;
  //size_t size;
  std::vector<QGraphicsRectItem *> m_rects;
  int m_delay;

  int m_width;

  void drawlines(QGraphicsScene *scene, int *array, size_t sizeGiven, int delay);
  void add_lines(int value);

public slots:
  void runCamera(void);
private slots:

  void on_PBTrun_2_clicked();
  void on_rand_clicked();
};
#endif // MAINWINDOW_H
