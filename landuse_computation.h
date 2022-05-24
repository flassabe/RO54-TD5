#ifndef _LANDUSE_COMPUTATION_H_
#define _LANDUSE_COMPUTATION_H_

#include "mesh.h"
#include <vector>
#include <memory>

void mesh_intersection(OGRPolygon *poly, MeshGrid *grid);
void compute_landuse(std::vector<std::unique_ptr<OGRGeometry>> &layer, MeshGrid *grid);

#endif // _LANDUSE_COMPUTATION_H_
