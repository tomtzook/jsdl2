package sdl2.events;

public class CAxisMotionEvent extends Event {

    private final int mJoystickId;
    private final int mAxis;
    private final int mValue;

    public CAxisMotionEvent(int joystickId, int axis, int value) {
        super(EventType.CONTROLLER_AXIS_MOTION);
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
