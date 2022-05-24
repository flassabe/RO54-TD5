#ifndef _READSOURCES_H_
#define _READSOURCES_H_

#include <map>
#include <string>
#include <gdal/gdal_priv.h>

/*!
 * \class GDALDatasetWrapper provides a wrapper to handle safely the dataset type (manipulated in OGR through a pointer)
 */
class GDALDatasetWrapper {
  GDALDataset *dataset;

public:
  GDALDatasetWrapper(GDALDataset *d): dataset(d) {}
  ~GDALDatasetWrapper();
  GDALDatasetWrapper(const GDALDatasetWrapper &other) = delete;
  GDALDatasetWrapper &operator=(const GDALDatasetWrapper &other) = delete;
  GDALDataset *operator->();
  GDALDataset *get() {return dataset;}
  GDALDatasetWrapper(GDALDatasetWrapper &&other);
  GDALDatasetWrapper &operator=(GDALDatasetWrapper &&other);
};

std::map<std::string, GDALDatasetWrapper> readfiles(const std::map<std::string, std::string> &landuses_sources);

#endif // _READSOURCES_H_
