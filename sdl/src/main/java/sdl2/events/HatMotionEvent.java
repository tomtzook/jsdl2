package sdl2.events;

public class HatMotionEvent extends Event {

    private final int mJoystickId;
    private final int mHat;
    private final int mValue;

    public HatMotionEvent(int type, int joystickId, int hat, int value) {
        super(type);
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
