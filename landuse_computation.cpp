#include "landuse_computation.h"
#include "common.h"
#include <cmath>

using namespace std;

/*!
 * \function check_layer_for_poly checks if a given layer contains polygons or multipolygons
 * \param layer a pointer to the layer to test
 * \return the index of the layer feature geometry that is composed of polygons or multipolygons
 * Returns -1 if no polygons nor multipolygons are found
 */
int check_layer_for_poly(OGRLayer *layer) {
  int poly_idx = -1;
  if (layer) {
    // TODO: your code here
  }
  return poly_idx;
}

/*!
 * \function mesh_intersection computes the actual intersection rate between a mesh and a building (represented as a polygon)
 * \param poly the pointer to a polygon defining a building
 * \param grid a pointer to the grid being computed
 * 
 * Do not forget to check if a building is within the grid boundaries
 */
void mesh_intersection(OGRPolygon *poly, MeshGrid *grid) {
  if (!poly) return;
  // TODO: your code here
}

/*!
 * \function compute_landuse computes the landuse of a layer related to a grid (specific to a landuse type)
 * \param layer the layer used to compute the landuse
 * \param grid the grid in which to store the result
 */
void compute_landuse(OGRLayer *layer, MeshGrid *grid) {
  // Check if layer contains multipolygon ot polygon features
  int poly_idx = check_layer_for_poly(layer);
  if (poly_idx == -1)
    return;

  // TODO: your code here
}
