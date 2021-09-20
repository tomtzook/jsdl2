package sdl2.events;

public enum EventType {
    /* Joystick events */
    JOYAXISMOTION(0x600),
    JOYBALLMOTION(0x601),
    JOYHATMOTION(0x602),
    JOYBUTTONDOWN(0x603),
    JOYBUTTONUP(0x604),
    JOYDEVICEADDED(0x605),
    JOYDEVICEREMOVED(0x606),
    /* Game controller events */
    CONTROLLERAXISMOTION(0x650),
    CONTROLLERBUTTONDOWN(0x651),
    CONTROLLERBUTTONUP(0x652),
    CONTROLLERDEVICEADDED(0x653),
    CONTROLLERDEVICEREMOVED(0x654),
    CONTROLLERDEVICEREMAPPED(0x655)
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
