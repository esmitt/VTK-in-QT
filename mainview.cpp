#include "mainview.h"
#include "ui_mainview.h"
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkSmartPointer.h>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    // This creates a polygonal cylinder model with eight circumferential facets
    // (i.e, in practice an octagonal prism).
    vtkSmartPointer<vtkCylinderSource> cylinder =
      vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetResolution(8);

    // The mapper is responsible for pushing the geometry into the graphics library.
    // It may also do color mapping, if scalars or other attributes are defined.
    vtkSmartPointer<vtkPolyDataMapper> cylinderMapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

    // The actor is a grouping mechanism: besides the geometry (mapper), it
    // also has a property, transformation matrix, and/or texture map.
    // Here we set its color and rotate it around the X and Y axes.
    vtkSmartPointer<vtkActor> cylinderActor =
      vtkSmartPointer<vtkActor>::New();
    cylinderActor->SetMapper(cylinderMapper);
    cylinderActor->GetProperty()->SetColor(1.0000, 0.3882, 0.2784);
    cylinderActor->RotateX(30.0);
    cylinderActor->RotateY(-45.0);

    // The renderer generates the image
    // which is then displayed on the render window.
    // It can be thought of as a scene to which the actor is added
    vtkSmartPointer<vtkRenderer> renderer =
      vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(cylinderActor);
    renderer->SetBackground(0.1, 0.2, 0.4);
    // Zoom in a little by accessing the camera and invoking its "Zoom" method.
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Zoom(1.5);

    // The render window is the actual GUI window
    // that appears on the computer screen
    vtkSmartPointer<vtkRenderWindow> renderWindow =
      vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->SetSize(200, 200);
    
    // These lines are important:
    // The actual render windows comes from the QVTK widget
    // The Renderer object should be passed to the QVTK widget (actors to be add for example)
    renderWindow = ui->qvtkWidget->GetRenderWindow();
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

MainView::~MainView()
{
    delete ui;
}
