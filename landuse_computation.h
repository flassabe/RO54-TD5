#ifndef _LANDUSE_COMPUTATION_H_
#define _LANDUSE_COMPUTATION_H_

#include "mesh.h"

int check_layer_for_poly(OGRLayer *layer);
void mesh_intersection(OGRPolygon *poly, MeshGrid *grid);
void compute_landuse(OGRLayer *layer, MeshGrid *grid);

#endif // _LANDUSE_COMPUTATION_H_
