// doxygen documentation
#include "doxygen_mainpage.cpp"

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

#include "utilities.hpp"


using namespace cv;
using namespace std;


//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************


int main( int argc, const char** argv )
{
    static const size_t SIZE_OF_RESULT = 480;

    char image_file_name[128];
    char image_file_name_480[128];

    bool we_have_images = true;
    size_t counter = 0;

    while(we_have_images)
    {
        Mat src, src_gray, dst;

        const String window_name = "picture";
        
          
        counter++;
        sprintf(image_file_name, "data/img%05d.jpg", counter); 
        sprintf(image_file_name_480, "data/img%05d_480.jpg", counter);

        if(is_file_exists(image_file_name))
        {

            src = imread(image_file_name, IMREAD_COLOR);

            namedWindow(window_name, WINDOW_NORMAL);
            imshow(window_name, src);
            waitKey(2000);

            src_gray = imread(image_file_name, IMREAD_GRAYSCALE);
            imshow(window_name, src_gray);
            //imwrite("data/tuman_grayscale.jpg", src_gray);
            waitKey(2000);

            size_t width = src_gray.size().width;
            cout << "width = " << width << endl;
            size_t height = src_gray.size().height;
            cout << "height = " << height << endl;

            size_t w_l = 0, w_u = width-1, h_l = 0, h_u = height-1;

            if(width > height)
            {
                size_t diff = width - height;
                w_l = diff / 2 - 1; 
                w_u = w_l + height;
            }
            else if(height > width)
            {
                size_t diff = height - width;
                h_l = diff / 2 - 1; 
                h_u = h_l + width;
            }

            cout << w_l << " " << w_u << " " << h_l << " " << h_u << " " << endl;

            // Crop image
            Mat cropped_image = src_gray(Range(h_l, h_u), Range(w_l, w_u)); 
            imshow(window_name, cropped_image);
            //imwrite("data/tuman_cropped.jpg", cropped_image);
            waitKey(2000);

            destroyAllWindows();
            namedWindow(window_name, WINDOW_NORMAL);

            //resize up
            resize(cropped_image, dst, Size(SIZE_OF_RESULT, SIZE_OF_RESULT), INTER_LINEAR);

            imshow(window_name, dst);
            imwrite(image_file_name_480, dst);
            waitKey(2000);

            destroyAllWindows();

        }
        else
        {
            we_have_images = false;
        }
    }

//    setMouseCallback(window_name, onMouse, (void *)(&window_frame));

    
    waitKey();

   return 0;
}



//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************


