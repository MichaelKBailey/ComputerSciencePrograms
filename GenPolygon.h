#ifndef GENPOLYGON_H
#define GENPOLYGON_H

#include "GenLine.h"

class GenPolygon
{
  private:
    int no_lines;
    GenLine* lines;

  public:
    GenPolygon();
    GenPolygon(int no_lines);
    ~GenPolygon();
    GenPolygon(const GenPolygon& poly);
    int getNoLines();
    void setNoLines(int no_lines);
    GenLine getLineAt(int index);
    void setLineAt(int index, GenLine line);
    void draw();
};

#endif;
    
    
    