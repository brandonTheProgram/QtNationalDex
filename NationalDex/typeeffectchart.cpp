#include "typeeffectchart.h"
#include "ui_typeeffectchart.h"

TypeEffectChart::TypeEffectChart(QWidget *parent)
        : QDialog(parent), ui(new Ui::TypeEffectChart){
    ui->setupUi(this);

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

TypeEffectChart::~TypeEffectChart(){
    delete ui;
}
