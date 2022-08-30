#ifndef TYPEEFFECTCHART_H
#define TYPEEFFECTCHART_H

#include <QDialog>

namespace Ui {
class TypeEffectChart;
}

/*!
 * \class TypeEffectChart
 * \brief This class represents a Dialog screen that will display how a
 *        Pokemon's type would interact with other types
 */
class TypeEffectChart : public QDialog{
    Q_OBJECT

public:
    /*!
     * \fn TypeEffectChart(QWidget *parent = nullptr)
     * \brief This is the default constructor for the TypeEffectChart
     * \param parent - the widget parent of the child object
     */
    explicit TypeEffectChart(QWidget *parent = nullptr);

    /*!
     * \fn ~TypeEffectChart()
     * \brief This is the deconstructor for the TypeEffectChart
     */
    ~TypeEffectChart();

private:
    /*!
     * \variable ui
     * \brief The UI for the NatureEffectChart
     */
    Ui::TypeEffectChart *ui;
};

#endif // TYPEEFFECTCHART_H
