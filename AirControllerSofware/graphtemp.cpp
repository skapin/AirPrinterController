#include "graphtemp.h"

GraphTemp::GraphTemp(QWidget *parent) :
    QwtPlot(parent)
{
    setCanvasBackground(Qt::white);
    _grid.enableX( false );
    _grid.setPen( QPen(Qt::gray, 1));
    _grid.attach( this );

    // Fixe the X/Y axis scale
    this->setAxisScale(QwtPlot::yLeft,0.0,300.0,25.0);

    _estimatedTemp.setPen( QPen(Qt::darkCyan,2, Qt::DotLine) );
    _estimatedTemp.attach( this );
    replot();
}

void GraphTemp::setTempController(TempController *tempcontroller) {
    _tempController = tempcontroller;
}
