#include "readsources.h"
#include "conversion.h"
#include "mesh.h"
#include "landuse_computation.h"
#include <iostream>

using namespace std;

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
  for (auto &entry: ogr_data) {
    env = dataset_conversion(entry.second.get(), &lambert93);
    full_env.MinX = min(env.MinX, full_env.MinX);
    full_env.MaxX = max(env.MaxX, full_env.MaxX);
    full_env.MinY = min(env.MinY, full_env.MinY);
    full_env.MaxY = max(env.MaxY, full_env.MaxY);
  }

  // Grid size definition
  OGRPoint grid_origin{986155, 6728791};
  grid_origin.assignSpatialReference(&lambert93);
  int x_cnt = 1 + (full_env.MaxX - grid_origin.getX()) / 25.0;
  int y_cnt = 1 + (full_env.MaxY - grid_origin.getY()) / 25.0;
  cout << "MeshGrid: y_cnt=" << y_cnt << ", x_cnt=" << x_cnt << endl;
  map<string, MeshGrid> landuse;
  for (auto &entry: ogr_data) {
    landuse[entry.first] = MeshGrid{grid_origin, 25.0, 25.0, x_cnt, y_cnt};
    for (OGRLayer *layer: entry.second.get()->GetLayers()) {
      compute_landuse(layer, &landuse[entry.first]);
    }
    cout << "Landuse computed for role: " << entry.first << endl;
  }

  return 0;
}
