package sdl2;

public class PowerInfo {

    private final PowerState mState;
    private final int mSecondsLeft;
    private final int mPercentage;

    public PowerInfo(PowerState state, int secondsLeft, int percentage) {
        mState = state;
        mSecondsLeft = secondsLeft;
        mPercentage = percentage;
    }

    public PowerState getState() {
        return mState;
    }

    public int getSecondsLeft() {
        return mSecondsLeft;
    }

    public int getPercentage() {
        return mPercentage;
    }
}
