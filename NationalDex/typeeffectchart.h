#ifndef TYPEEFFECTCHART_H
#define TYPEEFFECTCHART_H

#include <QDialog>

namespace Ui {
class TypeEffectChart;
}

class TypeEffectChart : public QDialog
{
    Q_OBJECT

public:
    explicit TypeEffectChart(QWidget *parent = nullptr);
    ~TypeEffectChart();

private:
    Ui::TypeEffectChart *ui;
};

#endif // TYPEEFFECTCHART_H
