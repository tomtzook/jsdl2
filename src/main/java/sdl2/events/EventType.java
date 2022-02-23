package sdl2.events;

public enum EventType {
    /* Joystick events */
    /**
     * {@link JAxisMotionEvent}
     */
    JOY_AXIS_MOTION,
    /**
     * {@link JBallMotionEvent}
     */
    JOY_BALL_MOTION,
    /**
     * {@link JHatMotionEvent}
     */
    JOY_HAT_MOTION,
    /**
     * {@link JButtonChangeEvent}
     */
    JOY_BUTTON_DOWN,
    /**
     * {@link JButtonChangeEvent}
     */
    JOY_BUTTON_UP,
    /**
     * {@link JDeviceConnectionEvent}
     */
    JOY_DEVICE_ADDED,
    /**
     * {@link JDeviceConnectionEvent}
     */
    JOY_DEVICE_REMOVED,
    /* GameController events */
    /**
     * {@link CAxisMotionEvent}
     */
    CONTROLLER_AXIS_MOTION,
    /**
     * {@link CButtonChangeEvent}
     */
    CONTROLLER_BUTTON_DOWN,
    /**
     * {@link CButtonChangeEvent}
     */
    CONTROLLER_BUTTON_UP,
    /**
     * {@link CDeviceConnectionEvent}
     */
    CONTROLLER_DEVICE_ADDED,
    /**
     * {@link CDeviceConnectionEvent}
     */
    CONTROLLER_DEVICE_REMOVED
    ;
}
