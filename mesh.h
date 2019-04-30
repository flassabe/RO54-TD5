#ifndef _MESH_H_
#define _MESH_H_

#include <memory>
#include <gdal/ogrsf_frmts.h>

class MeshGrid {
  OGRPoint _origin; ///< marks the bottom left point. Must be in a spatial reference with meter units
  double _mesh_width; ///< the individual mesh width in meters
  double _mesh_height; ///< the individual mesh height in meters
  int _mesh_x_count; ///< Number of mesh for grid width
  int _mesh_y_count; ///< Number of mesh for grid height
  std::unique_ptr<float[]> _grid; ///< Content of the grid

public:
  MeshGrid(const OGRPoint &origin=OGRPoint{0.0, 0.0}, double mw=0.0, double mh=0.0,
           int x_cnt=1, int y_cnt=1);
  MeshGrid(const MeshGrid &other) = delete;
  MeshGrid &operator=(const MeshGrid &other) = delete;
  MeshGrid(MeshGrid &&other);
  MeshGrid &operator=(MeshGrid &&other);
  float *operator[](size_t i);
  OGRPoint &get_origin() {return _origin;}
  const OGRPoint &get_origin()const {return _origin;}
  double get_mesh_width()const {return _mesh_width;}
  double get_mesh_height()const {return _mesh_height;}
  int get_mesh_x_count()const {return _mesh_x_count;}
  int get_mesh_y_count()const {return _mesh_y_count;}
  unsigned long long count_non_zero()const;
};

#endif // _MESH_H_
