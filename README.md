# jsdl2

Java bindings for SDL2

## Examples

Initializing SDL:
```java
if (SDL.init(SDL.INIT_JOYSTICK) < 0) {
    // error
    System.err.printf("SDL.init error: %s\n", SDL.getError());
    System.exit(1);    
}

// use SDL

SDL.quit();
```

Handling Events:
```java
Event event = SDLEvents.waitEventTimeout(5000);
if (event == null) {
    // timeout
    return;
}

switch (event.getType()){
    case JOY_AXIS_MOTION:
        JAxisMotionEvent axisMotionEvent = (JAxisMotionEvent)event;
        // do something with the information
    break;
    // handle other event types
    // ... 
}
```

Using the Joystick subsystem:
```java
long ptr = SDLJoystick.open(0);
if (ptr == 0) {
    System.err.printf("Error opening device: %s\n", SDL.getError());
    return;
}

System.out.printf("Joystick %s: axes=%d\n",
        SDLJoystick.getName(ptr),
        SDLJoystick.getNumAxes(ptr));

for (int i = 0; i < SDLJoystick.getNumAxes(ptr); i++) {
    int axis = SDLJoystick.getAxis(ptr, i);
    System.out.printf("\tAxis %d: %d\n", i, axis);
}

SDLJoystick.close(ptr);
```
