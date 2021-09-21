# jsdl2

Java bindings for SDL2

## Examples

Initializing SDL:
```java
SDL.init(SDL.INIT_JOYSTICK)
try {
    // use SDL
} finally {
    SDL.quit();    
}
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

System.out.printf("Joystick %s: axes=%d\n",
        SDLJoystick.getName(ptr),
        SDLJoystick.getNumAxes(ptr));

for (int i = 0; i < SDLJoystick.getNumAxes(ptr); i++) {
    int axis = SDLJoystick.getAxis(ptr, i);
    System.out.printf("\tAxis %d: %d\n", i, axis);
}

SDLJoystick.close(ptr);
```
