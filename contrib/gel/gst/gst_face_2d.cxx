// This is gel/gst/gst_face_2d.cxx
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma implementation
#endif
//:
// \file
// \author crossge@crd.ge.com

#include <utility>

#include "gst_face_2d.h"

gst_face_2d::gst_face_2d( gst_polygon_2d_sptr polygon)
  : outside_( polygon)
{
}

gst_face_2d::gst_face_2d( gst_polygon_2d_sptr polygon, std::vector<gst_polygon_2d_sptr> holes)
  : outside_( polygon),
    holes_(std::move( holes))
{
}

gst_face_2d::~gst_face_2d()
{
}
