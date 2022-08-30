#ifndef NATUREEFFECTCHART_H
#define NATUREEFFECTCHART_H

#include <QDialog>

namespace Ui {
class NatureEffectChart;
}

/*!
 * \class NatureEffectChart
 * \brief This class represents a Dialog screen that will display how a
 *        Pokemon's stats are affected by its nature
 */
class NatureEffectChart : public QDialog{
    Q_OBJECT

public:

    /*!
     * \fn NatureEffectChart(QWidget *parent = nullptr)
     * \brief This is the default constructor for the NatureEffectChart
     * \param parent - the widget parent of the child object
     */
    explicit NatureEffectChart(QWidget *parent = nullptr);

    /*!
     * \fn ~NatureEffectChart()
     * \brief This is the deconstructor for the NatureEffectChart
     */
    ~NatureEffectChart();

private:
    /*!
     * \variable ui
     * \brief The UI for the NatureEffectChart
     */
    Ui::NatureEffectChart *ui;
};

#endif // NATUREEFFECTCHART_H
