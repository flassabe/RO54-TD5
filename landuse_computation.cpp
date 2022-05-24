#include "landuse_computation.h"
#include "common.h"
#include <cmath>
#include <iostream>

using namespace std;

/*!
 * \brief mesh_intersection computes the intersection between a polygon and a grid mesh
 * \param poly the polygon whose intersection is to be computed
 * \param grid the mesh grid used to compute and store the intersection
 */
void mesh_intersection(OGRPolygon *poly, MeshGrid *grid) {
  if (!poly) return;
  // TODO: your code here
  
  // End of your code
}

/*!
 * \brief compute_landuse computes the landuse matrix for a given type of landuse.
 * It relies on mesh_intersection.
 * \param layer the vector of geometries whose landuse is to be calculated
 * \param grid the grid used to compute and store the intersection
 * \see mesh_intersection
 */
void compute_landuse(std::vector<std::unique_ptr<OGRGeometry>> &layer, MeshGrid *grid) {
	for (auto &geom_ptr: layer) {
		// TODO: your code here
		
		// End of your code
	}
}
