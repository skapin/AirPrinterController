#ifndef GRAPHTEMP_H
#define GRAPHTEMP_H

#ifdef WIN32
    #define QWT_DLL
#endif


#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_legend.h>
#include <QVector>
#include <QPen>
#include <string>


#include "tempcontroller.h"

class GraphTemp : public QwtPlot
{
    Q_OBJECT
public:
    explicit GraphTemp(QWidget *parent = 0);
    void setTempController( TempController* tempcontroller );
    
signals:
    
public slots:

private:
    QwtPlotGrid _grid;
    QwtPlotCurve _estimatedTemp;
    TempController* _tempController;
    
};

#endif // GRAPHTEMP_H
