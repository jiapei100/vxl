//:
// \file
// \brief Example of creating, processing and using an image data object
// \author Ian Scott

#include <vcl_iostream.h>
#include <testlib/testlib_root_dir.h>
#include <vil2/vil2_load.h>
#include <vil2/vil2_crop.h>
#include <vil2/vil2_image_view.h>
#include <vil2/vil2_image_view_functions.h>


int main(int argc, char** argv)
{

  vcl_string filename = testlib_root_dir() + "/vxl/vil/tests/file_read_data/ff_rgb8bit_raw.ppm";
  vcl_cout<<"Load " << filename << " into an image data object." << vcl_endl;


  // This is how we initialise an image data object.

  vil2_image_data_sptr data = vil2_load_image_data(filename.c_str());
  
  vcl_cout<<"Crop the image by 1 pixel around all sides." << vcl_endl;
  
  // We can apply some operation to it.

  vil2_image_data_sptr cropped_data = vil2_crop(data, 1, 1, data->nx()-2, data->ny()-2);

  // An then get the image pixels from it.
  
  vil2_image_view_base * view = cropped_data->get_view(0,0,0,cropped_data->nx(), cropped_data->ny(), cropped_data->nplanes());

  vcl_cout << "Created a view of type " << view->is_a() << vcl_endl;

  vil2_image_view<unsigned char> uc_view= *view;

  vil2_print_all(vcl_cout,uc_view);

  // don't forget to delete view.
  delete view;
  
  return 0;
}
