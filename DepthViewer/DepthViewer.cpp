#include <XnOpenNI.h>
#include <XnCppWrapper.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace xn;
using namespace cv;

int main( int argc, char* argv[] )
{
    Context mContext;
    mContext.Init();

    DepthGenerator mDepthGen;
    mDepthGen.Create( mContext );

    mContext.StartGeneratingAll();

    int max_dist = 5000;
    int min_dist = 0;
    bool reverse_colormap = true;

    if(argc == 3)
    {
        max_dist = atoi(argv[2]);
        min_dist = atoi(argv[1]);
    }

    while (waitKey(1) == -1)
    {
        mContext.WaitAnyUpdateAll();

        DepthMetaData depthData;
        mDepthGen.GetMetaData( depthData );
        Mat imgDepth( depthData.FullYRes(), depthData.FullXRes(), CV_16UC1, ( void* )depthData.Data() );
        Mat img8bitDepth;

        for(size_t i = 0; i < depthData.FullYRes(); i++)
        {
            uint16_t * row = imgDepth.ptr<uint16_t>(i);
            for(size_t j = 0; j < depthData.FullXRes(); j++)
            {
                uint16_t* pixel = &row[j];

                if (*pixel > max_dist) {
                    *pixel = max_dist;
                }
                else if (*pixel < min_dist && *pixel > 0) {
                    *pixel = min_dist;
                }
                else if (*pixel == 0)
                {
                    *pixel = max_dist;
                }
                if(reverse_colormap){
                    *pixel = 65535 - (*pixel-min_dist)*(int)(65535/(max_dist-min_dist));
                }
                else *pixel = (*pixel-min_dist)*(int)(65535/(max_dist-min_dist));
                pixel++;
            }
        }

        // Convert 16bit to 8bit greyscale
        imgDepth.convertTo( img8bitDepth, CV_8UC1, 1.0 / 257.0);         

        // Apply color map to 8bit frame
        Mat rgb(60, 80, CV_8UC3);
        applyColorMap(img8bitDepth, rgb, COLORMAP_JET);
        cv::resize(rgb, rgb, cv::Size(640, 480), CV_INTER_LINEAR);
        namedWindow( "Depth View", CV_WINDOW_NORMAL);
        imshow( "Depth View", rgb);

    }
    mContext.StopGeneratingAll();
    mContext.Release();
    return 0;
}
