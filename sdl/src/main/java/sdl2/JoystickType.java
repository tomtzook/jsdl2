package sdl2;

public enum JoystickType {
    UNKNOWN(0),
    GAME_CONTROLLER(1),
    WHEEL(2),
    ARCADE_STICK(3),
    FLIGHT_STICK(4),
    DANCE_PAD(5),
    GUITAR(6),
    DRUM_KIT(7),
    ARCADE_PAD(8),
    THROTTLE(9);

    private final int mValue;

    JoystickType(int value) {
        mValue = value;
    }

    public static JoystickType fromRaw(int value) {
        for (JoystickType type : values()) {
            if (type.mValue == value) {
                return type;
            }
        }

        throw new EnumConstantNotPresentException(JoystickType.class, String.valueOf(value));
    }
}
