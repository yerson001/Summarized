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
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

#define ORANGE QColor(255, 191, 0)
#define WHITE QColor(255, 255, 255)
#define GREEN QColor(55, 200, 0)
#define BLUE QColor(11, 97, 164)
#define RED QColor(255, 57, 0)
#define ORANGE QColor(255, 191, 0)
#define APPLE QColor(165, 255, 0)
#define PURPLE QColor(124, 7, 169)


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QMediaPlayer;
class QVideoWidget;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

protected:
//  void resizeEvent(QResizeEvent *);



private:
  Ui::MainWindow *ui;
  QMediaPlayer *mMediaPlayer;
  QVideoWidget *mVideoWitget;

  bool RUNNING = false;
  int width;
  int height;
  int camPort = 0;
  std::vector<pair<double,int>> histogramValues;
  //********video info**********
  string NameVideo;
  int NumberFrames;
  float LengthVideo;


  int no_movement;
  int FRAME_RANGE;

  //**************************
  long MAX_VALUE = 2000000;
  long MAX_MID_VALUE = 1500000;
  long MID_value = 1000000;
  long MIN_MID_VALUE = 500000;
  long MIN_VALUE = 500;

  int *arr;
  size_t size;
  QGraphicsScene *scene;
  int it,count,forwad,anterior;

  //mergesort* sort;
  //int* arr;
  QGraphicsScene* m_scene;
  QGraphicsScene* m_video;
  //size_t size;
  std::vector<QGraphicsRectItem *> m_rects;
  int m_delay;

  int m_width;

  void drawlines(QGraphicsScene *scene, int *array, size_t sizeGiven, int delay,QColor c);
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
  void on_abrir_clicked();
  void on_play_clicked();
  void on_pause_clicked();
  void on_stop_clicked();
  void on_pushButton_clicked();
  void on_next_clicked();
  void on_back_clicked();
  void on_go_clicked();
  void on_fill_clicked();
};
#endif // MAINWINDOW_H
