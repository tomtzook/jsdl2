package sdl2.events;

public class JAxisMotionEvent extends Event {

    private final int mJoystickId;
    private final int mAxis;
    private final int mValue;

    public JAxisMotionEvent(int joystickId, int axis, int value) {
        super(EventType.JOY_AXIS_MOTION);
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
