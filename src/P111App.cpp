#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class P111App : public AppNative {
  public:
	void prepareSettings(Settings *settings);
	void setup();
	void mouseDown(MouseEvent event);
	void mouseMove(MouseEvent event);
	void update();
	void draw();
    
    Vec2i mMouseLoc;
    int stpX;
    int stpY;
};

void P111App::prepareSettings( Settings *settings ){
	settings->setWindowSize( 800, 400 );
	settings->setFrameRate(60.0f);
}

void P111App::setup()
{
}

void P111App::mouseDown( MouseEvent event )
{
}

void P111App::mouseMove(MouseEvent event) {
    mMouseLoc = event.getPos();
    
	gl::clear(Color(0, 0, 0));
    
    int width = getWindowWidth();
    int height = getWindowHeight();
    
    stpX = mMouseLoc.x + 2;
    stpY = mMouseLoc.y + 2;
    
    if (stpX < 2) stpX = 2;
    if (stpY < 2) stpY = 2;
    
     for (int gridY = 0; gridY < height; gridY += stpY) {
        for (int gridX = 0; gridX < width; gridX += stpX) {
            gl::color(Color(CM_HSV, float(gridX)/float(width), float(height - gridY)/float(height), 1.0f));
            
            Rectf rect(gridX, gridY, gridX+stpX, gridY+stpY);
            gl::drawSolidRect(rect);
            
            //console() << rect << std::endl;
        }
    }
}

void P111App::update()
{
}

void P111App::draw()
{
}

CINDER_APP_NATIVE( P111App, RendererGl )
