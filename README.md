An example for the [Flow Engine](http://github.com/massile/FlowEngine)
======================================================================

### Graphics:

First, all the assets are loaded in the constructor of the [World](World.h) class:
 - A vertex and fragment shader
 - A rock mesh
 - A texture map that includes the diffuse map, specular map and normal map of the rocks texture
 
This class shall extends the IWorld interface provided by `FlowEngine`.

All these assets are recorded in the base application through the `record` method of the [AppProvider](AppProvider.h) class.

The AppProvider handles all the states of the application.
It extends the IProvider interface which initializes the application that way:
    - it takes a pointer to a window instance in the constructor
    - the `record` method should init all the necessary locators of the application; there are 3 locators:
        - Environment
        - UI
        - Input
        
Each of these locators have a `provide` method that asks for some services.
The `Environment` locator requires an `IWorld` and a `Graphics` service:
    - the `IWorld` service loads all the resources of the app
    - the `Graphics` service renders objects to the screen using `the render method`.
    
UI and Input locators are initialised with default services in the IProvider class.

### Components:

Once the provider is initialised, it can register Objects.
An `Object` is either a light, a camera or a point in 3d space.

You can tie 4 different kinds of components to an `Object`:
    - an InputComponent which shall take care of the mouse and keyboard input 
    - a PhysicsComponent which shall take care of the object physics
    - a ShaderComponent which shall take care of updating the shader uniforms
    - a GraphicsComponent which shall take care of rendering the Mesh that represents the `Object`

#### Camera input ([Source file](CameraInputComponent.h)):

Move the mouse to look around.
Use W, A, S, D to translate the camera.

#### Light input ([Source file](LightInputComponent.h)):

Use the arrow keys to move the light