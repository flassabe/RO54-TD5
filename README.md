# LO53 - TD7: GIS

## Context

In this session, your task is to build a representation of a landuse (i.e. what the geographical area is used to) map based on openstreetmap data. The main flow is the following:
1. Create a mesh grid
2. Import all OSM files
3. Convert all data to Lambert93
4. Go through the GDALDatasets and find the polygons defining buildings shapes
5. Compute the intersection between building shapes and the landuse mesh grid
6. Write their coverage rate in the mesh grid array.

The data files used for this session are available on moodle. The project has a Makefile that can help you build your program with the `make` command.

## Install dependencies

If you wish to work on your own computer, you need to use a GNU/Linux distribution such as Ubuntu, Debian or Fedora. Dependencies for Fedora are the following:

```bash
sudo dnf install gdal-devel
```

On Ubuntu, is may look like this (you may update this file and propose a pull request if it is a different package):

```bash
sudo apt install gdal-dev
```

## Creating a grid mesh

This is already implemented in the provided code.

## Importing all OSM files

This step requires to load the GDAL driver, then to import each source file and wrap the result into a GDALDatasetWrapper.

Based on the lecture examples, use GDAL to import each OSM file into an element of the corresponding map (it is defined in the provided code). Your code will be located in the readsources.cpp file, according to the comments. Use the GDALDatasetWrapper to ensure proper cleaning of your class instances (see [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) for more information).

Reminder: a C++ STL map is a key,value container, organized as an binary search tree, in which the keys are ordered when inserted. The map provides three access methods:

 - `find(key_value)`, which returns an iterator to the map element whose key is `key_value` if it exists, or `end()` if it doesn't.
 - `operator [key_value]` which returns the value corresponding to the key `key_value`. Be advised that, if `key_value` doesn't exist, it is then created with a default corresponding value
 - method `at(key_value)` that returns the corresponding value, and throws `std::out_of_range` if `key_value` is not in the map.
 - see [cppreference page on map](https://en.cppreference.com/w/cpp/container/map) for more information

## Convert to Lambert93

Since OSM data are provided in WGS84 coordinate reference system, you shall create an instance of `OGRCoordinateTransformation`, with which you shall:

 - go through all data sources
 - clone every geometry into a vector
 - convert the geometries coordinates to **Lambert93**
 - store the result into `converted_data` map

Your code must be located in `conversion.cpp`.

## Going through the data and computing landuse

Go through the vectors you filled on the previous step and find polygons and multipolygons (based on `GetType` method provided by the `OGRGeomFieldDefnRef` pointer in `OGRFeature`), and compute the area of their intersections with meshes. You can use create from `common.h` to provide a well known text defining a mesh (with 5 points in it, first and last point being the same ones), then use `Intersection` and `get_Area` from the OGR API. Then, landuse qualification is computed by the intersection area divided by the mesh area. This part requires to be a bit smart to avoid hours of computation.

This part is implemented in `landuse_computation.cpp`.

## Output the results in files

For each landuse defined (in the map instanciated in `landuse.cpp`), write its content into a file, one file line for each grid row, values separated by spaces. Files are named with the map key, and a .dat suffix. Only output grid meshes that have non zero values.

Each output file has 2 sections:

 - A header with the mesh grid properties: origin (x and y), mesh x and y dimensions, mesh x and y count (one line, fields separated by ',')
 - The content with all relevant meshes, one mesh per line:
   - mesh x and y indices, mesh value (as computed in `landuse_computation`)
   
It is implemented in `landuse.cpp`.
