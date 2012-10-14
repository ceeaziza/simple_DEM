#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "global_properties.h"

void triangular_grid(grain* g)
{
  /* Initialize grain properties */
  for (int i = 0; i < ng; i++) {
    g[i].R = (rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
    g[i].m = M_PI * rho * g[i].R * g[i].R;
    g[i].I = 0.5 * g[i].m * g[i].R * g[i].R;
    g[i].p = 0.0;
  }

  /* Initialize grain positions in a triangular grid */
  for (int i = 0; i < ng; i++) {
    int column 	= i%ngw;
    int row 	= i/ngw;

    if (row%2 == 0) 	/* Even row */
      g[i].x = rmax + 2*column*rmax;
    else 		/* Odd row */
      g[i].x = 2*rmax + 2*column*rmax;
    g[i].y = rmax + 2*row*rmax;
  
  }
}
