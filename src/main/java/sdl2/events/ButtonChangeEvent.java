package sdl2.events;

public class ButtonChangeEvent extends Event {

    private final int mJoystickId;
    private final int mButton;
    private final int mState;

    public ButtonChangeEvent(int type, int joystickId, int button, int state) {
        super(type);
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

    public int getState() {
        return mState;
    }
}
