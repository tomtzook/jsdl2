package sdl2.events;

public class JButtonChangeEvent extends Event {

    private final int mJoystickId;
    private final int mButton;
    private final boolean mState;

    public JButtonChangeEvent(int type, int joystickId, int button, boolean state) {
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

    public boolean getState() {
        return mState;
    }
}
