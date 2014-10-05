//
// lineBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "lineBrush.h"

extern float frand();

LineBrush::LineBrush( ImpressionistDoc* pDoc, char* name ) :
    ImpBrush(pDoc,name)
{
}

void LineBrush::BrushBegin( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    int size = pDoc->getSize();



    glLineWidth( (float)size );

    BrushMove( source, target );
}

void LineBrush::BrushMove( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    if ( pDoc == NULL ) {
        printf( "LineBrush::BrushMove  document is NULL\n" );
        return;
    }

    glBegin( GL_LINES );
        SetColor( source );

        glVertex2d( target.x-10, target.y );
        glVertex2d( target.x+10, target.y );

    glEnd();
}

void LineBrush::BrushEnd( const Point /*source*/, const Point /*target*/ )
{
    // do nothing so far
}
