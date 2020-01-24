#ifndef NATUREEFFECTCHART_H
#define NATUREEFFECTCHART_H

#include <QDialog>

namespace Ui {
class NatureEffectChart;
}

class NatureEffectChart : public QDialog{
    Q_OBJECT

public:
    explicit NatureEffectChart(QWidget *parent = nullptr);
    ~NatureEffectChart();

private:
    Ui::NatureEffectChart *ui;
};

#endif // NATUREEFFECTCHART_H
