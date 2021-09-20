package sdl2.events;

public class JHatMotionEvent extends Event {

    private final int mJoystickId;
    private final int mHat;
    private final int mValue;

    public JHatMotionEvent(int joystickId, int hat, int value) {
        super(EventType.JOY_HAT_MOTION);
        mJoystickId = joystickId;
        mHat = hat;
        mValue = value;
    }

    public int getJoystickId() {
        return mJoystickId;
    }

    public int getHat() {
        return mHat;
    }

    public int getValue() {
        return mValue;
    }
}
