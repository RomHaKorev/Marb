#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QTreeView>
#include <QTreeView>
#include <QListView>
#include <QScrollBar>

#include "Thistle/Trees/treeview.h"
#include "Thistle/Trees/radialtreelayout.h"

#include "Thistle/kernel/itemdelegate.h"
#include "Thistle/Graphs/graphview.h"
#include "Thistle/Graphs/graphmodel.h"

#include "Thistle/Charts/linearchart.h"
#include "Thistle/Charts/xychart.h"
#include "Thistle/Charts/radialchart.h"
#include "Thistle/Charts/radarchart.h"
#include "Thistle/Charts/piechart.h"
#include "Thistle/Charts/piechart3d.h"

#include <QDebug>
#include <QStringListModel>


#include <iostream>

#define CHART

int main( int argc, char* argv[] ) {
    QApplication a(argc, argv);

#ifdef XYCHART
    int high_x = 40;
    int low_x = 5;
    int high_y = 100;
    int low_y = -200;

    qsrand( QTime::currentTime().msec() );

    QStandardItemModel* model2 = new QStandardItemModel( 6, 1 );
    //model2->setHorizontalHeaderLabels( QStringList() << "My values" << "My second values" );
    model2->setHorizontalHeaderLabels( QStringList() << "My values" );
    //model2->setVerticalHeaderLabels( QStringList() << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sept" << "Oct" );
    for ( int i = 0; i < model2->rowCount(); ++i )
    {
        for ( int j = 0; j < model2->columnCount(); ++j )
        {
            int x = qrand() % ((high_x + 1) - low_x) + low_x;
            int y = qrand() % ((high_y + 1) - low_y) + low_y;

            model2->setData( model2->index( i, j ), QPointF( x,y ) );
        }
        /*model2->setData( model2->index( i, 1 ), 5 );
        if ( i%2 ) model2->setData( model2->index( i, 2 ), 1 );
        else model2->setData( model2->index( i, 2 ), 3 );*/
    }

    model2->setData( model2->index( 1, 0 ), QLineF( 10, 50, 50, 65 ), Qt::UserRole );


    Thistle::XYChart xy;
    xy.setFrameShape( QFrame::NoFrame );
    xy.setModel( model2 );
    xy.setTitle( "A line chart example" );
    xy.show();
    xy.resize( 400, 275 );
#endif
#ifdef CHART
    int high = 40;
    int low = 5;

    qsrand( QTime::currentTime().msec() );

    QStandardItemModel* model2 = new QStandardItemModel( 6, 2 );
    //model2->setHorizontalHeaderLabels( QStringList() << "My values" << "My second values" );
    model2->setHorizontalHeaderLabels( QStringList() << "My values" );
    //model2->setVerticalHeaderLabels( QStringList() << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sept" << "Oct" );
    for ( int i = 0; i < model2->rowCount(); ++i )
    {
        for ( int j = 0; j < model2->columnCount(); ++j )
        {
            int v = qrand() % ((high + 1) - low) + low;
            model2->setData( model2->index( i, j ), v );
        }
        /*model2->setData( model2->index( i, 1 ), 5 );
        if ( i%2 ) model2->setData( model2->index( i, 2 ), 1 );
        else model2->setData( model2->index( i, 2 ), 3 );*/
    }

    model2->setData( model2->index( 1, 0 ), QLineF( 10, 50, 50, 65 ), Qt::UserRole );


    Thistle::LinearChart linear;
    linear.setFrameShape( QFrame::NoFrame );
    linear.setModel( model2 );
    Thistle::SerieFormat style = linear.serieFormat( 1 );
    style.setType( /*Thistle::Area | Thistle::Line */Thistle::Spline /*| Thistle::Dot*/ /*| Thistle::Thistle::Area*/ );
    QPen pen = style.pen();
    pen.setWidth( 3 );
    style.setPen( pen );
    linear.setSerieFormat( 1, style );
    style = linear.serieFormat( 0 );
    style.setType( Thistle::Line | Thistle::Dot );
    style.setShape( Thistle::Shape::Triangle );
    linear.setSerieFormat(0, style );
    //linear.setFixedSize( 400, 275 );
    linear.setTitle( "A line chart example" );
    linear.show();
    linear.resize( 400, 275 );

    Thistle::AbstractLayer* layer = new Thistle::AbstractLayer( &linear );
    //linear.addLayer( layer );

#endif

#ifdef GRAPH
    Thistle::GraphModel* model = new Thistle::GraphModel(0,1);
    for( int i = 0; i < 9; ++i  ) {
        model->appendRow( new QStandardItem( QString::number( i ) ) );
    }

    Thistle::GraphView graph;
    //graph.setFixedSize( 500, 500 );
    graph.setModel( model );
    model->addEdge( 0, 0, 1, 0 );
    model->addEdge( 0, 0, 5, 0 );
    model->addEdge( 0, 0, 7, 0 );
    model->addEdge( 1, 0, 4, 0 );
    model->addEdge( 1, 0, 9, 0 );
    model->addEdge( 2, 0, 3, 0 );
    model->addEdge( 3, 0, 6, 0 );
    model->addEdge( 4, 0, 7, 0 );
    model->addEdge( 2, 0, 5, 0 );
    model->addEdge( 6, 0, 8, 0 );
    model->addEdge( 0, 0, 8, 0 );
    model->addEdge( 6, 0, 5, 0 );
    model->addEdge( 2, 0, 1, 0 );
    graph.show();
#endif

#ifdef TREE
    QStandardItemModel* model = new QStandardItemModel( 0, 1 );
    QStandardItem* root = new QStandardItem( "root" );
    QStandardItem* A = new QStandardItem( "A" );
    QStandardItem* B = new QStandardItem( "B" );
    QStandardItem* C = new QStandardItem( "C" );
    QStandardItem* D = new QStandardItem( "D" );
    QStandardItem* E = new QStandardItem( "E" );
    QStandardItem* F = new QStandardItem( "F" );
    QStandardItem* G = new QStandardItem( "G" );
    QStandardItem* H = new QStandardItem( "H" );
    QStandardItem* I = new QStandardItem( "I" );
    QStandardItem* J = new QStandardItem( "J" );

    root->appendRow( A );
    root->appendRow( B );
    root->appendRow( C );
    
    A->appendRow( D );
    A->appendRow( E );

    C->appendRow( F );

    D->appendRow( G );
    D->appendRow( H );

    E->appendRow( I );

    I->appendRow( J );

    model->appendRow( root );

    Thistle::TreeView* tree = new Thistle::TreeView();

    Thistle::ItemDelegate* d = new Thistle::ItemDelegate();
    Thistle::ItemStyle style = d->itemStyle();
    style.setShape( Thistle::Ellipse );
    d->setItemStyle( style );
    
    tree->layout()->setOrientation( Qt::Horizontal );
    tree->layout()->deleteLater();
    tree->setLayout( new Thistle::RadialTreeLayout() );
    tree->setItemDelegate( d );
    tree->setModel( model );

    tree->show();

#endif
    return a.exec();
}