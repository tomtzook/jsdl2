package sdl2.events;

public class CButtonChangeEvent extends Event {

    private final int mJoystickId;
    private final int mButton;
    private final boolean mState;

    public CButtonChangeEvent(int joystickId, int button, boolean state) {
        super(state ? EventType.CONTROLLER_BUTTON_DOWN : EventType.CONTROLLER_BUTTON_UP);
        mJoystickId = joystickId;
        mButton = button;
        mState = state;
    }

    public int getJoystickId() {
        return mJoystickId;
    }

    public int getButton() {
        return mButton;
    }

    public boolean getState() {
        return mState;
    }
}
