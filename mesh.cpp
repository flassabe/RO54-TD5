#include "mesh.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <gdal/ogr_feature.h>
#include <gdal/ogr_geometry.h>

using namespace std;

MeshGrid::MeshGrid(const OGRPoint &origin, double mw,
                   double mh, int x_cnt, int y_cnt):
                   _origin(origin), _mesh_width(mw), _mesh_height(mh),
                   _mesh_x_count(x_cnt), _mesh_y_count(y_cnt) {
  _grid = make_unique<float[]>(x_cnt * y_cnt);
}

MeshGrid::MeshGrid(MeshGrid &&other) {
  _origin = other._origin;
  _mesh_width = other._mesh_width;
  _mesh_height = other._mesh_height;
  _mesh_x_count = other._mesh_x_count;
  _mesh_y_count = other._mesh_y_count;
  _grid = move(other._grid);
}

MeshGrid &MeshGrid::operator=(MeshGrid &&other) {
  _origin = other._origin;
  _mesh_width = other._mesh_width;
  _mesh_height = other._mesh_height;
  _mesh_x_count = other._mesh_x_count;
  _mesh_y_count = other._mesh_y_count;
  _grid = move(other._grid);
  return *this;
}

float *MeshGrid::operator[](size_t i) {
  if (i < _mesh_y_count && i >= 0)
    return &_grid[i * _mesh_x_count];
  else {
    char error[50];
    sprintf(error, "Out of grid: i=%d", i);
    throw out_of_range(error);
  }
}

unsigned long long MeshGrid::count_non_zero()const {
  unsigned long long count = 0;
  for (auto i=0; i<_mesh_x_count*_mesh_y_count; ++i) {
    if (_grid[i] > 0)
      ++count;
  }
  return count;
}
