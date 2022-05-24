#include "readsources.h"
#include "conversion.h"
#include "mesh.h"
#include "landuse_computation.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <memory>
#include <cmath>

using namespace std;

/*!
 * \brief save_results saves your results, one file for each landuse type
 * \param landuse the map with the landuse values, indexed by landuse name (use that data to name the files)
 */
void save_results(const map<string, MeshGrid> &landuse) {
	// TODO: your code here
	// End of your code
}

int main() {
  map<string, string> sources{{"Retail", "../data/belfort-commerces.osm"},
                              {"Schools", "../data/belfort-ecoles.osm"},
                              {"Industry", "../data/belfort-entreprises.osm"},
                              {"Trainstations", "../data/belfort-gares.osm"},
                              {"Healthcare", "../data/belfort-hopitaux.osm"},
                              {"Leisure", "../data/belfort-loisirs.osm"},
                              {"Public services", "../data/belfort-publiques.osm"},
                              {"Universities", "../data/belfort-universites.osm"},
                              {"Residential", "../data/belfort-residences.osm"}};
  auto ogr_data = readfiles(sources);

  // Data coordinates conversion
  OGREnvelope env, full_env;
  OGRSpatialReference lambert93;
  lambert93.importFromEPSG(2154);
  map<string, vector<unique_ptr<OGRGeometry>>> converted_data;
  for (auto &entry: ogr_data) {
    vector<unique_ptr<OGRGeometry>> v;
    tie(env, v)  = dataset_conversion(entry.second.get(), &lambert93);
    full_env.MinX = min(env.MinX, full_env.MinX);
    full_env.MaxX = max(env.MaxX, full_env.MaxX);
    full_env.MinY = min(env.MinY, full_env.MinY);
    full_env.MaxY = max(env.MaxY, full_env.MaxY);
    converted_data[entry.first] = move(v);
  }

  // Grid size definition
  OGRPoint grid_origin{floor(full_env.MinX), floor(full_env.MinY)};
  grid_origin.assignSpatialReference(&lambert93);
  int x_cnt = 1 + (full_env.MaxX - grid_origin.getX()) / 25.0;
  int y_cnt = 1 + (full_env.MaxY - grid_origin.getY()) / 25.0;
  cout << "MeshGrid: y_cnt=" << y_cnt << ", x_cnt=" << x_cnt << endl;
  cout << "OGR envelop dimensions: " << (full_env.MaxX - full_env.MinX) << " x "  << (full_env.MaxY - full_env.MinY) << endl;
  map<string, MeshGrid> landuse;
  for (auto &entry: converted_data) {
    landuse[entry.first] = MeshGrid{grid_origin, 25.0, 25.0, x_cnt, y_cnt};
    compute_landuse(entry.second, &landuse[entry.first]);
    
    cout << "Landuse computed for role: " << entry.first << endl;
    cout << "Computed " << landuse[entry.first].count_non_zero() << " values >0" << endl;
  }
  save_results(landuse);

  return 0;
}
