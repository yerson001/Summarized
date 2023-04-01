#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QImage>
#include <QPixmap>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <vector>
#include <qfiledialog.h>
#include <opencv2/opencv.hpp>
#include <moveitem.h>

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

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  vector<pair<int,int> > Limit(int t_number,int n);
  int filters(Mat img1,Mat img2,Mat &d,int k);
  ~MainWindow();

private slots:
  void SetHistogram();

  void on_mainpage_clicked();
  void on_videopage_clicked();
  void on_analisispage_clicked();
  void on_mainpage_2_clicked();
  void on_openfileAnalisis_clicked();
  void on_draw_clicked();
  void on_openfile_clicked();
  void on_start_clicked();
  void on_goFrame_clicked();
  void on_next_clicked();
  void on_back_clicked();
  void on_guardar_clicked();


  void on_start_2_clicked();

private:
  Ui::MainWindow *ui;
  MoveItem *item = new MoveItem();
  // **** opencv instance ****
  cv::VideoCapture cap;

  //@******** video info *******
  string NameVideo;
  string OnlyName;
  int NumberFrames;
  float LengthVideo;
  //*** start slot ****
   bool RUNNING = false;
   int FRAME_RANGE;
   int no_movement;
   bool control;
   // ******* limits********
   long MAX_VALUE = 2000000;
   long MAX_MID_VALUE = 1500000;
   long MID_value = 1000000;
   long MIN_MID_VALUE = 500000;
   long MIN_VALUE = 700;

   //*** now Qgraphics view and histogram *****+
   int *arr;
   bool color;
   size_t size;
   int flag;
   int m_width;
   QGraphicsScene *scene;
   int it,count,forwad,anterior;
   QGraphicsScene* m_scene;
   QGraphicsScene* als_scene;

   std::vector<QGraphicsRectItem *> m_rects;



   std::vector<pair<int,int>> histogramValues;
   std::vector<pair<int,int>> histogramCsv;


   // **** function to get only histogram *******
   void drawlines(QGraphicsScene *scene, int *array, size_t sizeGiven,QColor c);
   int ValueLines(int val);
   void add_lines(int value);
   void configSensivility();
   void histogramConfig();
   void IntervalVideo(int m,int n);
   void getFrame();
   string realname();
   int getPosValue();
   void changevalue(int);
   void resetvalues();
};

#endif // MAINWINDOW_H
