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
#include <threads.h>
#include <opencv2/opencv.hpp>
#include <QMessageBox>



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
  bool RUNNING = false;
  int width;
  int height;
  int camPort = 0;
  //********video info**********
  string NameVideo;
  int NumberFrames;
  float LengthVideo;


  int no_movement;
  int FRAME_RANGE = 100;

  //**************************
  long MAX_VALUE = 2000000;
  long MAX_MID_VALUE = 1500000;
  long MID_value = 1000000;
  long MIN_MID_VALUE = 500000;
  long MIN_VALUE = 0;

  int *arr;
  size_t size;
  QGraphicsScene *scene;
  int it,count;

  //mergesort* sort;
  //int* arr;
  QGraphicsScene* m_scene;
  //size_t size;
  std::vector<QGraphicsRectItem *> m_rects;
  int m_delay;

  int m_width;

  void drawlines(QGraphicsScene *scene, int *array, size_t sizeGiven, int delay);
  int ValueLines(int val);

  void add_lines(int value);



public slots:
  void runCamera(void);
   int filters(Mat img1,Mat img2,Mat &d,int k);
private slots:

  void on_PBTrun_2_clicked();
  void on_rand_clicked();
  void on_analyze_clicked();
  //void on_spinBox_valueChanged(int arg1);
};
#endif // MAINWINDOW_H
