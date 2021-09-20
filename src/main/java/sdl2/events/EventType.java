package sdl2.events;

public enum EventType {
    /* Joystick events */
    JOY_AXIS_MOTION(0x600),
    JOY_BALL_MOTION(0x601),
    JOY_HAT_MOTION(0x602),
    JOY_BUTTON_DOWN(0x603),
    JOY_BUTTON_UP(0x604),
    JOY_DEVICE_ADDED(0x605),
    JOY_DEVICE_REMOVED(0x606)
    ;
    
    private final int mValue;

    EventType(int value) {
        mValue = value;
    }

    public static EventType fromRawValue(int value) {
        for (EventType type : values()) {
            if (type.mValue == value) {
                return type;
            }
        }

        throw new EnumConstantNotPresentException(EventType.class, String.valueOf(value));
    }
}
