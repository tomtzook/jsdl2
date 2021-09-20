package sdl2.events;

public class AxisMotionEvent extends Event {

    private final int mJoystickId;
    private final int mAxis;
    private final int mValue;

    public AxisMotionEvent(int type, int joystickId, int axis, int value) {
        super(type);
        mJoystickId = joystickId;
        mAxis = axis;
        mValue = value;
    }

    public int getJoystickId() {
        return mJoystickId;
    }

    public int getAxis() {
        return mAxis;
    }

    public int getValue() {
        return mValue;
    }
}
