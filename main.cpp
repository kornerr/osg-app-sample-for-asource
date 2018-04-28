
//#include <osg/GraphicsContext>
#include <osgViewer/Viewer>

int main(int argc, char *argv[])
{
    osgViewer::Viewer viewer;

    // Specify window size.
    int width = 800;
    int height = 600;

    // Create GC.
    auto traits = new osg::GraphicsContext::Traits;
    traits->x = 0;
    traits->y = 0;
    traits->width = width;
    traits->height = height;
    traits->windowDecoration = true;
    auto gc = osg::GraphicsContext::createGraphicsContext(traits);

    // Set GC.
    auto camera = viewer.getCamera();
    camera->setGraphicsContext(gc);
    camera->setViewport(new osg::Viewport(0, 0, width, height));
    camera->setClearMask(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    float aspect = static_cast<float>(width) / static_cast<float>(height);
    camera->setProjectionMatrixAsPerspective(45, aspect, 1, 1000);

    // Start application.
    viewer.run();

    return 0;
}

