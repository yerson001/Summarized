#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QMainWindow>

namespace Ui {
  class Analysis;
}

class Analysis : public QMainWindow
{
  Q_OBJECT

public:
  explicit Analysis(QWidget *parent = nullptr);
  ~Analysis();

private:
  Ui::Analysis *ui;
};

#endif // ANALYSIS_H
