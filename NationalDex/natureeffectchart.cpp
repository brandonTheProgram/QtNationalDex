#include "natureeffectchart.h"
#include "ui_natureeffectchart.h"

NatureEffectChart::NatureEffectChart(QWidget *parent)
    :QDialog(parent), ui(new Ui::NatureEffectChart)
{
    ui->setupUi(this);

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

NatureEffectChart::~NatureEffectChart(){
    delete ui;
}
